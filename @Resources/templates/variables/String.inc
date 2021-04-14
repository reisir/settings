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
LeftMouseUpAction=!CommandMeasure "InputText{Index}" "ExecuteBatch 1"
[InputText{Index}]
Measure=Plugin
Plugin=InputText
SolidColor=#s_RightPanelBackgroundColor#
FontColor=#s_FontColor#
FontFace=#s_FontFace#
FontSize=[Value{Index}:FontSize]
X=[Value{Index}:X]
Y=[Value{Index}:Y]
H=[Value{Index}:H]
W=[Value{Index}:W]
DynamicVariables=1
DefaultValue="Give new value"
Command1=[!SetOption "Value{Index}" Text "$UserInput$"][!UpdateMeter "Value{Index}"][!Redraw]
