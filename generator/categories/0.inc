[FirstRight]
Meter=Image
MeterStyle=FirstItem | FirstRightPanel
Y=([#s_GenTopHeight])
SolidColor=0,0,0,0
W=0
H=0

[CategoryIcon0]
Meter=String
Text=
MeterStyle=RightPanel | GenIcon
Padding=[#s_CategoryTitleXPadding],[#s_CategoryIconTopPadding],0,0
[Title0]
Meter=String
Text=Settings
MeterStyle=GenTitle
W=([#s_RightPanelW] - [CategoryIcon0:W])
Padding=0,0,0,0
[CategoryDescription0]
Meter=String
Text=a settings skin generator
MeterStyle=VarDescription | ThickDescription | RightPanel
[CategoryTitleSeparator0]
Meter=Image
MeterStyle=RightPanel | GenSeparator

[VarIcon1]
Meter=String
Y=20R
Text=[\xE7C3]
MeterStyle=RightPanel | GenSmallIcon
[Var1]
Meter=String
Text=Documentation
MeterStyle=RightPanel | GenSmallTitle
[Var1Description]
Meter=String
Text=
MeterStyle=RightPanel | GenDesc
[Value1]
Meter=String
Text=https://github.com/sceleri/settings/wiki
MeterStyle=RightPanel | GenString | Link1
LeftMouseUpAction=["https://github.com/sceleri/settings/wiki"]

[VarIcon2]
Meter=String
Y=15R
Text=[\xE835]
MeterStyle=RightPanel | GenSmallIcon
[Var2]
Meter=String
Text=Example variable file
MeterStyle=RightPanel | GenSmallTitle
[Var2Description]
Meter=String
Text=
MeterStyle=RightPanel | GenDesc
[Value2]
Meter=String
Text=Open
MeterStyle=RightPanel | VarString | GenString
LeftMouseUpAction=["#@#example.inc"]
