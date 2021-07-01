param (
    [Parameter()]
    [System.Collections.Hashtable]
    $Variable,
    [Parameter()]
    [System.Collections.Hashtable]
    $Options
)

$ini = @"

[VariableIcon$($Options.Index)]
Meter=String
Text=$($Variable.Properties.Icon)
MeterStyle=VariableIcon | $($Options.Container)

[VariableTitle$($Options.Index)]
Meter=String
Text=$($Variable.Properties.Name)
MeterStyle=VarTitle | $($Options.Container)

[VariableDescription$($Options.Index)]
Meter=String
Text=$($Variable.Properties.Description)
MeterStyle=VarDescription | $($Options.Container)

[VariableVariableValue$($Options.Index)]
Meter=String
Text=[#$($Variable.Key)]
MeterStyle=VarStringValue | $($Options.Container)
LeftMouseUpAction=[!CommandMeasure "InputText$($Options.Index)" "ExecuteBatch All"][!SetOption #CURRENTSECTION# FontColor "0,0,0,0"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[InputText$($Options.Index)]
Measure=Plugin
Plugin=InputText
SolidColor=[#s_RightPanelBackgroundColor]
FontColor=#s_FontColor#
FontFace=#s_FontFace#
FontSize=#s_InputTextFontSize#
X=([VariableVariableValue$($Options.Index):X])
Y=([VariableVariableValue$($Options.Index):Y] + [#s_ValueYPadding])
H=[VariableVariableValue$($Options.Index):H]
W=([#s_RightPanelW] - ([#s_VariableXPadding] * 2))
DynamicVariables=1
DefaultValue=[#$($Variable.Key)]
Command1=[!WriteKeyValue "Variables" "$($Variable.Key)" "`$UserInput`$" "$($Options.SettingsFile)"][!Refresh][#s_OnChangeAction]
OnDismissAction=[!SetOption VariableVariableValue$($Options.Index) FontColor "[#s_FontColor]"][!UpdateMeter VariableVariableValue$($Options.Index)][!Redraw]


"@



return $ini