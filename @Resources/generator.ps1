function Update {

}

# Variables from Rainmeter
$variableFilePath = "$($RmAPI.VariableStr('s_RawPath'))"
$dynamicVariableFile = "#SKINSPATH#$($RmAPI.VariableStr('s_DynamicVariableFile'))"
# $dynamicThemeFile = "#ROOTCONFIGPATH#settings\themes\$($RmAPI.VariableStr('s_SettingsTheme')).inc"
$dynamicThemeFile = "#ROOTCONFIGPATH#settings\Themes\1.inc"
$dynamicInternalVariableFile = "#ROOTCONFIGPATH#settings\includes\Variables.inc"

# Generator directories
$resourcesDir = "$($RmAPI.VariableStr('@'))"
$includeDir = "$($resourcesDir)Includes\"
$addonsDir = "$($resourcesDir)Addons\"
$themesDir = "$($resourcesDir)Themes\"
$templatesDir = "$($resourcesDir)Templates\"
$meterstylesDir = "$($resourcesDir)MeterStyles"

# Template scripts
$variableScriptsDir = "$($templatesDir)Variables\"
$categoryScriptsDir = "$($templatesDir)Categories\"
$listitemScriptsDir = "$($templatesDir)ListItems\"
$commonScriptsDir = "$($templatesDir)Common\"

# Title script for easy access in Variable template scripts
$variableCommonScript = "$($commonScriptsDir)VariableCommons.ps1"
$listCommonScript = "$($commonScriptsDir)ListCommons.ps1"

# Defaults
$defaultVariableType = "String"
$defaultCategoryType = "Default"
$defaultListItemType = "Default"

# Generated directories
$generatedSkinDir = "$($RmAPI.VariableStr('ROOTCONFIGPATH'))Settings\"
$generatedCategoriesDir = "$($generatedSkinDir)Categories\"
$generatedIncludeDir = "$($generatedSkinDir)Includes\"
$generatedAddonsDir = "$($generatedSkinDir)Addons\"
$generatedThemesDir = "$($generatedSkinDir)Themes\"

# Testfile
$testfile = "$($resourcesDir)test.inc"

