[FirstRightPanel]
Meter=String
Text=First
FontColor=0,0,0,0
MeterStyle=FirstItem | RightPanel
Y=[#s_ScrollRightPanel]

[CategoryIcon1]
Meter=String
Text=
MeterStyle=CategoryIcon | RightPanel
Padding=[#s_CategoryTitleXPadding],[#s_CategoryTitleXPadding],0,0
Y=0
[Title1]
Meter=String
Text=Instructions
MeterStyle=CategoryTitle | RightPanel
W=([#s_RightPanelW] - [CategoryIcon1:W])
Padding=0,[#s_CategoryTitleXPadding],0,0

[CategoryDescription1]
Meter=String
Text=For Settings to correctly parse your variables, you need to format the variable file.
MeterStyle=VarDescription | RightPanel
W=([#s_GeneratorRightPanelWidth] - [#s_VariableXPadding] * 2)

[Value6]
Meter=String
Text=1. Read the RainDoc documentation
MeterStyle=VarStringValue | Link1 | RightPanel
LeftMouseUpAction=["https://github.com/sceleri/settings/wiki"]

[Value7]
Meter=String
Text=2. Drag & Drop your formatted variable file on this skin
MeterStyle=VarStringValue | Link0 | RightPanel
W=([#s_GeneratorRightPanelWidth] - [#s_VariableXPadding] * 2)
[Value8]
Meter=String
Text=3. Click on "Generate & Inject".
MeterStyle=VarStringValue | Link0 | RightPanel
W=([#s_GeneratorRightPanelWidth] - [#s_VariableXPadding] * 2)

[VariableIcon2]
Meter=String
Text=[\xE835]
MeterStyle=VariableIcon | RightPanel
FontSize=14
Y=5R
[Var2]
Meter=String
Text=Example variable file
MeterStyle=VarTitle | RightPanel
Y=-6r
[Var2Description]
Meter=String
Text=
MeterStyle=VarDescription | RightPanel
W=([#s_GeneratorRightPanelWidth] - [#s_VariableXPadding] * 2)
[Value2]
Meter=String
Text=Change to and open the example file
MeterStyle=VarStringValue | RightPanel
W=([#s_GeneratorRightPanelWidth] - [#s_VariableXPadding])
LeftMouseUpAction=[!SetVariable "s_RawPath" "#@#example.inc"][!WriteKeyValue Variables "s_RawPath" "#@#example.inc"][!WriteKeyValue Variables "s_Type" "inc"][#s_FileChangeAction]

