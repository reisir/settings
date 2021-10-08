param (
    [Parameter()]
    [String]
    $Side
)

$ini = @"
[Last$($Side)]
Meter=String
Text=Last
FontColor=255,0,0,0
MeterStyle=LastItem | $($Side)Panel

[ScrollDown$($Side)]
Measure=Calc
Formula=[#s_Scroll$($Side)] - [#s_ScrollSpeed]
IfCondition=([Last$($Side):Y] > [#s_PanelH])
IfTrueAction=[!SetVariable "s_Scroll$($Side)" "[&ScrollDown$($Side)]"][!DisableMeasure "ScrollDown$($Side)"][!Update][#s_Save$($side)Scroll]
IfFalseAction=[!DisableMeasure "ScrollDown$($Side)"]
IfConditionMode=1
Disabled=1
DynamicVariables=1

[ScrollUp$($Side)]
Measure=Calc
Formula=[#s_Scroll$($Side)] + [#s_ScrollSpeed]
IfCondition=([First$($Side):Y] < [#s_TopHeight])
IfTrueAction=[!SetVariable "s_Scroll$($Side)" "[&ScrollUp$($Side)]"][!DisableMeasure "ScrollUp$($Side)"][!Update][#s_Save$($side)Scroll]
IfFalseAction=[!DisableMeasure "ScrollUp$($Side)"]
IfConditionMode=1
Disabled=1
DynamicVariables=1


"@

return $ini