function Construct {

    # Implemented types
    $variableTypes = @(Get-ChildItem -Path $($variableScriptsDir) -Name | % { $_.Split('.')[0] })
    $categoryTypes = @(Get-ChildItem -Path $($categoryScriptsDir) -Name | % { $_.Split('.')[0] })
    $listTypes = @(Get-ChildItem -Path $($listitemScriptsDir) -Name | % { $_.Split('.')[0] })

    # Read variables file
    $RmAPI.Log("Parsing settings file")
    $settingsFileContent = Get-Content $variableFilePath -Raw

    # GET OVERRIDES FROM VARIABLE FILE
    $overridePattern = '(?s-m)(;!.*?)(?=;@|$)'
    $settingsFileContent -match $overridePattern

    $Overrides = Filter-Properties -String $Matches[0]

    if($Overrides.SkinName) { $GeneratedSkinName = "$($Overrides.SkinName.Trim()).ini" } 
    else { $GeneratedSkinName = "Settings.ini" }

    if($Overrides.SkinDirectory) { $TargetDirectory = "$($Overrides.SkinDirectory.Trim())\" } 
    else { $TargetDirectory = "Settings\" }

    # Generated files
    $generatedSkinFile = "$($generatedSkinDir)$GeneratedSkinName"

    # Injectors
    $targetSkin = $RmAPI.VariableStr('s_Skin')
    $injectPath = "$($RmAPI.VariableStr('SKINSPATH'))$targetSkin\$TargetDirectory"

    # TODO: Handle unformatted variable files
    if($settingsFileContent -notmatch $categoryPattern) {
        $RmAPI.LogError("Variable file is not formatted")
        return
    }

    # Reset directories, copy files etc.
    Prepare-Directories

    # Regex patterns
    $categoryPattern = '(?s-m)(;@.*?)(?=;@|$)'
    
    # Get all $categoryPattern matches from $settingsFileContent to %_ with Foreach
    $settings = @(
        Select-String -Pattern $categoryPattern -Input $settingsFileContent -AllMatches | ForEach-Object {
        # Filter each matched $category
        foreach ($category in $_.Matches) {
            Pipe-Category -String $category
        }
    })

    # Write main settings.ini
    $RainmeterOptions = @{
        "SettingsFile" = $dynamicVariableFile
        "ThemeFile" = $dynamicThemeFile
    }
    &"$($templatesDir)Rainmeter.ps1" -Options $RainmeterOptions > $generatedSkinFile
    
    # Construct categories
    $settings | ForEach-Object { $i = 0 } {
        Category-Ini -category $_ -i $i
        $i++
    }

    # Construct category list
    $RmAPI.Log("Category list")
    Category-List -Settings $settings

    Join-MeterStyles

    &"$($templatesDir)TitleBar.ps1" -Overrides $Overrides > "$($generatedIncludeDir)TitleBar.inc"
    
    $Overrides > $testfile

    Inject-Settings -Path $injectPath

}

function Join-MeterStyles {
        
    Get-ChildItem $($meterstylesDir) -Include *.inc -Recurse | ForEach-Object {Get-Content $_; ""} | Out-File "$($includeDir)MeterStyles.inc"
   
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
            $RmAPI.LogError("Variable type '$($Variable.Type)' is not implemented, defaulting to $defaultVariableType")
            $Variable.Type = $defaultVariableType
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

    # Filter type
    # Type is special since it's required
    if("$($Category.UnfilteredProperties)" -match "$($Patterns.Type)") {
        $Category.Type = Remove-Whitespace -String $Matches[1]
        # Default undeclared type to Default without logging
        if($Category.Type -eq "") {
            $Category.Type = $defaultCategoryType
        }
        # Default typos to Default
        if($listTypes -NotContains $Category.Type) {
            $RmAPI.LogError("Category type '$($Category.Type)' is not implemented. Changed to $defaultCategoryType")
            $Category.Type = $defaultCategoryType
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

    # $RmAPI.Log("Category $($Category.Name) ($i.inc)")

    # Local Type variable to not fuck up the Category List creation
    $Type = $Category.Type
    if($categoryTypes -NotContains $Type) { $Type = $defaultCategoryType }

    # Set the Index
    $Category.Index = $i

    # First Item template
    $ini = &"$($templatesDir)FirstItem.ps1" -Side "Right"
    
    # Call the appropriate Variable script
    $ini += &"$($categoryScriptsDir)$($Type).ps1" -Category $Category
    $ini += "`n`n"
    
    # Create variable inis
    $Category.Variables | ForEach-Object { $j = 0 } {
        # $RmAPI.Log("Variable $($_.Key) ($j.inc)")
        $ini += Variable-Ini -Variable $_ -Index $j
        $j++
    }

    # Last Item template
    $ini += &"$($templatesDir)LastItem.ps1" -Side "Right"
    
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

    # Load common variable functions to scope
    ."$variableCommonScript"

    # Set index of variable
    $Variable["Index"] = $Index

    # Call the appropriate Variable script
    $ini = &"$($variableScriptsDir)$($Variable.Type).ps1" -Variable $Variable -SettingsFile $dynamicVariableFile
    $ini += "`n`n"

    return $ini

}

function Category-List {
    param(
        [Parameter(Mandatory=$true)]
        $Settings
    )

    # First Item template
    $ini = &"$($templatesDir)FirstItem.ps1" -Side "Left"

    ."$listCommonScript"
    
    # Loop through the categories
    $Settings | ForEach-Object { $i = 0 } {
        # Set the Index number
        $_.Index = $i
        
        # Get the category type
        $Type = $_.Type
        if($listTypes -NotContains $_.Type) { $Type = $defaultListItemType }

        # Call the appropriate ListItem template script
        $ini += &"$($listitemScriptsDir)$($Type).ps1" -Category $_ -InternalSettingsFile $dynamicInternalVariableFile
        $ini += "`n`n"
        $i++
    }

    # Last Item template
    $ini += &"$($templatesDir)LastItem.ps1" -Side "Left"

    # Credit icon, outside of the scrollable item list
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

function Filter-Properties {
    param (
    [Parameter(Mandatory=$true)]
    [string]
    $String
    )

    $Patterns = @{
        "UnfilteredProperty" = '(?s-m)(?<=\|)(.*?)(?=\||\n|$)'
        "PropertyKey" = '^\s*(.*?)\s|$|\n'
        "PropertyValue" = '(?s-m)\s?.*?\s(.*?)(?=$|\n|\|)'
    }

    $hash = @{}
    # Match every | Key Value | pair from the property line
    Select-String -Pattern $Patterns.UnfilteredProperty -input $String -AllMatches | ForEach-Object {
        # Filter each matched $category
        foreach ($UnfilteredProperty in $_.Matches) {
            $key, $value = ""
            if($UnfilteredProperty -match $Patterns.PropertyValue) {
                $value = $Matches[1]
            }
            # Only add the property to the hashtable if it has a key.
            if($UnfilteredProperty -match $Patterns.PropertyKey) {
                $key = Remove-Whitespace -String $Matches[1]
                $hash["$key"] = "$value"
            }
        }
    }

    return $hash
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
    New-Item -Path $generatedSkinDir -ItemType "directory" -Name "Categories"
    New-Item -Path $generatedSkinDir -ItemType "directory" -Name "Includes"
    New-Item -Path $generatedSkinDir -ItemType "directory" -Name "Addons"
    New-Item -Path $generatedSkinDir -ItemType "directory" -Name "Themes"
    New-Item -Path $injectPath -ItemType "directory" -Name $TargetDirectory.TrimEnd('/')
    # Remove files in generated directories
    Get-ChildItem -Path "$generatedCategoriesDir*" -Include *.inc | Remove-Item
    Get-ChildItem -Path "$generatedIncludeDir*" -Include *.inc | Remove-Item
    # Remove settings injected earlier
    Get-ChildItem -Path "$($injectPath)$TargetDirectory*" -Include @("*.inc","*.ini","RainRGB4RunCommand.exe") | Remove-Item
    # Copy Includes to generated skin
    Copy-Item -Path "$includeDir*" -Destination $generatedIncludeDir -Recurse
    # Copy Themes to generated skin
    Copy-Item -Path "$themesDir*" -Include "*.inc" -Destination $generatedThemesDir -Recurse
    # Copy Addons to generated skin
    Copy-Item -Path "$addonsDir*" -Destination $generatedAddonsDir -Recurse
}

function Inject-Settings {
    param (
        [Parameter()]
        $Path
    )

    # Inject generated settings
    Copy-Item -Path "$generatedSkinDir*" -Destination $Path -Recurse

    $RmAPI.Log("Refreshing Rainmeter")
    $RmAPI.Bang('[!RefreshApp]')
    # $RmAPI.Bang('[!ActivateConfig]$($targetSkin)\settings\settings.ini')
    $RmAPI.Log("Loading generated settings skin")
    Start-Process "C:\Program Files\Rainmeter\Rainmeter.exe" -ArgumentList "!ActivateConfig", "$($targetSkin)\$TargetDirectory", "`"$GeneratedSkinName`""
}
