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
[VariableValue{Index}]
Meter=String
Text=[#{Key}]
MeterStyle=VarStringValue | {Container}
LeftMouseUpAction=[!CommandMeasure "InputText{Index}" "ExecuteBatch All"][!SetOption VariableValue{Index} FontColor "0,0,0,0"][!UpdateMeter VariableValue{Index}][!Redraw]
Hidden={Hidden}
[InputText{Index}]
Measure=Plugin
Plugin=InputText
SolidColor=[#s_RightPanelBackgroundColor]
FontColor=[#s_FontColor]
FontFace=[#s_FontFace]
FontSize=[#s_InputTextFontSize]
Disabled={Hidden}
X=([VariableValue{Index}:X] + [#s_VariableXPadding])
Y=([VariableValue{Index}:Y] + [#s_ValueYPadding])
H=[VariableValue{Index}:H]
W=([#s_RightPanelW] - ([#s_VariableXPadding] * 2))
DynamicVariables=1
DefaultValue=[#{Key}]
Command1=[!WriteKeyValue "Variables" "{Key}" "$UserInput$" "{SettingsFile}"][!Refresh][#s_OnChangeAction]
OnDismissAction=[!SetOption VariableValue{Index} FontColor "[#s_FontColor]"][!UpdateMeter VariableValue{Index}][!Redraw]
InputNumber=1

