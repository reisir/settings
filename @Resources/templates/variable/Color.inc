[VariableIcon{Index}]
Meter=String
Text={Icon}
MeterStyle=VariableIcon | {Container}
Hidden={Hidden}
[VariableTitle{Index}Title]
Meter=String
Text={Name}
MeterStyle=VarTitle | {Container}
Hidden={Hidden}
[VariableDescription{Index}]
Meter=String
Text={Description}
MeterStyle=VarDescription | {Container}
Hidden={Hidden}
[ColorVariableValue{Index}]
Meter=Shape
Shape=Ellipse [#s_ColorSize],[#s_ColorSize],[#s_ColorSize],[#s_ColorSize] | Fill Color [#{Key}] | StrokeWidth [#s_ColorStrokeWidth] | Extend Outline
Outline=Stroke Color [#s_ColorStrokeColor]
MeterStyle=VarColorValue | {Container}
LeftMouseUpAction=[!CommandMeasure "RainRGB{Index}" "Run"]
Hidden={Hidden}
[StringVariableValue{Index}]
Meter=String
Text=[#{Key}]
MeterStyle=VarStringValue | VarColorString | {Container}
LeftMouseUpAction=[!CommandMeasure "RainRGB{Index}" "Run"]
Hidden={Hidden}
[RainRGB{Index}]
Measure=Plugin
Plugin=RunCommand
Disabled={Hidden}
Program=""#CURRENTPATH#addons\RainRGB4RunCommand.exe""
Parameter=""VarName={Key}" "FileName={SettingsFile}" "RefreshConfig=-1""
OutputType=ANSI
FinishAction=[!Refresh][#s_OnChangeAction]
