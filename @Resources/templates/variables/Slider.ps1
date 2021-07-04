param(
    [Parameter(Mandatory)]
    [hashtable]
    $Variable,
    [Parameter(Mandatory)]
    [string]
    $SettingsFile
)

$string=@"
$(Title)

[MeasureMouse$($Variable.Index)]
Measure=Plugin
Plugin=Mouse
LeftMouseDragAction=[!SetOption SliderAnchor$($Variable.Index) X "(Clamp(`$MouseX$,[#s_LeftPanelW]+[#s_VariableXPadding]+10,[#s_LeftPanelW]+[#s_VariableXPadding]+10+200))"][!UpdateMeter SliderAnchor$($Variable.Index)][!UpdateMeasure MousePercentage$($Variable.Index)]
LeftMouseUpAction=!CommandMeasure MeasureMouse$($Variable.Index) "Stop"
RelativeToSkin=1
RequireDragging=1
DynamicVariables=1
[MousePercentage$($Variable.Index)]
Measure=Calc
Formula=([SliderAnchor$($Variable.Index):X]-[#s_LeftPanelW]-[#s_VariableXPadding]-10)/200
DynamicVariables=1
OnChangeAction=[!SetVariable $($Variable.Key) "(Ceil($($Variable.MaxValue)*[MousePercentage$($Variable.Index)]))"][!WriteKeyValue Variables $($Variable.Key) "(Ceil($($Variable.MaxValue)*[MousePercentage$($Variable.Index)]))" "$SettingsFile"][!UpdateMeterGroup "Sliders$($Variable.Index)"][!Redraw]
[SliderBar$($Variable.Index)]
Meter=Shape
X=([#s_LeftPanelW]+[#s_VariableXPadding]+10)
Y=[#s_VariableYPadding]R
Shape=Rectangle 1,5,200,5,3 | StrokeWidth 0 | Fill Color 303030
Shape2=Rectangle 0,5,(201*([#$($Variable.Key)]/$($Variable.MaxValue))),5,2.5 | StrokeWidth 0 | Fill Color FEFEFE
DynamicVariables=1
Group=Sliders$($Variable.Index)
[SliderAnchor$($Variable.Index)]
Meter=Shape
X=([#s_LeftPanelW]+[#s_VariableXPadding]+10+200*([#$($Variable.Key)]/$($Variable.MaxValue)))
Y=r
Shape=Ellipse 2.5, 7.5, 7,7 | StrokeWidth 0 | Fill Color FEFEFE
Shape2=Ellipse 2.5, 7.5, 4,4 | StrokeWidth 0 | Fill Color 303030
DynamicVariables=1
Group=Sliders$($Variable.Index)
LeftMouseDownAction=!CommandMeasure MeasureMouse$($Variable.Index) "Start"
[SliderValue$($Variable.Index)]
Meter=String
X=([#s_LeftPanelW]+[#s_VariableXPadding]+10+215)
Y=7.5r
FontSize=12
Text=[#$($Variable.Key)]
StringAlign=LeftCenter
Padding=0,0,0,0
W=80
MeterStyle=VarString | VarColorString
DynamicVariables=1
Group=Sliders$($Variable.Index)

"@

return $string