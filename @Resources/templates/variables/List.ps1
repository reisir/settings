param(
    [Parameter(Mandatory)]
    [System.Collections.Hashtable]
    $Variable,
    [Parameter(Mandatory)]
    [String]
    $SettingsFile
)

$Variable.Add('PSList', @{'Labels' = @(); 'Values' = @() })

$Variable.Options -split '\s*;\s*' | ForEach-Object {
    if ($_ -match ',') {
        $temp = $_ -split '\s*,\s*'
        $Variable.PSList.Labels += $temp[0]
        $Variable.PSList.Values += $temp[1]
    }
    else {
        $Variable.PSList.Labels += $_
        $Variable.PSList.Values += $_
    }
}

$ini = @"
$(Title)

"@

$i = 0

foreach ($label in $Variable.PSList.Labels) {
    $ini += @"

[ListCheck$($Variable.Index)$(Remove-Whitespace -String $label)]
Meter=String
Text=[&MainLua:Ternary('[#$($Variable.PSList.Values[$i])]', '=', '1', '[\xE73A]', '[\xE739]')]
X=([#s_LeftPanelW]+[#s_VariableXPadding])
Y=[#s_VariableYPadding]R
FontSize=15
MeterStyle=ListIcon | RightPanel
Group=List$($Variable.Index)
DynamicVariables=1
LeftMouseUpAction=[!SetVariable $($Variable.PSList.Values[$i]) "(1-[#$($Variable.PSList.Values[$i])])"][!WriteKeyValue Variables $($Variable.PSList.Values[$i]) "[#$($Variable.PSList.Values[$i])]" "$SettingsFile"][#s_SaveScroll][!Update][!Redraw][&MainLua:OnChangeAction()]

[ListString$($Variable.Index)$(Remove-Whitespace -String $label)]
Meter=String
Text=$label
X=5R
Y=-1r
Padding=0,0,[#s_VariableXPadding],[#s_VariableYPadding]
MeterStyle=VarString
Group=List$($Variable.Index)
LeftMouseUpAction=[!SetVariable $($Variable.PSList.Values[$i]) "(1-[#$($Variable.PSList.Values[$i])])"][!WriteKeyValue Variables $($Variable.PSList.Values[$i]) "[#$($Variable.PSList.Values[$i])]" "$SettingsFile"][#s_SaveScroll][!Update][!Redraw][&MainLua:OnChangeAction()]


"@
    $i++
}

return $ini