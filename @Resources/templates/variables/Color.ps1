param (
    [Parameter()]
    [System.Collections.Hashtable]
    $Variable,
    [Parameter()]
    [String]
    $SettingsFile
)

return @"
$(Title)

[VariableContainer$($Variable.Index)]
MeterStyle=VariableContainer | RightPanel
Meter=Image
H=([ColorVariableValue$($Variable.Index):H] > [ColorStringValue$($Variable.Index):H]) ? [ColorVariableValue$($Variable.Index):H] : [ColorStringValue$($Variable.Index):H]

[ColorVariableValue$($Variable.Index)]
Meter=Shape
Shape=Ellipse [#s_ColorSize],[#s_ColorSize],[#s_ColorSize],[#s_ColorSize] | Fill Color [#$($Variable.Key)] | StrokeWidth [#s_ColorStrokeWidth] | Extend Outline
Outline=Stroke Color [#s_ColorStrokeColor]
MeterStyle=VarColor
LeftMouseUpAction=[!CommandMeasure "RainRGB$($Variable.Index)" "Run"]
Container=VariableContainer$($Variable.Index)

[ColorStringValue$($Variable.Index)]
Meter=String
Text=[#$($Variable.Key)]
MeterStyle=VarString | VarColorString
$(FontFace)
LeftMouseUpAction=[!CommandMeasure "RainRGB$($Variable.Index)" "Run"]
Container=VariableContainer$($Variable.Index)

[RainRGB$($Variable.Index)]
Measure=Plugin
Plugin=RunCommand
Program=""#CURRENTPATH#addons\RainRGB4RunCommand.exe""
Parameter=""VarName=$($Variable.Key)" "FileName=$($SettingsFile)" "RefreshConfig=-1""
OutputType=ANSI
FinishAction=[#s_SaveScroll][!Refresh][#s_OnChangeAction]
"@
