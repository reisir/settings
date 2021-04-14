function Update {

}

# Implemented types array
$implementedTypes = @("String", "Integer", "Color", "Toggle")

# variables from Rainmeter
$skin = $RmAPI.VariableStr("Skin")
$settingsFile = $RmAPI.VariableStr("SettingsFile")

# directories & files
$testfile = "$($RmAPI.VariableStr('@'))test.inc"
$generatedSkinFile = "$($RmAPI.VariableStr('ROOTCONFIGPATH'))settings\settings.ini"
$categoriesDir = "$($RmAPI.VariableStr('ROOTCONFIGPATH'))settings\categories\"
$settingsFilePath = "$($RmAPI.VariableStr('SKINSPATH'))$($skin)\@Resources\$($settingsFile)"

function Construct {

    # Template directory
    $templatesDir = "$($RmAPI.VariableStr('@'))templates\"

    # Read settings file
    $settingsFileContent = Get-Content $settingsFilePath -Raw

    # Filter settings file into staggered array
    $settings = Settings-Array -String $settingsFileContent

    # Variable to hold generated .ini
    # Get rainmeter section from template
    $ini = Get-Content -Path "$($templatesDir)Rainmeter.inc" -Raw

    # Construct categories
    $i = 0
    foreach ($category in $settings) {
        Category-Ini -category $category -i $i
        $i++
    }

    Category-List -Settings $settings

    $ini > $generatedSkinFile

}

function Category-List {
    param(
        [Parameter(Mandatory=$true)]
        $Settings
    )

    $templatesDir = "$($RmAPI.VariableStr('@'))templates\"

    $ini = Get-Content -Path "$($templatesDir)FirstItem.inc" -Raw
    $ini = Filter-Template -Template $ini -Properties @{"Container" = "LeftPanel"}
    $listTemplate = Get-Content -Path "$($templatesDir)CategoryList.inc" -Raw

    $i = 0
    foreach ($category in $Settings) {
        $Properties = @{
            "Index" = $i
            "Category" = "$($category[0]).inc"
            "Container" = "LeftPanel"
        }
        $ini += Filter-Template -Template $listTemplate -Properties $Properties
        $i++
    }

    $ini > "$($categoriesDir)CategoryList.inc"

}

function Settings-Array {
    param (
        [Parameter()]
        [Alias("String")]
        $settingsFileContent
    )

    # Regex patterns
    $categoryPattern = '(?s-m);@(.*?)(?=;@|$)'
    $categoryTitlePattern = '(?s-m)(?<=;@)(.*?)(?=\n)'
    $variablePattern = '(?s-m);;(.*?)\n(?![;$]).*?\n'
    $variableProperties = @{
        "Type" = '(?<=Type=)(.*?)(?=\n)'
        "Name" = '(?<=Name=)(.*?)(?=\n)'
        "Description" = '(?<=Description=)(.*?)(?=\n)'
        "DefaultValue" = '(?<=DefaultValue=)(.*?)(?=\n)'
        "RealName" = '(?m-s)^(?!;)(.*?)(?==)'
        "CurrentValue" = '(?m-s)^(?!;).*=(.*?)(?=\n)'
    }

    $categories = $settingsFileContent | Select-String -Pattern $categoryPattern -AllMatches

    $settings = @()

    foreach ($match in $categories.Matches) {

        $title = $match | Select-String -Pattern $categoryTitlePattern
        $category = @(Remove-Newline -String $title.Matches[0].value)
        $variables = $match | Select-String -Pattern $variablePattern -AllMatches

        foreach ($variable in $variables.Matches) {
            $var = Filter-Hashtable -String $variable -Properties $variableProperties
            $category += , $var
        }

        $settings += , $category

        }

    return $settings

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
            $s = Remove-Newline -String $Matches[1]
            $hash.Add("$($_.Key)",$s)
        }
    }
    
    return $hash

}

function Category-Ini {
    param (
        [Parameter()]
        $category,
        [Parameter()]
        $i
    )

    # path to current category.inc
    $file = "$($categoriesDir)$($i).inc"

    # Template strings directory
    $templatesDir = "$($RmAPI.VariableStr('@'))templates\"

    $ini = Get-Content -Path "$($templatesDir)FirstItem.inc" -Raw
    $ini += Get-Content -Path "$($templatesDir)CategoryTitle.inc" -Raw
    $Properties = @{
        "Index" = $i
        "Title" = $category[0]
        "Container" = "RightPanel"
    }
    $ini = Filter-Template -Template $ini -Properties $Properties

    # get variables hashtable array
    $variables = $category[1..($category.Length)]

    $j = 0
    foreach ($var in $variables) {
        $ini += Variable-Ini -Variable $var -Index $j
        $j++
    }
    # log n of variables in this category
    # $RmAPI.Log("Variables in Category$($i): $($variables.Length)")

    $ini > $file

}

function Variable-Ini {
    param (
        [Parameter(Mandatory=$true)]
        $Variable,
        [Parameter(Mandatory=$true)]
        $Index
    )

    # Template strings directory
    $templatesDir = "$($RmAPI.VariableStr('@'))templates\variables\"

    $nonVariableProperties = @{
        "Index" = $Index
        "Container" = "RightPanel"
    }
    
    if ($implementedTypes -contains $Variable.Type) {
        # Get template
        $ini = Get-Content -Path "$($templatesDir)$($Variable.Type).inc" -Raw
        # Replace {Index} with $Incdex
        $ini = Filter-Template -Template $ini -Properties $nonVariableProperties
        $ini = Filter-Template -Template $ini -Properties $Variable
    } else {
        $ini = ""
    }

    return $ini

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