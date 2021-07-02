function Update {

}

# Implemented types
$variableTypes = @("String", "Integer", "Color", "Toggle", "Info")
$defaultVariableType = @("String")
$categoryTypes = @("Default", "About")
$listTypes = @("Default", "About", "Topic")

# Variables from Rainmeter
$variableFilePath = "$($RmAPI.VariableStr('s_RawPath'))"
$dynamicVariableFile = "#SKINSPATH#$($RmAPI.VariableStr('s_DynamicVariableFile'))"
$dynamicThemeFile = "#ROOTCONFIGPATH#settings\includes\themes\$($RmAPI.VariableStr('s_SettingsTheme')).inc"
$dynamicInternalVariableFile = "#ROOTCONFIGPATH#settings\includes\Variables.inc"

# Generator directories
$resourcesDir = "$($RmAPI.VariableStr('@'))"
$includeDir = "$($resourcesDir)includes\"
$addonsDir = "$($resourcesDir)addons\"
$templatesDir = "$($resourcesDir)templates\"
$variableScriptsDir = "$($resourcesDir)templates\variables\"
$categoryScriptsDir = "$($resourcesDir)templates\categories\"
$listitemScriptsDir = "$($resourcesDir)templates\listitems\"
$variableTitleScript = "$($variableScriptsDir)s_Title.ps1"

# Generated directories
$generatedSkinDir = "$($RmAPI.VariableStr('ROOTCONFIGPATH'))settings\"
$generatedCategoriesDir = "$($generatedSkinDir)categories\"
$generatedIncludeDir = "$($generatedSkinDir)includes\"
$generatedAddonsDir = "$($generatedSkinDir)addons"

# Generated files
$generatedSkinFile = "$($generatedSkinDir)settings.ini"

# Injectors
$targetSkin = $RmAPI.VariableStr('s_Skin')
$injectPath = "$($RmAPI.VariableStr('SKINSPATH'))$($targetSkin)\"

# Testfile
$testfile = "$($resourcesDir)test.inc"

function Construct {
    # Reset directories, copy files etc.
    Prepare-Directories

    # Read settings file
    $settingsFileContent = Get-Content $variableFilePath -Raw

    # Filter settings file into staggered array
    $RmAPI.Log("Parsing settings file")

    # Regex patterns
    $categoryPattern = '(?s-m)(;@.*?)(?=;@|$)'

    # Handle unformatted variable files
    if($settingsFileContent -notmatch $categoryPattern) {}
    
    # Get all $categoryPattern matches from $settingsFileContent to %_ with Foreach
    $settings = @(
        Select-String -Pattern $categoryPattern -input $settingsFileContent -AllMatches | ForEach-Object {
        # Filter each matched $category
        foreach ($category in $_.Matches) {
            Pipe-Category -String $category
        }
    })

    # Testing
    $settings > $testfile

    # Variable to hold generated .ini
    # Get rainmeter section from template
    $ini = Get-Content -Path "$($templatesDir)Rainmeter.inc" -Raw
    $rainmeterTemplateProperties = @{
        "SettingsFile" = $dynamicVariableFile
        "ThemeFile" = $dynamicThemeFile
    }
    $ini = Filter-Template -Template $ini -Properties $rainmeterTemplateProperties
    $ini > $generatedSkinFile

    # Construct categories
    $settings | ForEach-Object { $i = 0 } {
        $RmAPI.Log("Building category $($i).inc")
        Category-Ini -category $_ -i $i
        $i++
    }

    $RmAPI.Log("Building category list")
    Category-List -Settings $settings

    Inject-Settings

}

