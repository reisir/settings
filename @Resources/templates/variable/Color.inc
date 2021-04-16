[Var{Index}Title]
Meter=String
Text={Name}
MeterStyle=VarTitle | {Container}
[Var{Index}Description]
Meter=String
Text={Description}
MeterStyle=VarDescription | {Container}
[Value{Index}]
Meter=Shape
Shape=Ellipse 20,20,20,20 | Fill Color [#{RealName}] | StrokeWidth 2 | Stroke Color 0,0,0
MeterStyle=VarColorValue | {Container}
LeftMouseUpAction=["#CURRENTPATH#addons\RainRGB4.exe" "VarName={RealName}" "FileName={SettingsFile}" "RefreshConfig=#CURRENTCONFIG#"][!Log "Picking colour {RealName}"]
SolidColor=255,0,0

