param (
    [Parameter()]
    [System.Collections.Hashtable]
    $Variable,
    [Parameter()]
    [String]
    $SettingsFile
)

return @"
$(Title)

[VariableValue$($Variable.Index)]
Meter=String
Text=[#$($Variable.Key)]
MeterStyle=VarString | RightPanel
$(FontFace)
LeftMouseUpAction=[!CommandMeasure "InputText$($Variable.Index)" "ExecuteBatch All"][!SetOption #CURRENTSECTION# FontColor "0,0,0,0"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[InputText$($Variable.Index)]
Measure=Plugin
Plugin=InputText
SolidColor=[#s_RightPanelBackgroundColor]
FontColor=[#s_FontColor]
$(FontFace)
FontSize=[#s_InputTextFontSize]
X=([VariableValue$($Variable.Index):X] + [#s_VariableXPadding])
Y=([VariableValue$($Variable.Index):Y] + [#s_VariableYPadding])
H=[VariableValue$($Variable.Index):H]
W=([#s_RightPanelW] - ([#s_VariableXPadding] * 2))
DynamicVariables=1
DefaultValue=[#$($Variable.Key)]
Command1=[!WriteKeyValue "Variables" "$($Variable.Key)" "`$UserInput`$" "$($SettingsFile)"][#s_SaveScroll][!Refresh][&MainLua:OnChangeAction()]
OnDismissAction=[!SetOption VariableValue$($Variable.Index) FontColor "[#s_FontColor]"][!UpdateMeter VariableValue$($Variable.Index)][!Redraw]
InputNumber=1
"@
