function Update {

}

# variables from Rainmeter
$skin = $RmAPI.VariableStr("Skin")
$settingsFile = $RmAPI.VariableStr("SettingsFile")

# directories & files
$testfile = "$($RmAPI.VariableStr('@'))test.inc"
$generatedSkinFile = "$($RmAPI.VariableStr('ROOTCONFIGPATH'))settings\settings.ini"
$categoriesDir = "$($RmAPI.VariableStr('ROOTCONFIGPATH'))settings\categories\"
$settingsFilePath = "$($RmAPI.VariableStr('SKINSPATH'))$($skin)\@Resources\$($settingsFile)"

# Line operation variables
$currentIndentifier = ""
$categoryIdentifier = ";@"
$variableIdentifier = ";;"

# Regex patterns
$categoryPattern = '(?s-m);@(.*?)(?=;@|$)'
$categoryTitlePattern = '(?s-m)(?<=;@)(.*?)(?=\n)'
# old pattern, doesn't lookahead for EOF, might be relevant
# variablePattern = '(?s-m);;(.*?)\n(?!;).*?\n';
$variablePattern = '(?s-m);;(.*?)\n(?![;$]).*?\n';
$variableTypePattern = '(?<=Type=)(.*?)(?=\n)'
$variableDefaultValuePattern = '(?<=DefaultValue=)(.*?)(?=\n)'
$variableNamePattern = '(?<=Name=)(.*?)(?=\n)'

function Construct {

    # Read settings file
    $file = Get-Content $settingsFilePath -Raw

    # Filter settings file into staggered array
    $settings = Filter-Settings $file

    # Variable to hold generated .ini
    $ini = ""

    # Construct categories
    $i = 0
    foreach ($category in $settings) {
        $ini += New-Category $category $i
        $i++
    }

    $ini > $generatedSkinFile

}

function Filter-Settings($settingsFileContent) {

    $categories = $settingsFileContent | Select-String -Pattern $categoryPattern -AllMatches

    $settings = @()
    
    foreach ($match in $categories.Matches) {

        $title = $match | Select-String -Pattern $categoryTitlePattern
        $category = @($title.Matches[0].value)
        $variables = $match | Select-String -Pattern $variablePattern -AllMatches

        foreach ($variable in $variables.Matches) {
            $type = $variable | Select-String -Pattern $variableTypePattern
            $name = $variable | Select-String -Pattern $variableNamePattern
            $defaultvalue = $variable | Select-String -Pattern $variableDefaultValuePattern

            $type = Filter-Newline $type.Matches[0].value
            $name = Filter-Newline $name.Matches[0].value
            $defaultvalue = Filter-Newline $defaultvalue.Matches[0].value

            $variable = @{'Type' = $type; 'Name' = $name; 'DefaultValue' = $defaultvalue}
            $category += , $variable
        }

        $settings += , $category

    }

    return $settings

}

function New-Category($category, $i) {

    $variables = $category[1..($category.Length)]

    $RmAPI.Log("Count: $($variables.Length)")

    # List all variables to $text
    $text = ""

    foreach ($var in $variables) {
        $text += "$($var.Name) "
    }

    $categoryIni = @"
[Title$($i)]
Meter=String
Text=$($text)
MeterStyle=TextStyle

"@

    return $categoryIni

}

# no worky
function Filter-Newline($s) {

    $filter = "`n"
    $s = $s -replace([System.Environment]::NewLine,"")

    return $s 

}
