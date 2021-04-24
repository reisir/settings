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
Text=Settings settings
MeterStyle=CategoryTitle | RightPanel
W=([#s_RightPanelW] - [CategoryIcon1:W])
Padding=0,[#s_CategoryTitleXPadding],0,0
[CategoryDescription1]
Meter=String
Text=
MeterStyle=VarDescription | RightPanel
[CategoryTitleSeparator1]
Meter=Image
MeterStyle=CategoryTitleSeparator | RightPanel
H=([#s_CategoryTitleBottomPadding] / 2)

[VariableIcon0]
Meter=String
Text=[\xE9E9]
MeterStyle=VariableIcon | RightPanel
FontSize=14
[Var0]
Meter=String
Text=Internal variables  
MeterStyle=VarTitle | RightPanel
Y=-6r
[Var0Description]
Meter=String
Text=
MeterStyle=VarDescription | RightPanel
W=([#s_GeneratorRightPanelWidth] - [#s_VariableXPadding] * 2)
[Value0]
Meter=String
Text=Change to internal variable file
MeterStyle=VarStringValue | RightPanel
W=([#s_GeneratorRightPanelWidth] - [#s_VariableXPadding])
LeftMouseUpAction=[!SetVariable "s_RawPath" "#@#includes\Variables.inc"][!WriteKeyValue Variables "s_RawPath" "#@#includes\Variables.inc"][!WriteKeyValue Variables "s_Type" "inc"][#s_FileChangeAction]

[VariableIcon1]
Meter=String
Text=[\xE9F3]
MeterStyle=VariableIcon | RightPanel
FontSize=14
Y=5R
[Var1]
Meter=String
Text=OnChangeAction
MeterStyle=VarTitle | RightPanel
Y=-6r
[Var1Description]
Meter=String
Text=Ran everytime a variable is changed.
MeterStyle=VarDescription | RightPanel
W=([#s_GeneratorRightPanelWidth] - [#s_VariableXPadding] * 2)
[Value1]
Meter=String
Text=Open s_OnChangeAction.inc
MeterStyle=VarStringValue | RightPanel
W=([#s_GeneratorRightPanelWidth] - [#s_VariableXPadding])
LeftMouseUpAction=["#@#includes\s_OnChangeAction.inc"]

