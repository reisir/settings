[VariableIcon{Index}]
Meter=String
Text={Icon}
MeterStyle=VariableIcon | {Container}
Hidden={Hidden}
[VariableTitle{Index}]
Meter=String
Text={Name}
MeterStyle=VarTitle | {Container}
Hidden={Hidden}
[VariableDescription{Index}]
Meter=String
Text={Description}
MeterStyle=VarDescription | {Container}
Hidden={Hidden}
[VariableVariableValue{Index}]
Meter=String
Text=[#{Key}]
MeterStyle=VarStringValue | {Container}
LeftMouseUpAction=[!CommandMeasure "InputText{Index}" "ExecuteBatch All"][!SetOption #CURRENTSECTION# FontColor "0,0,0,0"][!UpdateMeter #CURRENTSECTION#][!Redraw]
Hidden={Hidden}
[InputText{Index}]
Measure=Plugin
Plugin=InputText
SolidColor=[#s_RightPanelBackgroundColor]
FontColor=#s_FontColor#
FontFace=#s_FontFace#
FontSize=#s_InputTextFontSize#
Disabled={Hidden}
X=([VariableVariableValue{Index}:X])
Y=([VariableVariableValue{Index}:Y] + [#s_ValueYPadding])
H=[VariableVariableValue{Index}:H]
W=([#s_RightPanelW] - ([#s_VariableXPadding] * 2))
DynamicVariables=1
DefaultValue=[#{Key}]
Command1=[!WriteKeyValue "Variables" "{Key}" "$UserInput$" "{SettingsFile}"][!Refresh][#s_OnChangeAction]
OnDismissAction=[!SetOption VariableVariableValue{Index} FontColor "[#s_FontColor]"][!UpdateMeter VariableVariableValue{Index}][!Redraw]

