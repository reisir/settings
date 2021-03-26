function Update {

}

# variables from Rainmeter
$skin = $RmAPI.VariableStr("Skin")
$settingsFile = $RmAPI.VariableStr("SettingsFile")

# directories & files
$testfile = "$($RmAPI.VariableStr('@'))test.inc"
$categoriesDir = "$($RmAPI.VariableStr('ROOTCONFIGPATH'))settings\categories\"
$settingsFilePath = "$($RmAPI.VariableStr('SKINSPATH'))$($skin)\@Resources\$($settingsFile)"

# Line operation variables
$currentIndentifier = ""
$categoryIdentifier = ";@"
$variableIdentifier = ";;"

# Regex patterns
$categoryPattern = '(?s-m);@(.*?)(?=;@|$)'
$categoryTitlePattern = '(?s-m)(?<=;@)(.*?)(?=\n)'
$variablePattern = '(?s-m);;(.*?)\n(?!;).*?\n'
$variableTypePattern = '(?<=Type=)(.*?)(?=\n)'
$variableDefaultValuePattern = '(?<=DefaultValue=)(.*?)(?=\n)'
$variableNamePattern = '(?<=Name=)(.*?)(?=\n)'

## Full settings object
$settings = @()
$categories = @()

function Construct {

    Filter-Settings > $testfile

}

function Filter-Settings {

    # Read settings file
    $settingsFileContent = Get-Content $settingsFilePath -Raw
    $categories = $settingsFileContent | Select-String -Pattern $categoryPattern -AllMatches

    foreach ($match in $categories.Matches) {
        $title = $match | Select-String -Pattern $categoryTitlePattern
        $category = @($title.Matches[0].value)
        $variables = $match | Select-String -Pattern $variablePattern -AllMatches

        foreach ($variable in $variables.Matches) {
            $type = $variable | Select-String -Pattern $variableTypePattern
            $name = $variable | Select-String -Pattern $variableNamePattern
            $defaultvalue = $variable | Select-String -Pattern $variableDefaultValuePattern
            $variable = @{'type' = $type.Matches[0]; 'name' = $name.Matches[0]; 'defaultValue' = $defaultvalue.Matches[0]}
            $category += $variable
        }

        $settings += $category

    }

    return $settings

}

function New-Category($category, $i) {
    $categoryFile = "$($categoriesDir)$($i).inc"

    $categoryIni = @"
    [Title]
    Meter=String
    Text=$($category[0])
    MeterStyle=TextStyle
    
"@

    $categoryIni > $categoryFile
    
}