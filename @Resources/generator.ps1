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

    # $settings > $testfile
    $ini > $generatedSkinFile

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

    $categories = $settingsFileContent | Select-String -Pattern $categoryPattern -AllMatches

    $settings = @()

    foreach ($match in $categories.Matches) {

        $properties = [ordered]@{
            "title" = '(?s-m)(?<=;@)(.*?)(?=\n)'
            "variable" = '(?s-m);;(.*?)\n(?![;$]).*?\n'
        }

        $title = $match | Select-String -Pattern $categoryTitlePattern
        $category = @($title.Matches[0].value)
        $variables = $match | Select-String -Pattern $variablePattern -AllMatches

        foreach ($variable in $variables.Matches) {

            $var = Variable-Hastable -String $variable
            $category += , $var
        
        }

        $settings += , $category

        }

    return $settings

}

function Variable-Hastable {
    param (
        [Parameter()]
        [string]
        $String
    )

    $properties = @{
        "Type" = '(?<=Type=)(.*?)(?=\n)'
        "Name" = '(?<=Name=)(.*?)(?=\n)'
        "Description" = '(?<=Description=)(.*?)(?=\n)'
        "DefaultValue" = '(?<=DefaultValue=)(.*?)(?=\n)'
        "CurrentValue" = '(?m-s)^(?!;).*=(.*?)(?=\n)'
    }

    $var = @{}
    $properties.GetEnumerator() | ForEach-Object{

        if("$($String)" -match "$($_.Value)") {
            $var.Add("$($_.Key)",$Matches[1])
        }

    }
    
    return $var

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

    # get title of category
    $title = $category[0] -replace "`t|`n|`r",""

    $c = Get-Content -Path "$($templatesDir)Category.inc" -Raw
    $ini = $c -f $i, $title

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
    
    # Get variable type and sanitize the random newline character
    $type = $Variable.Type -replace "`t|`n|`r",""

    if ($implementedTypes -contains $type) {
        $c = Get-Content -Path "$($templatesDir)$($type).inc" -Raw
        $ini = $c -f $Index, $Variable.Name, $Variable.Description, $Variable.CurrentValue
    } else {
        $ini = ""
    }

    return $ini

}
