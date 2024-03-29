[FirstRight]
Meter=Image
MeterStyle=FirstItem | FirstRightPanel
Y=([#s_ScrollRight] + [#s_TopHeight])
SolidColor=0,0,0,0
W=0
H=0

[CategoryIcon11]
Meter=String
Text=
MeterStyle=CategoryIcon | RightPanel

[Title11]
Meter=String
Text=Category list
MeterStyle=CategoryTitle
W=([#s_RightPanelW] - [CategoryIcon11:W])

[CategoryDescription11]
Meter=String
Text=
MeterStyle=VarDescription | ThickDescription | RightPanel

[CategoryTitleSeparator11]
Meter=Image
MeterStyle=CategoryTitleSeparator | RightPanel

[LastRight]
Meter=String
Text=Last
FontColor=255,0,0,0
MeterStyle=LastItem | RightPanel

[ScrollDownRight]
Measure=Calc
Formula=[#s_ScrollRight] - [#s_ScrollSpeed]
IfCondition=([LastRight:Y] > [#s_PanelH])
IfTrueAction=[!SetVariable "s_ScrollRight" "[&ScrollDownRight]"][!DisableMeasure "ScrollDownRight"][!Update][#s_SaveScroll]
IfFalseAction=[!DisableMeasure "ScrollDownRight"]
IfConditionMode=1
Disabled=1
DynamicVariables=1

[ScrollUpRight]
Measure=Calc
Formula=[#s_ScrollRight] + [#s_ScrollSpeed]
IfCondition=([FirstRight:Y] < [#s_TopHeight])
IfTrueAction=[!SetVariable "s_ScrollRight" "[&ScrollUpRight]"][!DisableMeasure "ScrollUpRight"][!Update][#s_SaveScroll]
IfFalseAction=[!DisableMeasure "ScrollUpRight"]
IfConditionMode=1
Disabled=1
DynamicVariables=1


