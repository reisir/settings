[FirstRightPanel]
Meter=String
Text=First
FontColor=0,0,0,0
MeterStyle=FirstItem | RightPanel
Y=[#s_ScrollRightPanel]
[CategoryIcon2]
Meter=String
Text=
MeterStyle=CategoryIcon | RightPanel

[Title2]
Meter=String
Text=Documentation 
MeterStyle=CategoryTitle | RightPanel
W=([#s_RightPanelW] - [CategoryIcon2:W])

[CategoryDescription2]
Meter=String
Text=Links to documentation
MeterStyle=VarDescription | RightPanel

[CategoryTitleSeparator2]
Meter=Image
MeterStyle=CategoryTitleSeparator | RightPanel

[Var0]
Meter=String
Text=RainDoc syntax
MeterStyle=VarTitle | RightPanel
[Var0Description]
Meter=String
Text=Includes quick-start guide.
MeterStyle=VarDescription | RightPanel
[Value0]
Meter=String
Text=https://github.com/sceleri/settings/wiki
MeterStyle=VarStringValue | Link1 | RightPanel
Hidden=
LeftMouseUpAction=["https://github.com/sceleri/settings/wiki"]

