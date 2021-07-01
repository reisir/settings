param (
    [Parameter()]
    [System.Collections.Hashtable]
    $Variable,
    [Parameter()]
    [System.Collections.Hashtable]
    $Options
)

$ini = @"
[VariableIcon$($Variable.Index)]
Meter=String
Text=$($Variable.Icon)
MeterStyle=VariableIcon | $($Options.Container)

[VariableTitle$($Variable.Index)Title]
Meter=String
Text=$($Variable.Name)
MeterStyle=VarTitle | $($Options.Container)

[VariableDescription$($Variable.Index)]
Meter=String
Text=$($Variable.Description)
MeterStyle=VarDescription | $($Options.Container)

[ColorVariableValue$($Variable.Index)]
Meter=Shape
Shape=Ellipse [#s_ColorSize],[#s_ColorSize],[#s_ColorSize],[#s_ColorSize] | Fill Color [#$($Variable.Key)] | StrokeWidth [#s_ColorStrokeWidth] | Extend Outline
Outline=Stroke Color [#s_ColorStrokeColor]
MeterStyle=VarColorValue | $($Options.Container)
LeftMouseUpAction=[!CommandMeasure "RainRGB$($Variable.Index)" "Run"]

[StringVariableValue$($Variable.Index)]
Meter=String
Text=[#$($Variable.Key)]
MeterStyle=VarStringValue | VarColorString | $($Options.Container)
LeftMouseUpAction=[!CommandMeasure "RainRGB$($Variable.Index)" "Run"]

[RainRGB$($Variable.Index)]
Measure=Plugin
Plugin=RunCommand
Program=""#CURRENTPATH#addons\RainRGB4RunCommand.exe""
Parameter=""VarName=$($Variable.Key)" "FileName=$($Options.SettingsFile)" "RefreshConfig=-1""
OutputType=ANSI
FinishAction=[!Refresh][#s_OnChangeAction]


"@

return $ini