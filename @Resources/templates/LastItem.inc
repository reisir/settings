[Last{Type}]
Meter=String
Text=Last
FontColor=0,0,0,0
MeterStyle=LastItem | {Container}

[ScrollDown{Type}]
Measure=Calc
Formula=[#s_Scroll] - [#s_ScrollSpeed]
IfCondition=([Last{Type}:Y] > ([#s_PanelH]))
IfTrueAction=[!SetVariable "s_Scroll" "[&ScrollDown{Type}]"][!DisableMeasure "ScrollDown{Type}"][!UpdateMeter "First{Type}"][!Redraw]
IfFalseAction=[!DisableMeasure "ScrollDown{Type}"][!UpdateMeter "First{Type}"][!Redraw]
IfConditionMode=1
Disabled=1
DynamicVariables=1

[ScrollUp{Type}]
Measure=Calc
Formula=[#s_Scroll] + [#s_ScrollSpeed]
IfCondition=([First{Type}:Y] < 0)
IfTrueAction=[!SetVariable "s_Scroll" "[&ScrollUp{Type}]"][!DisableMeasure "ScrollUp{Type}"][!UpdateMeter "First{Type}"][!Redraw]
IfFalseAction=[!DisableMeasure "ScrollUp{Type}"][!UpdateMeter "First{Type}"][!Redraw]
IfConditionMode=1
Disabled=1
DynamicVariables=1

