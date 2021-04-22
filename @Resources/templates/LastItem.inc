[Last{Container}]
Meter=String
Text=Last
FontColor=255,0,0,0
MeterStyle=LastItem | {Container}

[ScrollDown{Container}]
Measure=Calc
Formula=[#s_Scroll{Container}] - [#s_ScrollSpeed]
IfCondition=([Last{Container}:Y] > [#s_ScrollTreshold])
IfTrueAction=[!SetVariable "s_Scroll{Container}" "[&ScrollDown{Container}]"][!DisableMeasure "ScrollDown{Container}"][!Update][!Redraw]
IfFalseAction=[!DisableMeasure "ScrollDown{Container}"]
IfConditionMode=1
Disabled=1
DynamicVariables=1

[ScrollUp{Container}]
Measure=Calc
Formula=[#s_Scroll{Container}] + [#s_ScrollSpeed]
IfCondition=([First{Container}:Y] < 0)
IfTrueAction=[!SetVariable "s_Scroll{Container}" "[&ScrollUp{Container}]"][!DisableMeasure "ScrollUp{Container}"][!Update][!Redraw]
IfFalseAction=[!DisableMeasure "ScrollUp{Container}"]
IfConditionMode=1
Disabled=1
DynamicVariables=1

