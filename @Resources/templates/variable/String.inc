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
Text={CurrentValue}
MeterStyle=VarStringValue | {Container}
LeftMouseUpAction=[!CommandMeasure "InputText{Index}" "ExecuteBatch 1"]
[InputText{Index}]
Measure=Plugin
Plugin=InputText
SolidColor=#s_RightPanelBackgroundColor#
FontColor=#s_FontColor#
FontFace=#s_FontFace#
FontSize=#s_InputTextFontSize#
X=([Value{Index}:X] + [#s_VariableLeftPadding])
Y=([Value{Index}:Y] + [#s_VariablePadding])
H=[Value{Index}:H]
W=([RightPanelContainer:W] - ([Value{Index}:X] * 2))
DynamicVariables=1
DefaultValue="Give new value"
Command1=[!WriteKeyValue Variables "{RealName}" "$UserInput$" "{SettingsFile}"][!SetOption "Value{Index}" Text "$UserInput$"][!UpdateMeter "Value{Index}"][!Redraw]
