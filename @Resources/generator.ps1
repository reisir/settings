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
$variableDescriptionPattern = '(?<=Description=)(.*?)(?=\n)'
$variableCurrentValuePattern = '(?m-s)^(?!;).*=(.*?)(?=\n)'

function Construct {

    # Read settings file
    $file = Get-Content $settingsFilePath -Raw

    # Filter settings file into staggered array
    $settings = Filter-Settings $file

    # Variable to hold generated .ini
    $ini = Rainmeter-Section

    # Construct categories
    $i = 0
    foreach ($category in $settings) {
        New-Category $category $i
        # $ini += New-Category $category $i
        $i++
    }

    $settings > $testfile
    $ini > $generatedSkinFile

}

function Rainmeter-Section {
    $ini = @"
[Rainmeter]
DefaultUpdateDivider=-1
@IncludeSkinVariables=#ROOTCONFIGPATH#settings\skinVariables.inc
@IncludeSettingsStyles=#ROOTCONFIGPATH#settings\includes\VarStyles.inc

[IncludeBackground]
@IncludeCategory=#ROOTCONFIGPATH#settings\includes\Background.inc

[IncludeCategory]
@IncludeCategory=#ROOTCONFIGPATH#settings\categories\[#s_CurrentCategory].inc

"@

return $ini

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
            $description = $variable | Select-String -Pattern $variableDescriptionPattern
            $defaultvalue = $variable | Select-String -Pattern $variableDefaultValuePattern
            $currentvalue = $variable | Select-String -Pattern $variableCurrentValuePattern

            $variable = @{}
            $variable.Add('Type', $type.Matches[0].value)
            $variable.Add('Name', $name.Matches[0].value)
            $variable.Add('DefaultValue', $defaultvalue.Matches[0].value)
            $variable.Add('Currentvalue', $currentvalue.Matches[0].Groups[1].value)
            $variable.Add('Description', $description.Matches[0].value)

            $category += , $variable
        }

        $settings += , $category

    }

    return $settings

}

function New-Category($category, $i) {

    # path to current category.inc
    $file = "$($categoriesDir)$($i).inc"
    # @Include statement to return to main settings.ini file
    $include = @"
[IncludeCategory$i]
@IncludeCategory$i=categories\$i.inc

"@

    # new line appears from category object because idk
    # get title of category
    $title=$category[0]

    $ini = @"
[First]
Meter=Image
MeterStyle=FirstItem
[Title$i]
Meter=String
Text=$title
MeterStyle=CategoryTitle

"@

    # get variables hashtable array
    $variables = $category[1..($category.Length)]

    $j = 0
    foreach ($var in $variables) {
        $ini += New-Variable $var $j
        $j++
    }
    # log n of variables in this category
    # $RmAPI.Log("Variables in Category$($i): $($variables.Length)")

    $ini > $file

    return $include

}

function New-Variable($var, $j) {

    $type = $var.Type
    $ini = ""
    
    # $RmAPI.Log("Constructing variable of type: $($var.Type)")
    switch ($type) {
        # the random newline is fucking shit up here too
        # have to use -match instead of -eq
        {$_ -match "String"} { 
            # $RmAPI.Log("Constructing String variable")
            $ini = @"
[Var$j]
Meter=String
Text=$($var.Name)
MeterStyle=VarTitle
[Var$($j)Description]
Meter=String
Text=$($var.Description)
MeterStyle=VarDescription
[Value$i]
Meter=String
Text=$($var.CurrentValue)
MeterStyle=VarStringValue

"@
         }
        Default {
            $ini = ""
        }
    }

    return $ini

}
