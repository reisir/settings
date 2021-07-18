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
[Title0]
Meter=String
Text=Instructions
MeterStyle=GenTitle
W=([#s_RightPanelW] - [CategoryIcon0:W])
Padding=0,0,0,0
[CategoryDescription0]
Meter=String
Text=For Settings to correctly parse your variables, you need to format the variable file.
MeterStyle=RightPanel | GenDesc | ThickDescription
[CategoryTitleSeparator0]
Meter=Image
MeterStyle=RightPanel | GenSeparator

[Value6]
Meter=String
Text=1. Read the RainDoc documentation
MeterStyle=RightPanel | GenString | Link1
LeftMouseUpAction=["https://github.com/sceleri/settings/wiki"]

[Value7]
Meter=String
Text=2. Drag & Drop your formatted variable file on this skin
MeterStyle=RightPanel | GenString | Link0

[Value8]
Meter=String
Text=3. Click on "Generate & Inject".
MeterStyle=RightPanel | GenString | Link0

[VarIcon2]
Meter=String
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
Text=Change to the example file
MeterStyle=RightPanel | VarString | GenString
LeftMouseUpAction=[!SetVariable "s_RawPath" "#@#example.inc"][!WriteKeyValue Variables "s_RawPath" "#@#example.inc"][!WriteKeyValue Variables "s_Type" "inc"][#s_FileChangeAction]

