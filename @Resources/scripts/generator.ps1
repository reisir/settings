function Update {

}

# Implemented types
$variableTypes = @("String", "Integer", "Color", "Toggle", "Info", "RadioButton")
$defaultVariableTypes = @("String", "Integer", "Color", "Toggle", "Info")
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
    $settings = Settings-Array -String $settingsFileContent

    # Variable to hold generated .ini
    # Get rainmeter section from template
    $ini = Get-Content -Path "$($templatesDir)Rainmeter.inc" -Raw
    $rainmeterTemplateProperties = @{
        "SettingsFile" = $dynamicVariableFile
        "ThemeFile" = $dynamicThemeFile
    }
    $ini = Filter-Template -Template $ini -Properties $rainmeterTemplateProperties

    # Construct categories
    $i = 0
    foreach ($category in $settings) {
        $RmAPI.Log("Building category $($i).inc")
        Category-Ini -category $category -i $i
        $i++
    }

    $RmAPI.Log("Building category list")
    Category-List -Settings $settings

    $ini > $generatedSkinFile

    Inject-Settings

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
        return @(@{
            "Properties" = @{
                "Type" = "Default"
                "Name" = "File format error"
                "Description" = "Please add at least one (1) category"
                "Icon" = "[\xE783]"
            }
            "Variables" = @{
                "Properties" = @{
                    "Type" = "Info"
                    "Name" = "Refer to the RainDoc syntax wiki"
                    "Link" = "1"
                }
                "Key" = "RainDoc syntax"
                "Value" = "https://github.com/sceleri/settings/wiki"
            }
        })
    }

    # Get all $categoryPattern matches from $settingsFileContent to %_ with Foreach
    Select-String -Pattern $categoryPattern -input $settingsFileContent -AllMatches | Foreach {
        # Filter each matched $category
        foreach ($category in $_.Matches) {
            $c = Pipe-Category -String $category
            # Add the filtered category hashtable to the $settings array 
            $settings += , $c
            # $RmAPI.Log("$c")
        }
    }

    # $settings > $testfile

    return $settings

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
    
    # Get the variable properties

    # Make the Properties hashtable
    $Variable.Properties = @{"Name" = $Variable.Key}

    # Filter type
    # Type is special since it's required
    if("$($Variable.UnfilteredProperties)" -match "$($Patterns.Type)") {
        $Variable.Properties.Type = Remove-Whitespace -String $Matches[1]
        # Default undeclared type to String without logging
        if($Variable.Properties.Type -eq "") {
            $Variable.Properties.Type = "String"
        }
        # Default typos to String
        if($variableTypes -NotContains $Variable.Properties.Type) {
            $RmAPI.LogError("Variable type '$($Variable.Properties.Type)' is not implemented, defaulting to String")
            $Variable.Properties.Type = "String"
        }
    }

    # Creates Extensions array in $Variables if Variable type is not one of the default variable types
    if ($defaultVariableTypes -notcontains $Variable.Property.Type) {
        $Variable.Add('Extension', @{})
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
                $Variable.Properties["$key"] = "$value"

                # If property name is Options it creates an Extension in $Variable.Extensions
                if ($key -eq 'Options') {
                    switch ($Variable.Properties.Type) {
                        'RadioButton' {
                            $Variable.Extension.Add("$_",@{"Label"=@(); "Option"=@()})
                            ($value -split '; ') | ForEach-Object {
                                if ($_ -match ',') {
                                    $c=$_ -split ','
                                    $Variable.Extension.$($Variable.Properties.Type).Label+=$c[0]
                                    $Variable.Extension.$($Variable.Properties.Type).Option+=$c[1]
                                } else {
                                    $Variable.Extension.$($Variable.Properties.Type).Label+=$_
                                    $Variable.Extension.$($Variable.Properties.Type).Option+=$_
                                }
                            }
                            break
                        }
                        # add more extensions here
                        default {
                            break
                        }
                    }
                }
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
    Select-String -Pattern $Patterns.UnfilteredProperty -input $Category.UnfilteredProperties -AllMatches | Foreach {
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
        switch ($var.Properties.Type) {
            'RadioButton' {
                $ini += Variable-Ini -Variable $var -Index $j
                $k=0
                $var.Extension.$_.Label | ForEach-Object {
                    $ini += Variable-Ini -Variable $var -Index $j -Type Extension -ExtensionIndex $k
                    $k++
                }
            }
            default {
                $ini += Variable-Ini -Variable $var -Index $j
                
            }
        }
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
        $Index,
        [Parameter(Mandatory=$false)]
        [ValidateSet('Default','Extension')]
        $Type,
        [Parameter(Mandatory=$false)]
        $ExtensionIndex
    )

    # Properties used internally for skin generation, not user submitted
    $internalVariableProperties = @{
        "Index" = $Index
        "Container" = "RightPanel"
        "SettingsFile" = $dynamicVariableFile
    }

    # Get template for type
    switch ($Type) {
        'Extension' {
            $ini = Get-Content -Path "$($variableTemplatesDir)$($Variable.Properties.Type)(Extension).inc" -Raw
            break
        }
        default {
            $ini = Get-Content -Path "$($variableTemplatesDir)$($Variable.Properties.Type).inc" -Raw
        }
    }
    $ini > $testfile
    # Filter template
    $ini = Filter-Template -Template $ini -Properties $internalVariableProperties
    $RmAPI.Variable('Got here!')
    switch ($Type) {
        'Extension' {
            $ini = Filter-Template -Template $ini -Properties $Variable.Properties
            $Variable.Extension.Keys | ForEach-Object {
                $ini = Filter-Extension -Template $ini -Properties $Variable.Extension.RadioButton -Index $ExtensionIndex
            }
            break
        }
        default {
            
            $ini = Filter-Template -Template $ini -Properties $Variable.Properties
        }
    }
    $ini = Filter-Template -Template $ini -Properties $Variable
    $ini = Remove-UnformattedValues -Template $ini

    return $ini

}

function Category-List {
    param(
        [Parameter(Mandatory=$true)]
        $Settings
    )

    $ini = Get-Content -Path "$($templatesDir)FirstItem.inc" -Raw
    $ini = Filter-Template -Template $ini -Properties @{"Container" = "LeftPanel"}

    $i = 0
    foreach ($category in $Settings) {
        $externalProperties = @{
            "Index" = $i
            "Container" = "LeftPanel"
            "InternalVariables" = "$dynamicInternalVariableFile"
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
function Filter-Extension { 
    # processes extensions of templates.
    param(
        [Parameter(Mandatory=$true)]
        [string]
        $Template,
        [Parameter(Mandatory=$true)]
        [System.Collections.Hashtable]
        $Properties,
        [Parameter(Mandatory=$true)]
        $Index
    )

    # The extension contians two arrays named as the replacements
    # and value is replaced by contents of the array, indexed.
    $Properties.GetEnumerator() | ForEach-Object {
        $Template = $Template.replace("{$($_.Key)}","$($_.Value[$Index])")
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
