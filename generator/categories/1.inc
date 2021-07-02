[FirstRight]
Meter=String
Text=First
FontColor=0,0,0,0
MeterStyle=FirstItem | FirstRightPanel
Y=[#s_ScrollRight]

[CategoryIcon1]
Meter=String
Text=
MeterStyle=CategoryIcon | RightPanel
Padding=[#s_CategoryTitleXPadding],[#s_CategoryTitleXPadding],0,0
Y=0
[Title1]
Meter=String
Text=
MeterStyle=CategoryTitle | RightPanel
W=([#s_RightPanelW] - [CategoryIcon1:W])
Padding=0,[#s_CategoryTitleXPadding],0,0
[CategoryDescription1]
Meter=String
Text=The generated theme settings skins edit the original file so you'll have to regenerate to see the effects of your changes.
MeterStyle=VarDescription | RightPanel
W=([#s_GeneratorRightPanelWidth] - [#s_VariableXPadding] * 2)
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
Text=Themes:
MeterStyle=VarTitle | RightPanel
[Var0Description]
Meter=String
Text=
MeterStyle=VarDescription | RightPanel
W=([#s_GeneratorRightPanelWidth] - [#s_VariableXPadding] * 2)
[Value0]
Meter=String
Text=Change to theme: [#s_Theme0Name]
MeterStyle=VarStringValue | RightPanel
W=([#s_GeneratorRightPanelWidth] - [#s_VariableXPadding])
LeftMouseUpAction=[!SetVariable "s_SettingsTheme" "0"][!WriteKeyValue Variables "s_SettingsTheme" "0" "#@#includes\Variables.inc"][!SetVariable "s_RawPath" "#@#includes\themes\0.inc"][!WriteKeyValue Variables "s_RawPath" "#@#includes\themes\0.inc"][!WriteKeyValue Variables "s_Type" "inc"][#s_FileChangeAction]
Padding=0,0,0,0
[Value1]
Meter=String
Text=Change to theme: [#s_Theme1Name]
MeterStyle=VarStringValue | RightPanel
W=([#s_GeneratorRightPanelWidth] - [#s_VariableXPadding])
LeftMouseUpAction=[!SetVariable "s_SettingsTheme" "1"][!WriteKeyValue Variables "s_SettingsTheme" "1" "#@#includes\Variables.inc"][!SetVariable "s_RawPath" "#@#includes\themes\1.inc"][!WriteKeyValue Variables "s_RawPath" "#@#includes\themes\1.inc"][!WriteKeyValue Variables "s_Type" "inc"][#s_FileChangeAction]
Padding=0,0,0,0
[Value2]
Meter=String
Text=Change to theme: [#s_Theme2Name]
MeterStyle=VarStringValue | RightPanel
W=([#s_GeneratorRightPanelWidth] - [#s_VariableXPadding])
LeftMouseUpAction=[!SetVariable "s_SettingsTheme" "2"][!WriteKeyValue Variables "s_SettingsTheme" "2" "#@#includes\Variables.inc"][!SetVariable "s_RawPath" "#@#includes\themes\2.inc"][!WriteKeyValue Variables "s_RawPath" "#@#includes\themes\2.inc"][!WriteKeyValue Variables "s_Type" "inc"][#s_FileChangeAction]
Y=0R
Padding=0,0,0,0

[VariableIcon1]
Meter=String
Text=
Y=[#s_ValueYPadding]R
MeterStyle=VariableIcon | RightPanel
[Var1]
Meter=String
Text=
MeterStyle=VarTitle | RightPanel
[Var1Description]
Meter=String
Text=Theme names can be changed in Settings' Internal variables
MeterStyle=VarDescription | RightPanel
W=([#s_GeneratorRightPanelWidth] - [#s_VariableXPadding] * 2)
[Value3]
Meter=String
Text=Go to internal tab
MeterStyle=VarStringValue | RightPanel
W=([#s_GeneratorRightPanelWidth] - [#s_VariableXPadding])
LeftMouseUpAction=[!WriteKeyValue Variables s_GenCurrentCategory 2][!Refresh]

