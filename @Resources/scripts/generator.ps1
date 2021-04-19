function Update {

}

# Implemented types
$variableTypes = @("String", "Integer", "Color", "Toggle", "Info")
$defaultVariableType = @("String")
$categoryTypes = @("Default", "About")
$listTypes = @("Default", "About", "Topic")

# Variables from Rainmeter
$settingsFilePath = "$($RmAPI.VariableStr('s_SettingsFile'))"

# Generator directories
$resourcesDir = "$($RmAPI.VariableStr('@'))"
$includeDir = "$($resourcesDir)includes\"
$addonsDir = "$($resourcesDir)addons\"
$templatesDir = "$($resourcesDir)templates\"
$variableTemplatesDir = "$($templatesDir)variable\"
$categoryTemplatesDir = "$($templatesDir)category\"
$listTemplatesDir = "$($templatesDir)list\"

# Generated directories
$generatedSkinDir = "$($RmAPI.VariableStr('ROOTCONFIGPATH'))settings\"
$generatedCategoriesDir = "$($generatedSkinDir)categories\"
$generatedIncludeDir = "$($generatedSkinDir)includes\"
$generatedAddonsDir = "$($generatedSkinDir)addons"

# Generated files
$generatedSkinFile = "$($generatedSkinDir)settings.ini"

# Testfile
$testfile = "$($resourcesDir)test.inc"

function Construct {
    # Reset directories, copy files etc.
    Prepare-Directories

    # Read settings file
    $settingsFileContent = Get-Content $settingsFilePath -Raw

    # Filter settings file into staggered array
    $settings = Settings-Array -String $settingsFileContent

    # Variable to hold generated .ini
    # Get rainmeter section from template
    $ini = Get-Content -Path "$($templatesDir)Rainmeter.inc" -Raw
    $rainmeterTemplateProperties = @{
        "SettingsFile" = $settingsFilePath
    }
    $ini = Filter-Template -Template $ini -Properties $rainmeterTemplateProperties

    # Construct categories
    $i = 0
    foreach ($category in $settings) {
        Category-Ini -category $category -i $i
        $i++
    }

    Category-List -Settings $settings

    $ini > $generatedSkinFile
}

function Settings-Array {
    param (
        [Parameter(Mandatory=$true)]
        [Alias("String")]
        $settingsFileContent
    )

    # Regex patterns
    $categoryPattern = '(?s-m)(;@.*?)(?=;@|$)'

    # Fallback pattern for getting variables from unformatted files
    $unformattedVariablePattern = '(?sm)(?<=[^;])^([^;]+?)$'

    # Declare $settings as an empty array to make sure that $settings is an array
    $settings = @()

    # Handle unformatted variable files
    if($settingsFileContent -notmatch $categoryPattern) {
        $RmAPI.Log("Fuck you it's not formatted right")
        return 
    }

    # Get all $categoryPattern matches from $settingsFileContent to %_ with Foreach
    Select-String -Pattern $categoryPattern -input $settingsFileContent -AllMatches | Foreach {
        # Filter each matched $category
        foreach ($category in $_.Matches) {
            $c = Pipe-Category -String $category
            # Add the filtered category hashtable to the $settings array 
            $settings += , $c
        }
    }

    return $settings

}

function Pipe-Variable {

    param(
        [Parameter(Mandatory=$true)]
        $String,
        [Parameter(Mandatory=$true)]
        $Category
    )

    $Patterns = @{
        "UnfilteredProperties" = '(?s-m)(;\?.*?)(?=$|;@|;\?|$|\n)'

        "Type" = '(?<=;\?)(.*?)(?=\||\n|$)'
        "UnfilteredProperty" = '(?s-m)(?<=\|)(.*?)(?=\||\n|$)'
        "PropertyKey" = '^\s*(.*?)\s|$|\n'
        "PropertyValue" = '(?s-m)\s?.*?\s(.*?)(?=$|\n|\|)'

        "KeyValue" = '(?m-s)^(?!;)(.*?)(?=$|\n)'
        "Key" = '^(.*?)(?==)'
        "Value" = '(?<==)(.*?)(?=\n|$)'
    }

    # Get unfiltered data
    $Variable = Filter-Hashtable -String $String -Properties @{"KeyValue" = $Patterns.KeyValue; "UnfilteredProperties" = $Patterns.UnfilteredProperties}

    # Get the variable properties

    # Make the Properties hashtable
    $Variable.Properties = @{}

    # Get type
    if("$($Variable.UnfilteredProperties)" -match "$($Patterns.Type)") {
        $Variable.Properties.Type = Remove-Whitespace -String $Matches[1]
        # Change type to String if empty
        if($Variable.Properties.Type -eq "") {
            $Variable.Properties.Type = "String"
            # $RmAPI.Log("Changed $($Variable.UnfilteredProperties) type to String")
        }
    }

    # Match every | Key Value | pair from the property line
    Select-String -Pattern $Patterns.UnfilteredProperty -input $Variable.UnfilteredProperties -AllMatches | Foreach {
        # Filter each matched $category
        foreach ($UnfilteredProperty in $_.Matches) {
            $key, $value = ""
            if($UnfilteredProperty -match $Patterns.PropertyValue) {
                $value = $Matches[1]
                # $RmAPI.Log("Got variable value $value from $($UnfilteredProperty)")
            }
            # Only add the property to the hashtable if it has a key.
            if($UnfilteredProperty -match $Patterns.PropertyKey) {
                $key = Remove-Whitespace -String $Matches[1]
                # $RmAPI.Log("Got variable key $key from $($UnfilteredProperty)")
                $Variable.Properties.Add("$key", "$value")
            }
        }
    }

    # Checkpoint 1
    # $RmAPI.Log("$($Variable.Properties.Name) properties: $($Variable.Properties.Keys)")
    # $RmAPI.Log("This variable is: $($Variable.Properties.Name) from $Category")

    # Get the key and value from the unformatted line
    $Variable.KeyValue = Filter-Hashtable -String $Variable.KeyValue -Properties @{"Key" = $Patterns.Key; "Value" = $Patterns.Value}
    # Add Key and Value from KeyValue to the main object
    $Variable.KeyValue.GetEnumerator() | ForEach-Object {
        $Variable.Add("$($_.Key)", "$($_.Value)")
    }

    return $Variable

}

