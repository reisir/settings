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

[Title1]
Meter=String
Text=Instructions
MeterStyle=CategoryTitle | RightPanel
W=([#s_RightPanelW] - [CategoryIcon1:W])

[CategoryDescription1]
Meter=String
Text=
MeterStyle=VarDescription | RightPanel

[CategoryTitleSeparator1]
Meter=Image
MeterStyle=CategoryTitleSeparator | RightPanel

[Var0]
Meter=String
Text=File selection
MeterStyle=VarTitle | RightPanel
[Value0]
Meter=String
Text=Drag & Drop your variable file on this skin.
MeterStyle=VarStringValue | RightPanel
Hidden=
W=([#s_GeneratorRightPanelWidth] - [#s_VariableXPadding])
MouseOverAction=

[Var1]
Meter=String
Text=Usage
MeterStyle=VarTitle | RightPanel
[Value1]
Meter=String
Text=Move the "settings" directory from "Settings" to your skins root folder.
MeterStyle=VarStringValue | RightPanel
Hidden=
W=([#s_GeneratorRightPanelWidth] - [#s_VariableXPadding] * 2)
MouseOverAction=


