function Update {

}

# Implemented types array
$variableTypes = @("String", "Integer", "Color", "Toggle")
$categoryTypes = @("Default", "About")
$listTypes = @("Default", "Super", "About")

# variables from Rainmeter
$skin = $RmAPI.VariableStr("Skin")
$settingsFile = $RmAPI.VariableStr("SettingsFile")
$settingsFilePath = "$($RmAPI.VariableStr('SKINSPATH'))$($skin)\@Resources\$($settingsFile)"

# directories & files
$testfile = "$($RmAPI.VariableStr('@'))test.inc"
$skinDir = "$($RmAPI.VariableStr('ROOTCONFIGPATH'))settings\"

$generatedCategoriesDir = "$($skinDir)categories\"
$generatedSkinFile = "$($skinDir)\settings.ini"

# template directories
$templatesDir = "$($RmAPI.VariableStr('@'))templates\"
$categoryTemplatesDir = "$($templatesDir)category\"
$listTemplatesDir = "$($templatesDir)list\"
$variableTemplatesDir = "$($templatesDir)variable\"

function Construct {

    Make-Directories

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

function Make-Directories {
    New-Item -Path $skinDir -ItemType "directory" -Name "categories"
    Get-ChildItem -Path "$generatedCategoriesDir*" -Include *.inc | Remove-Item
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
            "Icon" = "$($category.Icon)"
            "Category" = "$($category.Title)"
            "Container" = "LeftPanel"
            "LeftMouseUpAction" = "[!WriteKeyValue Variables s_CurrentCategory $i][!Refresh]"
        }

        # If category type is not implemented, make it Default
        if($listTypes -NotContains $category.Type) {
            $type = "Default"
        } else {
            $type = $category.Type
        }

        $template = Get-Content -Path "$($listTemplatesDir)$($type).inc" -Raw
        $ini += Filter-Template -Template $template -Properties $Properties
        $i++
    }

    $ini > "$($generatedCategoriesDir)CategoryList.inc"

}

function Settings-Array {
    param (
        [Parameter()]
        [Alias("String")]
        $settingsFileContent
    )

    # Regex patterns
    $categoryPattern = '(?s-m)(;@.*?)(?=;@|$)'
    $variablePattern = '(?s-m)(;;.*?)\n(?![;$]).*?[\n|$]'
    $variablePatterns = @{
        "Type" = '(?<=;;Type=)(.*?)(?=\n)'
        "Name" = '(?<=;;Name=)(.*?)(?=\n)'
        "Description" = '(?<=;;Description=)(.*?)(?=\n)'
        "DefaultValue" = '(?<=;;DefaultValue=)(.*?)(?=\n)'
        "RealName" = '(?m-s)^(?!;)(.*?)(?==)'
        "CurrentValue" = '(?m-s)^(?!;).*=(.*?)(?=\n)'
    }
    $categoryPatterns = @{
        "Title" = '(?s-m)(?<=;@)(.*?)(?=\n)'
        "Type" = '(?<=;!Type=)(.*?)(?=\n)'
        "Icon" = '(?<=;!Icon=)(.*?)(?=\n)'
        "UnfilteredVariables" = '(?s-m)(;;.*)'
        "Description" = '(?<=;!Description=)(.*?)(?=\n)'
    }

    # Declare $settings as an empty array to make sure that $settings is an array
    $settings = @()

    # Get all $categoryPattern matches from $settingsFileContent to %_ with Foreach
    Select-String -Pattern $categoryPattern -input $settingsFileContent -AllMatches | Foreach {

        # Iterate over each matched $category in $_.Matches
        foreach ($category in $_.Matches) {

            # Filter category hashtables
            $c = Filter-Hashtable -String $category -Properties $categoryPatterns

            # Debug log
            $RmAPI.Log("Building category: $($c.Title).")

            # Create empty Variables array
            $c.Add("Variables", @())

            # Get all $variablePattern matches from $c.UnfilteredVariables to %_ with Foreach
            Select-String -Pattern $variablePattern -input $c.UnfilteredVariables -AllMatches | Foreach {
                # Debug log
                $RmAPI.Log("Filtering variables from: $($_.Matches)")
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
            $hash.Add("$($_.Key)",$s)
        }
    }
    
    return $hash

}

function Category-Ini {
    param (
        [Parameter()]
        $Category,
        [Parameter()]
        $i
    )

    # path to current category.inc
    $file = "$($generatedCategoriesDir)$($i).inc"
    
    # Properties to replace in templates
    $Properties = @{
        "Index" = $i
        "Title" = $Category.Title
        "Icon" = "$($category.Icon)"
        "Container" = "RightPanel"
        "Description" = $Category.Description
    }

    # First Item template
    $ini = Get-Content -Path "$($templatesDir)FirstItem.inc" -Raw

    # If category type is not implemented, make it Default
    if($categoryTypes -NotContains $category.Type) {
        $type = "Default"
    } else {
        $type = $category.Type
    }

    # Build category from template
    $template = Get-Content -Path "$($categoryTemplatesDir)$($type).inc" -Raw
    $ini += Filter-Template -Template $template -Properties $Properties

    # get variables hashtable array
    $variables = $Category.Variables

    $j = 0
    foreach ($var in $variables) {
        $ini += Variable-Ini -Variable $var -Index $j
        $j++
    }

    $ini > $file

}

function Variable-Ini {
    param (
        [Parameter(Mandatory=$true)]
        $Variable,
        [Parameter(Mandatory=$true)]
        $Index
    )

    $nonVariableProperties = @{
        "Index" = $Index
        "Container" = "RightPanel"
    }
    
    if ($variableTypes -contains $Variable.Type) {
        # Get template
        $ini = Get-Content -Path "$($variableTemplatesDir)$($Variable.Type).inc" -Raw
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