function Pipe-Category {

    param(
        [Parameter(Mandatory=$true)]
        $String
    )

    $Patterns = @{
        "UnfilteredProperties" = '(?s-m)(;@.*?)(?=$|;@|;\?|$|\n)'
        "UnfilteredVariables" = '(?s-m)(;\?.*)'

        "Type" = '(?<=;\@)(.*?)(?=\||\n|$)'
        "UnfilteredProperty" = '(?s-m)(?<=\|)(.*?)(?=\||\n|$)'
        "PropertyKey" = '^\s*(.*?)\s|$|\n'
        "PropertyValue" = '(?s-m)\s?.*?\s(.*?)(?=$|\n|\|)'

        "UnfilteredVariable" = '(?s-m)(;\?.*?)(?=;\?|;@|$)'
    }

    # Get unfiltered data
    $Category = Filter-Hashtable -String $String -Properties @{"UnfilteredProperties" = $Patterns.UnfilteredProperties; "UnfilteredVariables" = $Patterns.UnfilteredVariables}

    # Get the category properties

    # Make the Properties hashtable
    $Category.Properties = @{}

    # Get type
    if("$($Category.UnfilteredProperties)" -match "$($Patterns.Type)") {
        $Category.Properties.Type = Remove-Whitespace -String $Matches[1]
        # Change type to Default if empty
        if($Category.Properties.Type -eq "") {
            $Category.Properties.Type = "Default"
            # $RmAPI.Log("Changed $($Category.UnfilteredProperties) type to Default")
        }
    }
    
    # Match every | Key Value | pair from the property line
    Select-String -Pattern $Patterns.UnfilteredProperty -input $Category.UnfilteredProperties -AllMatches | Foreach {
        # Filter each matched $category
        foreach ($UnfilteredProperty in $_.Matches) {
            $key, $value = ""
            if($UnfilteredProperty -match $Patterns.PropertyValue) {
                $value = $Matches[1]
            }
            # Only add the property to the hashtable if it has a key.
            # This is a very smart move.
            if($UnfilteredProperty -match $Patterns.PropertyKey) {
                $key = Remove-Whitespace -String $Matches[1]
                $Category.Properties.Add("$key", "$value")
            }
        }
    }

    # Checkpoint 1
    # $RmAPI.Log("Got category properties: $($Category.Properties.Keys)")
    
    # Make the Variables array
    $Category.Add("Variables", @())
    # Get all UnfilteredVariable matches from UnfilteredVariables
    Select-String -Pattern $Patterns.UnfilteredVariable -input $Category.UnfilteredVariables -AllMatches | Foreach {
        # Filter each matched $category
        foreach ($UnfilteredVariable in $_.Matches) {
            # Filter each Variable
            $v = Pipe-Variable -String $UnfilteredVariable -Category $Category.Properties.Name
            $Category.Variables += , $v
        }
    }
    
    # Checkpoint 2
    $RmAPI.Log("Generated $($Category.Variables.Count) variables for '$($Category.Properties.Name)'")

    return $Category

}

function Category-Ini {
    param (
        [Parameter(Mandatory=$true)]
        $Category,
        [Parameter(Mandatory=$true)]
        $i
    )

    # path to current category.inc
    $file = "$($generatedCategoriesDir)$($i).inc"

    # Properties to replace in templates
    $Properties = @{
        "Index" = $i
        "Name" = $Category.Properties.Name
        "Icon" = "$($Category.Properties.Icon)"
        "Container" = "RightPanel"
        "Description" = $Category.Properties.Description
    }

    # First Item template
    $template = Get-Content -Path "$($templatesDir)FirstItem.inc" -Raw
    $ini = Filter-Template -Template $template -Properties @{"Container" = "RightPanel"}

    # If category type is not implemented, make it Default
    if($categoryTypes -NotContains $Category.Properties.Type) {
        $type = "Default"
    } else {
        $type = $Category.Properties.Type
    }

    # Build category from template
    $template = Get-Content -Path "$($categoryTemplatesDir)$($type).inc" -Raw
    $ini += Filter-Template -Template $template -Properties $Properties

    $j = 0
    foreach ($var in $Category.Variables) {
        $ini += Variable-Ini -Variable $var -Index $j
        $j++
    }

    $template = Get-Content -Path "$($templatesDir)LastItem.inc" -Raw
    $ini += Filter-Template -Template $template -Properties @{"Container" = "RightPanel"}

    $ini > $file

}

