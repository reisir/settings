[Var{Index}]
Meter=String
Text={Name}
MeterStyle=VarTitle
[Var{Index}Description]
Meter=String
Text={Description}
MeterStyle=VarDescription
[Value{Index}]
Meter=String
Text={CurrentValue}
MeterStyle=VarStringValue
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
InputNumber=1
DynamicVariables=1
DefaultValue="Give new value"
Command1=[!SetOption "Value{Index}" Text "$UserInput$"][!UpdateMeter "Value{Index}"][!Redraw]
