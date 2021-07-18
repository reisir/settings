function Update {

}

function Paths {

    param(
        [string]$raw = "",
        [uint32]$generate = 0
    )

    if(-Not ($raw)) {
        $raw = "$($RmAPI.VariableStr('s_RawPath'))"
    } else {
        $RmAPI.Bang("[!WriteKeyValue Variables s_RawPath `"$raw`" ]")
    }

    $skinspath = "$($RmAPI.VariableStr('SKINSPATH'))"

    $dynamicVariableFile = $raw -replace "$([Regex]::Escape($skinspath))",""
    $pattern = '(.*?)\\(.*)\\(.*?)$'

    $dynamicVariableFile -match $pattern
    foreach($match in $Matches) {

        $bangs = '[!WriteKeyValue Variables s_DynamicVariableFile "' + "$($Matches[0])" + '"]'
        $bangs += '[!WriteKeyValue Variables s_Skin "' + "$($Matches[1])" + '"]'
        $bangs += '[!WriteKeyValue Variables s_DynamicVariableDirectory "' + "$($Matches[2])" + '"]'

        # $RmAPI.Log("$bangs")
        $RmAPI.Bang("$bangs")
        $RmAPI.Bang("[!Refresh]")

    }

    if($generate -eq 1) {
        $RmAPI.Bang("[!Refresh][!Delay 100][!CommandMeasure Generator Construct]")
    }

}
