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

    # old patterns
    # $variablePattern = '(?s-m)(;;.*?)\n(?![;$]).*?[\n|$]'
    # "Type" = '(?<=;;Type=)(.*?)(?=\n)'

    # Regex patterns
    $categoryPattern = '(?s-m)(;@.*?)(?=;@|$)'
    $variablePattern = '(?s-m)(;\?.*?)\n(?!;|$).*?[\n|$]'
    $variablePatterns = @{
        "Type" = '(?<=;\?)(.*?)(?=\n)'
        "Name" = '(?<=;;Name=)(.*?)(?=\n)'
        "Description" = '(?<=;;Description=)(.*?)(?=\n)'
        "DefaultValue" = '(?<=;;DefaultValue=)(.*?)(?=\n)'
        "Hidden" = '(?<=;;Hidden=)(.*?)(?=\n)'
        "RealName" = '(?m-s)^(?!;)(.*?)(?==)'
        "CurrentValue" = '(?m-s)^(?!;).*=(.*?)(?=\n|$)'
    }

    # Patterns to filter out any declared variables and 
    # their properties from the category property search.
    # Without this extra step, a category could end up with
    # its first variables description etc.
    $categorySplitPatterns = @{
        "Properties" = '(?s-m)(;@.*?)(?=$|;@|;\?|$[^;])'
        "UnfilteredVariables" = '(?s-m)(;\?.*)'
    }

    $categoryPropertyPatterns = @{
        "Type" = '(?s-m)(?<=;@)(.*?)(?=\n|;;|$)'
        "Name" = '(?<=;;Name=)(.*?)(?=\n|;;|$)'
        "Icon" = '(?<=;;Icon=)(.*?)(?=\n|;;|$)'
        "Description" = '(?<=;;Description=)(.*?)(?=\n|;;|$)'
    }

    # Fallback pattern for getting variables from unformatted files
    $unformattedVariablePattern = '(?sm)(?<=[^;])^([^;]+?)$'

    # Declare $settings as an empty array to make sure that $settings is an array
    $settings = @()

    # Handle unformatted variable files
    if($settingsFileContent -notmatch $categoryPattern) {
        $RmAPI.LogWarning("Filtering unformatted variables file")
        $c = @{"Name" = "settings"; "Variables" = @()}
        Select-String -Pattern $unformattedVariablePattern -input $settingsFileContent -AllMatches | Foreach {
            foreach($match in $_.Matches) {
                $var = Filter-Hashtable -Properties $variablePatterns -String $match
                # check if processing empty $match
                if($var.RealName) {
                    $RmAPI.Log("Matched unformatted variable: $($var.RealName)")
                    $var["Name"] = $var["RealName"]
                    $var["Description"] = " "
                    $c.Variables += $var
                }
            }
        }
        $settings += $c
        return $settings
    }

    # Get all $categoryPattern matches from $settingsFileContent to %_ with Foreach
    Select-String -Pattern $categoryPattern -input $settingsFileContent -AllMatches | Foreach {

        # Iterate over each matched $category in $_.Matches
        foreach ($category in $_.Matches) {

            # Split category string into 'category properties' and 'unfiltered variables' strings
            $c = Filter-Hashtable -String $category -Properties $categorySplitPatterns
            # Filter properties string into a properties hashtable
            $c["Properties"] = Filter-Hashtable -String $c.Properties -Properties $categoryPropertyPatterns

            # Debug log
            $RmAPI.Log("Building category: $($c.Properties.Name).")

            # Create empty Variables array
            $c.Add("Variables", @())

            # Get all $variablePattern matches from $c.UnfilteredVariables to %_ with Foreach
            Select-String -Pattern $variablePattern -input $c.UnfilteredVariables -AllMatches | Foreach {
                # Debug log
                $RmAPI.Log("Filtering variables from: $($_.matches)")
                # Iterate over each matched $variable in $_.Matches
                foreach ($variable in $_.matches) {
                    # Filter $variable hashtables
                    $var = Filter-Hashtable -String $variable -Properties $variablePatterns

                    # Debug log
                    $RmAPI.Log("$($var.Name): $($var.keys)")

                    # Add the filtered variable hashtable to the $c.Variables array
                    $c.Variables += , $var
                }
            }

            # Add the filtered category hashtable to the $settings array 
            $settings += , $c

        }
    }

    return $settings

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

    if(($i -eq 0) -and ($Category.Properties.Type -match "About")) {
        $template = Get-Content -Path "$($variableTemplatesDir)Credit.inc" -Raw
        $ini += Filter-Template -Template $template -Properties @{"Container" = "RightPanel"}
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

    # Default to string variable
    if ($variableTypes -NotContains $Variable.Type) {
        $Variable["Type"] = $defaultVariableType
    }

    # Get template for type
    $ini = Get-Content -Path "$($variableTemplatesDir)$($Variable.Type).inc" -Raw
    # Filter template
    $ini = Filter-Template -Template $ini -Properties $internalVariableProperties
    $ini = Filter-Template -Template $ini -Properties $Variable

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
        $Properties = @{
            "Index" = $i
            "Icon" = "$($category.Properties.Icon)"
            "Category" = "$($category.Properties.Name)"
            "Container" = "LeftPanel"
        }

        # If category type is not implemented, make it Default
        if($listTypes -NotContains $category.Properties.Type) {
            $type = "Default"
        } else {
            $type = $category.Properties.Type
        }

        $template = Get-Content -Path "$($listTemplatesDir)$($type).inc" -Raw
        $ini += Filter-Template -Template $template -Properties $Properties
        $i++
    }

    $last = Get-Content -Path "$($templatesDir)LastItem.inc" -Raw
    $ini += Filter-Template -Template $last -Properties @{"Container" = "LeftPanel"}

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
            # Save the matched string
            $s = $Matches[1]
            if("$($_.Key)" -notmatch "UnfilteredVariables") {
                $s = Remove-Newline -String $s
            }
        } else {
            $s = " "
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

function Remove-Newline {
    param (
        [Parameter()]
        [string]
        $String
    )

    $String = $String -replace "`t|`n|`r",""

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
