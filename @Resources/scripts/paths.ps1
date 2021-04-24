function Update {

}

function Paths {

    $raw = "$($RmAPI.VariableStr('s_RawPath'))"
    $skinspath = "$($RmAPI.VariableStr('SKINSPATH'))"

    $dynamicVariableFile = $raw -replace "$([Regex]::Escape($skinspath))",""
    $pattern = '(.*?)\\(.*)\\(.*?)$'

    $dynamicVariableFile -match $pattern
    foreach($match in $Matches) {
        # $match.GetEnumerator() | ForEach-Object {
        #     $RmAPI.Log("Match $($_.Key): $($_.Value)")
        # }

        $bangs = '[!WriteKeyValue Variables s_DynamicVariableFile "' + "$($Matches[0])" + '"]'
        $bangs += '[!WriteKeyValue Variables s_Skin "' + "$($Matches[1])" + '"]'
        $bangs += '[!WriteKeyValue Variables s_DynamicVariableDirectory "' + "$($Matches[2])" + '"]'

        # $RmAPI.Log("$bangs")
        $RmAPI.Bang("$bangs")
        $RmAPI.Bang("[!Refresh]")

    }

}