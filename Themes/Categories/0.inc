[FirstRight]
Meter=Image
MeterStyle=FirstItem | FirstRightPanel
Y=([#s_ScrollRight] + [#s_TopHeight])
SolidColor=0,0,0,0
W=0
H=0

[CategoryIcon0]
Meter=String
Text=
MeterStyle=CategoryIcon | RightPanel

[Title0]
Meter=String
Text=Theme: [#s_Theme1Name] 
MeterStyle=CategoryTitle
W=([#s_RightPanelW] - [CategoryIcon0:W])

[CategoryDescription0]
Meter=String
Text=Customize the theme here 
MeterStyle=VarDescription | ThickDescription | RightPanel

[CategoryTitleSeparator0]
Meter=Image
MeterStyle=CategoryTitleSeparator | RightPanel


[VarIcon0]
Meter=String
MeterStyle=VarIcon | RightPanel
Padding=[#s_VariableXPadding],[#s_VariableIconTopPadding],[#s_VariableIconGap],0
Hidden=1

[VariableTitle0]
Meter=String
MeterStyle=VarTitle
Text=
ClipStringW=([#s_RightPanelW] - ([#s_VariableXPadding] * 2) - [VarIcon0:W])
Padding=[#s_VariableXPadding],[#s_VariableYPadding],[#s_VariableXPadding],[#s_VariableYPadding]

FontFace=#s_FontFace#

[VariableDescription0]
Meter=String
MeterStyle=VarDescription | RightPanel
Text=Link test 
FontFace=#s_FontFace#
Y=(-[#s_VariableYPadding])R



[VariableValue0]
Meter=String
Text=GitHub
MeterStyle=VarString | RightPanel | Link1
FontFace=#s_FontFace#

LeftMouseUpAction=["https://GitHub.com/sceleri/settings"]

[MeasureLinkStatus0]
Measure=Calc
Formula=1
IfCondition=(0 = #CURRENTSECTION#)
IfTrueAction=[!DisableMouseAction VariableValue0 LeftMouseUpAction]

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