function Pipe-Variable {

    param(
        [Parameter(Mandatory=$true)]
        $String
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

    # Get the key and value from the unformatted line
    $Variable.KeyValue = Filter-Hashtable -String $Variable.KeyValue -Properties @{"Key" = $Patterns.Key; "Value" = $Patterns.Value}
    # Add Key and Value from KeyValue to the main object
    $Variable.KeyValue.GetEnumerator() | ForEach-Object {
        $Variable.Add("$($_.Key)", "$($_.Value)")
    }
    
    # Make the Properties hashtable

    # Default the Name property to the Key
    $Variable.Properties = @{"Name" = $Variable.Key}

    # Filter type
    # Type is special since it's required
    if("$($Variable.UnfilteredProperties)" -match "$($Patterns.Type)") {
        $Variable.Type = Remove-Whitespace -String $Matches[1]
        # Default undeclared type to String without logging
        if($Variable.Type -eq "") {
            $Variable.Type = "String"
        }
        # Default typos to String
        if($variableTypes -NotContains $Variable.Type) {
            $RmAPI.LogError("Variable type '$($Variable.Type)' is not implemented, defaulting to String")
            $Variable.Type = "String"
        }
    }

    # Match every | Key Value | pair from the property line
    Select-String -Pattern $Patterns.UnfilteredProperty -input $Variable.UnfilteredProperties -AllMatches | ForEach-Object {
        # Filter each matched $category
        foreach ($UnfilteredProperty in $_.Matches) {
            $key, $value = ""
            if($UnfilteredProperty -match $Patterns.PropertyValue) {
                $value = $Matches[1]
            }
            # Only add the property to the hashtable if it has a key.
            if($UnfilteredProperty -match $Patterns.PropertyKey) {
                $key = Remove-Whitespace -String $Matches[1]
                #TODO: maybe add a check if props are overriding internal props like Index etc.
                $Variable["$key"] = "$value"
            }
        }
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

    # Filter type
    # Type is special since it's required
    if("$($Category.UnfilteredProperties)" -match "$($Patterns.Type)") {
        $Category.Properties.Type = Remove-Whitespace -String $Matches[1]
        # Default undeclared type to Default without logging
        if($Category.Properties.Type -eq "") {
            $Category.Properties.Type = "Default"
        }
        # Default typos to Default
        if($listTypes -NotContains $Category.Properties.Type) {
            $RmAPI.LogError("Category type '$($Category.Properties.Type)' is not implemented. Changed to Default")
            $Category.Properties.Type = "Default"
        }
    }
    
    # Match every | Key Value | pair from the property line
    Select-String -Pattern $Patterns.UnfilteredProperty -input $Category.UnfilteredProperties -AllMatches | ForEach-Object {
        # Filter each matched $category
        foreach ($UnfilteredProperty in $_.Matches) {
            $key, $value = ""
            if($UnfilteredProperty -match $Patterns.PropertyValue) {
                $value = $Matches[1]
            }
            # Only add the property to the hashtable if it has a key.
            if($UnfilteredProperty -match $Patterns.PropertyKey) {
                # $RmAPI.Log("Adding key: '$($Matches[1])'")
                $key = Remove-Whitespace -String $Matches[1]
                $Category.Add("$key", "$value")
            }
        }
    }

    # Checkpoint 1
    # $RmAPI.Log("Got category properties: $($Category.Properties.Keys)")
    
    # Make the Variables array
    $Category.Add("Variables", @())
    # Get all UnfilteredVariable matches from UnfilteredVariables
    Select-String -Pattern $Patterns.UnfilteredVariable -input $Category.UnfilteredVariables -AllMatches | ForEach-Object {
        # Filter each matched $category
        foreach ($UnfilteredVariable in $_.Matches) {
            # Filter each Variable
            $v = Pipe-Variable -String $UnfilteredVariable
            $Category.Variables += , $v
        }
    }
    
    # Checkpoint 2
    # $RmAPI.Log("Generated $($Category.Variables.Count) variables for '$($Category.Properties.Name)'")

    return $Category

}

function Category-Ini {
    param (
        [Parameter(Mandatory=$true)]
        $Category,
        [Parameter(Mandatory=$true)]
        $i
    )

    # If category type is not implemented, make it Default
    # TODO: check the list of implemented categories
    $Type = $Category.Type
    if($categoryTypes -NotContains $Type) {
        $Type = "Default"
    }

    # Set the Index
    $Category.Index = $i

    # First Item template
    $template = Get-Content -Path "$($templatesDir)FirstItem.inc" -Raw
    $ini = Filter-Template -Template $template -Properties @{"Container" = "Right"}
    
    # Call the appropriate Variable script
    $ini += &"$($categoryScriptsDir)$($Type).ps1" -Category $Category
    # Add space between variables, without newlines the section name would be appended to the last templates last option
    $ini += "`n`n"
    
    # Create variable inis
    $Category.Variables | ForEach-Object { $j = 0 } {
        $ini += Variable-Ini -Variable $_ -Index $j
        $j++
    }

    # Last Item template
    $template = Get-Content -Path "$($templatesDir)LastItem.inc" -Raw
    $ini += Filter-Template -Template $template -Properties @{"Container" = "Right"}

    # Write category
    $ini > "$($generatedCategoriesDir)$($i).inc"

}

function Variable-Ini {
    param (
        [Parameter(Mandatory=$true)]
        $Variable,
        [Parameter(Mandatory=$true)]
        $Index
    )

    $Variable["Index"] = $Index
    
    # Call the appropriate Variable script
    $ini = &"$($variableScriptsDir)$($Variable.Type).ps1" -Variable $Variable -SettingsFile $dynamicVariableFile
    # Add space between variables, without newlines the section name would be appended to the last templates last option
    $ini += "`n`n"
    
    return $ini

}

function Category-List {
    param(
        [Parameter(Mandatory=$true)]
        $Settings
    )

    # FirstItem template
    $ini = Get-Content -Path "$($templatesDir)FirstItem.inc" -Raw
    $ini = Filter-Template -Template $ini -Properties @{"Container" = "Left"}
    
    # Loop through the categories
    $Settings | ForEach-Object { $i = 0 } {
        # Set the Index number
        $_.Index = $i

        # Get the category type
        $type = $_.Type
        # If category type is not implemented, make it Default
        if($listTypes -NotContains $_.Type) { $type = "Default" }

        # Call the appropriate ListItem template script
        $ini += &"$($listitemScriptsDir)$($type).ps1" -Category $_ -InternalSettingsFile $dynamicInternalVariableFile
        $ini += "`n`n"
        $i++
    }

    # Add in the LastItem
    $last = Get-Content -Path "$($templatesDir)LastItem.inc" -Raw
    $ini += Filter-Template -Template $last -Properties @{"Container" = "Left"}

    # Credit icon last, outside of the scrollable item list
    $ini += &"$($listitemScriptsDir)Credit.ps1"

    # Write category list to file
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
    New-Item -Path $injectPath -ItemType "directory" -Name "settings"
    # Remove files in generated directories
    Get-ChildItem -Path "$generatedCategoriesDir*" -Include *.inc | Remove-Item
    Get-ChildItem -Path "$generatedIncludeDir*" -Include *.inc | Remove-Item
    # Remove settings injected earlier
    Get-ChildItem -Path "$($injectPath)settings\*" -Include @("*.inc","*.ini","RainRGB4RunCommand.exe") | Remove-Item
    # Copy Includes to generated skin
    Copy-Item -Path "$includeDir*" -Destination $generatedIncludeDir -Recurse
    # Copy Addons to generated skin
    Copy-Item -Path "$addonsDir*" -Include "*.exe" -Destination $generatedAddonsDir -Recurse
}

function Inject-Settings {
    # Inject generated settings
    Copy-Item -Path "$generatedSkinDir*" -Destination "$($injectPath)settings\" -Recurse
    
    $RmAPI.Log("Refreshing Rainmeter")
    $RmAPI.Bang('[!RefreshApp]')
    # $RmAPI.Bang('[!ActivateConfig]$($targetSkin)\settings\settings.ini')
    $RmAPI.Log("Loading generated settings skin")
    Start-Process "C:\Program Files\Rainmeter\Rainmeter.exe" -ArgumentList "!ActivateConfig", "$($targetSkin)\settings", "settings.ini"
}
