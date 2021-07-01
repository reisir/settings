param (
    [Parameter()]
    [System.Collections.Hashtable]
    $Variable,
    [Parameter()]
    [System.Collections.Hashtable]
    $Options
)

$ini = @"
[VariableIcon$($Options.Index)]
Meter=String
Text=$($Variable.Properties.Icon)
MeterStyle=VariableIcon | $($Options.Container)

[VariableTitle$($Options.Index)Title]
Meter=String
Text=$($Variable.Properties.Name)
MeterStyle=VarTitle | $($Options.Container)

[VariableDescription$($Options.Index)]
Meter=String
Text=$($Variable.Properties.Description)
MeterStyle=VarDescription | $($Options.Container)

[ColorVariableValue$($Options.Index)]
Meter=Shape
Shape=Ellipse [#s_ColorSize],[#s_ColorSize],[#s_ColorSize],[#s_ColorSize] | Fill Color [#$($Variable.Key)] | StrokeWidth [#s_ColorStrokeWidth] | Extend Outline
Outline=Stroke Color [#s_ColorStrokeColor]
MeterStyle=VarColorValue | $($Options.Container)
LeftMouseUpAction=[!CommandMeasure "RainRGB$($Options.Index)" "Run"]

[StringVariableValue$($Options.Index)]
Meter=String
Text=[#$($Variable.Key)]
MeterStyle=VarStringValue | VarColorString | $($Options.Container)
LeftMouseUpAction=[!CommandMeasure "RainRGB$($Options.Index)" "Run"]

[RainRGB$($Options.Index)]
Measure=Plugin
Plugin=RunCommand
Program=""#CURRENTPATH#addons\RainRGB4RunCommand.exe""
Parameter=""VarName=$($Variable.Key)" "FileName=$($Options.SettingsFile)" "RefreshConfig=-1""
OutputType=ANSI
FinishAction=[!Refresh][#s_OnChangeAction]


"@

return $ini