function Variable-Ini {
    param (
        [Parameter(Mandatory=$true)]
        $Variable,
        [Parameter(Mandatory=$true)]
        $Index
    )

    # Properties used internally for skin generation, not user submitted
    $internalVariableProperties = @{
        "Index" = $Index
        "Container" = "RightPanel"
        "SettingsFile" = $settingsFilePath
    }

    # Get template for type
    $ini = Get-Content -Path "$($variableTemplatesDir)$($Variable.Properties.Type).inc" -Raw
    # Filter template
    $ini = Filter-Template -Template $ini -Properties $internalVariableProperties
    $ini = Filter-Template -Template $ini -Properties $Variable.Properties
    $ini = Filter-Template -Template $ini -Properties $Variable
    $ini = Remove-UnformattedValues -Template $ini

    return $ini

}

function Category-List {
    param(
        [Parameter(Mandatory=$true)]
        $Settings
    )

    $RmAPI.Log("Building category list.")

    $ini = Get-Content -Path "$($templatesDir)FirstItem.inc" -Raw
    $ini = Filter-Template -Template $ini -Properties @{"Container" = "LeftPanel"}

    $i = 0
    foreach ($category in $Settings) {
        $externalProperties = @{
            "Index" = $i
            "Container" = "LeftPanel"
        }

        # If category type is not implemented, make it Default
        if($listTypes -NotContains $category.Properties.Type) {
            $type = "Default"
        } else {
            $type = $category.Properties.Type
        }

        $template = Get-Content -Path "$($listTemplatesDir)$($type).inc" -Raw
        $template = Filter-Template -Template $template -Properties $externalProperties
        $template = Filter-Template -Template $template -Properties $category.Properties
        $ini += Remove-UnformattedValues -Template $template
        $i++
    }

    $last = Get-Content -Path "$($templatesDir)LastItem.inc" -Raw
    $ini += Filter-Template -Template $last -Properties @{"Container" = "LeftPanel"}

    # credit last, outside of the scrollable item list
    $template = Get-Content -Path "$($listTemplatesDir)Credit.inc" -Raw
    $ini += $template

    $ini > "$($generatedCategoriesDir)CategoryList.inc"

}

function Filter-Hashtable {
    param (
        [Parameter(Mandatory=$true)]
        [string]
        $String,
        [Parameter(Mandatory=$true)]
        [System.Collections.Hashtable]
        $Properties
    )

    $hash = @{}
    $Properties.GetEnumerator() | ForEach-Object {
        if("$($String)" -match "$($_.Value)") {
            # Save the matched string before
            $s = $Matches[1]
            # checking if the value is supposed to be unfiltered
            if("$($_.Key)" -notmatch "UnfilteredVariables") {
                $s = Remove-Newline -String $s
            }
        }
        $hash.Add("$($_.Key)",$s)
    }

    return $hash

}

function Filter-Template {
    param(
        [Parameter(Mandatory=$true)]
        [string]
        $Template,
        [Parameter(Mandatory=$true)]
        [System.Collections.Hashtable]
        $Properties
    )

    # Iterate over the template for each property of the variable
    $Properties.GetEnumerator() | ForEach-Object {
        $Template = $Template.replace("{$($_.Key)}","$($_.Value)")
    }

    return $Template

}

function Remove-UnformattedValues {
    param(
        [Parameter(Mandatory=$true)]
        [string]
        $Template
    )

    $Template = $Template -replace "\{.*?\}",""

    return $Template

}

function Remove-Newline {
    param (
        [Parameter()]
        [string]
        $String
    )

    $String = $String -replace "`t|`n|`r",""

    return $String

}

function Remove-Whitespace {
    param (
        [Parameter()]
        $String
    )

    $String = $String -replace "`t|`n|`r|\s+",""

    return $String
}

function Prepare-Directories {
    # Create directories
    New-Item -Path $generatedSkinDir -ItemType "directory" -Name "categories"
    New-Item -Path $generatedSkinDir -ItemType "directory" -Name "includes"
    New-Item -Path $generatedSkinDir -ItemType "directory" -Name "addons"
    # Remove files in generated directories
    Get-ChildItem -Path "$generatedCategoriesDir*" -Include *.inc | Remove-Item
    Get-ChildItem -Path "$generatedIncludeDir*" -Include *.inc | Remove-Item
    # Copy Includes to generated skin
    Copy-Item -Path "$includeDir*" -Include "*.inc" -Destination $generatedIncludeDir -Recurse
    # Copy Addons to generated skin
    Copy-Item -Path "$addonsDir*" -Include "*.exe" -Destination $generatedAddonsDir -Recurse
}
