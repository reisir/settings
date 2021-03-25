function Update {

}

# variables from Rainmeter
$skin = $RmAPI.VariableStr("Skin")
$settingsFile = $RmAPI.VariableStr("SettingsFile")

# directories & files
$testfile = "$($RmAPI.VariableStr('@'))includes\test.inc"
$categoriesDir = "$($RmAPI.VariableStr('ROOTCONFIGPATH'))settings\categories\"
$settingsFilePath = "$($RmAPI.VariableStr('SKINSPATH'))$($skin)\@Resources\$($settingsFile)"

# Script variables

function Construct {

    # Log
    # $RmAPI.Log($settingsFilePath)
    # $RmAPI.Log('Reading settings file from:')

    # Read settings file
    $settingsFileContent = Get-Content $settingsFilePath

    # Declare line operation variables
    $currentIndentifier = ""
    $categoryIdentifier = ";@"
    $category = @()
    $variableIdentifier = ";;"
    $variable = ""

    # Do operations on each line of the settings file

    $i = 0
    foreach ($line in $settingsFileContent) {
        $identifier = -join $line[0..1]
        if ($identifier -eq $categoryIdentifier) {
            $category = @()
            $category += -join $line[2..($line.Length)]
            New-Category $category $i
            $i++
        } elseif ($identifier -eq $variableIdentifier) {
            $category += -join $line[2..($line.Length)]
        }
    }

    $categories > $testfile

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