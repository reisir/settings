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
Text=Themes
MeterStyle=CategoryTitle | RightPanel
W=([#s_RightPanelW] - [CategoryIcon1:W])
Padding=0,[#s_CategoryTitleXPadding],0,0
[CategoryDescription1]
Meter=String
Text=Change theme names in Internal variables
MeterStyle=VarDescription | RightPanel
[CategoryTitleSeparator1]
Meter=Image
MeterStyle=CategoryTitleSeparator | RightPanel
H=([#s_CategoryTitleBottomPadding] / 2)

[VariableIcon0]
Meter=String
Text=
MeterStyle=VariableIcon | RightPanel
[Var0]
Meter=String
Text=Light theme
MeterStyle=VarTitle | RightPanel
[Var0Description]
Meter=String
Text=
MeterStyle=VarDescription | RightPanel
W=([#s_GeneratorRightPanelWidth] - [#s_VariableXPadding] * 2)
[Value0]
Meter=String
Text=Edit theme 1: [#s_Theme0Name]
MeterStyle=VarStringValue | RightPanel
W=([#s_GeneratorRightPanelWidth] - [#s_VariableXPadding])
LeftMouseUpAction=[!SetVariable "s_SettingsTheme" "0"][!WriteKeyValue Variables "s_SettingsTheme" "0" "#@#includes\Variables.inc"][!SetVariable "s_RawPath" "#@#includes\themes\0.inc"][!WriteKeyValue Variables "s_RawPath" "#@#includes\themes\0.inc"][!WriteKeyValue Variables "s_Type" "inc"][#s_FileChangeAction]

[VariableIcon1]
Meter=String
Text=
MeterStyle=VariableIcon | RightPanel
[Var1]
Meter=String
Text=Dark theme
MeterStyle=VarTitle | RightPanel
[Var1Description]
Meter=String
Text=
MeterStyle=VarDescription | RightPanel
W=([#s_GeneratorRightPanelWidth] - [#s_VariableXPadding] * 2)
[Value1]
Meter=String
Text=Edit theme 2: [#s_Theme1Name]
MeterStyle=VarStringValue | RightPanel
W=([#s_GeneratorRightPanelWidth] - [#s_VariableXPadding])
LeftMouseUpAction=[!SetVariable "s_SettingsTheme" "1"][!WriteKeyValue Variables "s_SettingsTheme" "1" "#@#includes\Variables.inc"][!SetVariable "s_RawPath" "#@#includes\themes\1.inc"][!WriteKeyValue Variables "s_RawPath" "#@#includes\themes\1.inc"][!WriteKeyValue Variables "s_Type" "inc"][#s_FileChangeAction]

[VariableIcon2]
Meter=String
Text=
MeterStyle=VariableIcon | RightPanel
[Var2]
Meter=String
Text=Slim theme
MeterStyle=VarTitle | RightPanel
[Var2Description]
Meter=String
Text=
MeterStyle=VarDescription | RightPanel
W=([#s_GeneratorRightPanelWidth] - [#s_VariableXPadding] * 2)
[Value2]
Meter=String
Text=Edit theme 3: [#s_Theme2Name]
MeterStyle=VarStringValue | RightPanel
W=([#s_GeneratorRightPanelWidth] - [#s_VariableXPadding])
LeftMouseUpAction=[!SetVariable "s_SettingsTheme" "2"][!WriteKeyValue Variables "s_SettingsTheme" "2" "#@#includes\Variables.inc"][!SetVariable "s_RawPath" "#@#includes\themes\2.inc"][!WriteKeyValue Variables "s_RawPath" "#@#includes\themes\2.inc"][!WriteKeyValue Variables "s_Type" "inc"][#s_FileChangeAction]

