[Var{Index}]
Meter=String
Text={Name}
MeterStyle=VarTitle | {Container}
[Var{Index}Description]
Meter=String
Text={Description}
MeterStyle=VarDescription | {Container}
[Value{Index}]
Meter=String
Text=[#{Key}]
MeterStyle=VarStringValue | {Container}
LeftMouseUpAction=[!CommandMeasure "InputText{Index}" "ExecuteBatch All"][!Log "InputText{Index}"]
Hidden={Hidden}
[InputText{Index}]
Measure=Plugin
Plugin=InputText
SolidColor=#s_RightPanelBackgroundColor#
FontColor=#s_FontColor#
FontFace=#s_FontFace#
FontSize=#s_InputTextFontSize#
Disabled={Hidden}
X=([Value{Index}:X] + [#s_VariableXPadding])
Y=([Value{Index}:Y] + [#s_ValueYPadding])
H=[Value{Index}:H]
W=([RightPanelContainer:W] - ([Value{Index}:X] * 2))
DynamicVariables=1
DefaultValue="Give new value"
Command1=[!WriteKeyValue "Variables" "{Key}" "$UserInput$" "{SettingsFile}"][!Refresh]

