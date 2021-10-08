param (
    [Parameter()]
    [System.Collections.Hashtable]
    $Variable,
    [Parameter()]
    [String]
    $SettingsFile
)

$usedPlugins.CursorColor = $true
$usedPlugins.Mouse = $true

if (-not $Variable.Format) {
    $Variable.Format='rgb'
} elseif (@('rgb', 'rgba', 'hex', 'hexa') -notcontains $Variable.Format.ToLower()) {
    $Variable.Format='rgb'
} else {
    $Variable.Format=$Variable.Format.ToLower()
}

return @"
$(Title)

[VariableContainer$($Variable.Index)]
MeterStyle=VariableContainer | RightPanel
Meter=Image
H=([ColorVariableValue$($Variable.Index):H] > [ColorStringValue$($Variable.Index):H]) ? [ColorVariableValue$($Variable.Index):H] : [ColorStringValue$($Variable.Index):H]

[ColorVariableValueContainer$($Variable.Index)]
Meter=Shape
X=[#s_VariableXPadding]r
Y=r
Shape=Ellipse ([#s_ColorSize]+[#s_ColorStrokeWidth]),([#s_ColorSize]+[#s_ColorStrokeWidth]),([#s_ColorSize]+[#s_ColorStrokeWidth]) | Fill Color 200,200,200 | StrokeWidth [#s_ColorStrokeWidth]

[ColorTransparentBackground$($Variable.Index)]
Meter=Image
ImageName=#CURRENTPATH#Addons\TrpBg
H=([#s_ColorSize]*2)
W=([#s_ColorSize]*2)
Container=ColorVariableValueContainer$($Variable.Index)

[ColorVariableValue$($Variable.Index)]
Meter=Shape
X=0
Y=0
Shape=Ellipse ([#s_ColorSize]+[#s_ColorStrokeWidth]/2),([#s_ColorSize]+[#s_ColorStrokeWidth]/2),[#s_ColorSize],[#s_ColorSize] | Fill Color [#$($Variable.Key)] | StrokeWidth [#s_ColorStrokeWidth] | Extend Outline
Outline=Stroke Color [#s_ColorStrokeColor]
MeterStyle=VarColor
LeftMouseUpAction=[!CommandMeasure ColorPickerUI "SetColor('$($Variable.Key)', 'Variables', '$($Variable.Format)', [[$SettingsFile]])"]
Container=ColorVariableValueContainer$($Variable.Index)

[ColorStringValue$($Variable.Index)]
Meter=String
X=(2*[#s_ColorSize]+[#s_VariableXPadding]+10)
Text=[#$($Variable.Key)]
MeterStyle=VarString | VarColorString
$(FontFace)
LeftMouseUpAction=[!CommandMeasure ColorPickerUI "SetColor('$($Variable.Key)', 'Variables', '$($Variable.Format)', [[$SettingsFile]])"]
Container=VariableContainer$($Variable.Index)
"@
