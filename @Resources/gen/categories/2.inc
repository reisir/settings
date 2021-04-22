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
[CategoryTitleSeparator1]
Meter=Image
MeterStyle=CategoryTitleSeparator | RightPanel
H=([#s_CategoryTitleBottomPadding] / 2)

[Var6]
Meter=String
Text=1. Formatting
MeterStyle=VarTitle | RightPanel
[Var6Description]
Meter=String
Text=For Settings to correctly parse your variables, you need to format the variable file.
MeterStyle=VarDescription | RightPanel
W=([#s_GeneratorRightPanelWidth] - [#s_VariableXPadding] * 2)
[Value6]
Meter=String
Text=RainDoc documentation
MeterStyle=VarStringValue | Link1 | RightPanel
LeftMouseUpAction=["https://github.com/sceleri/settings/wiki"]

[Var3]
Meter=String
Text=2. Generating
MeterStyle=VarTitle | RightPanel
[Value7]
Meter=String
Text=Drag & Drop your variable file on this skin.
MeterStyle=VarStringValue | Link0 | RightPanel
[Value8]
Meter=String
Text=Click on "Generate & Inject".
MeterStyle=VarStringValue | Link0 | RightPanel
; [Var0Description]
; Meter=String
; Text=
; MeterStyle=VarDescription | RightPanel
; [Var1Description]
; Meter=String
; Text=
; MeterStyle=VarDescription | RightPanel