param(
    [Parameter(Mandatory)]
    [System.Collections.Hashtable]
    $Variable,
    [Parameter(Mandatory)]
    [String]
    $SettingsFile
)

$Variable.Add('PSRadioButton', @{'Labels' = @(); 'Values' = @() })

$Variable.Options -split '\s*;\s*' | ForEach-Object {
    if ($_ -match ',') {
        $temp = $_ -split '\s*,\s*'
        $Variable.PSRadioButton.Labels += $temp[0]
        $Variable.PSRadioButton.Values += $temp[1]
    }
    else {
        $Variable.PSRadioButton.Labels += $_
        $Variable.PSRadioButton.Values += $_
    }
}

$ini = @"
$(Title)

"@

$i = 0
foreach ($label in $Variable.PSRadioButton.Labels) {
    $ini += @"
[RadioButton$($Variable.Index)$(Remove-Whitespace -String $label)]
Meter=String
Text=[[&Ternary:Ternary('[#$($Variable.Key)]', '=', '$($Variable.PSRadioButton.Values[$i])', '\xECCB', '\xECCA')]]
X=([#s_LeftPanelW]+[#s_VariableXPadding])
Y=[#s_VariableYPadding]R
FontSize=15
MeterStyle=ListIcon | RightPanel
Group=RadioButton$($Variable.Index)
DynamicVariables=1
LeftMouseUpAction=[!SetVariable $($Variable.Key) "$($Variable.PSRadioButton.Values[$i])"][!WriteKeyValue Variables $($Variable.Key) "$($Variable.PSRadioButton.Values[$i])" "$SettingsFile"][!UpdateMeterGroup "RadioButton$($Variable.Index)"][#s_SaveScroll][!Update][!Redraw][#s_OnChangeAction]

[RadioString$($Variable.Index)$(Remove-Whitespace -String $label)]
Meter=String
Text=$label
X=5R
Y=-1r
FontWeight=([&Ternary:Ternary('[#$($Variable.Key)]', '=', '$($Variable.PSRadioButton.Values[$i])', '600', '400')]=0 ? 400 : [&Ternary:Ternary('[#$($Variable.Key)]', '=', '$($Variable.PSRadioButton.Values[$i])', '600', '400')])
Padding=0,0,[#s_VariableXPadding],[#s_VariableYPadding]
MeterStyle=VarString | VarColorString
Group=RadioButton$($Variable.Index)
DynamicVariables=1
LeftMouseUpAction=[!SetVariable $($Variable.Key) "$($Variable.PSRadioButton.Values[$i])"][!WriteKeyValue Variables $($Variable.Key) "$($Variable.PSRadioButton.Values[$i])" "$SettingsFile"][!UpdateMeterGroup "RadioButton$($Variable.Index)"][#s_SaveScroll][!Update][!Redraw][#s_OnChangeAction]


"@
    $i++
}

return $ini