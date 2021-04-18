[Var{Index}Title]
Meter=String
Text={Name}
MeterStyle=VarTitle | {Container}
[Var{Index}Description]
Meter=String
Text={Description}
MeterStyle=VarDescription | {Container}
[ColorValue{Index}]
Meter=Shape
Shape=Ellipse [#s_ColorSize],[#s_ColorSize],[#s_ColorSize],[#s_ColorSize] | Fill Color [#{Key}] | StrokeWidth [#s_ColorStrokeWidth] | Stroke Color [#s_ColorStrokeColor]
MeterStyle=VarColorValue | {Container}
LeftMouseUpAction=[!CommandMeasure "RainRGB{Index}" "Run"][!Log "Picking colour {Key}"]
Hidden={Hidden}
[StringValue{Index}]
Meter=String
Text=[#{Key}]
MeterStyle=VarStringValue | VarColorString | {Container}
LeftMouseUpAction=[!CommandMeasure "RainRGB{Index}" "Run"][!Log "Picking colour {Key}"]
Hidden={Hidden}
[RainRGB{Index}]
Measure=Plugin
Plugin=RunCommand
Disabled={Hidden}
Program=""#CURRENTPATH#addons\RainRGB4RunCommand.exe""
Parameter=""VarName={Key}" "FileName={SettingsFile}" "RefreshConfig=-1""
OutputType=ANSI
FinishAction=[!Refresh]

