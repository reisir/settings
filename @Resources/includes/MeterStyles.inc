;Category list styles
[CategoryListIcon]
AccurateText=1
AntiAlias=1
X=0
Y=0R
Padding=([#s_ListIconLeftPadding] + [#s_VarTitleNudge]),[#s_ListIconTopPadding],0,[#s_ListItemPadding]
FontSize=#s_FontSize3#
FontFace=#s_IconFontFace#

[CategoryListItem]
AccurateText=1
AntiAlias=1
Y=0r
Padding=[#s_ListItemLeftPadding],[#s_ListItemTopPadding],[#s_ListItemPadding],[#s_ListItemPadding]
FontSize=#s_FontSize3#
FontFace=#s_FontFace#
DynamicVariables=1

[CategoryListTopicItem]
AccurateText=1
AntiAlias=1
Y=0r
Padding=[#s_ListItemLeftPadding],[#s_ListItemTopPadding],[#s_ListItemPadding],[#s_ListItemPadding]
FontSize=#s_FontSize4#
FontFace=#s_FontFace#
DynamicVariables=1

[CategoryListAboutItem]
AccurateText=1
AntiAlias=1
Y=0r
Padding=[#s_ListItemLeftPadding],[#s_ListItemTopPadding],[#s_ListItemPadding],[#s_ListItemPadding]
FontSize=#s_FontSize2#
FontFace=#s_FontFace#
FontWeight=500
DynamicVariables=1

;Category styles
[CategoryIcon]
AccurateText=1
AntiAlias=1
X=0
Y=0R
Padding=[#s_CategoryTitleLeftPadding],[#s_CategoryIconTopPadding],0,0
FontSize=#s_FontSize1#
FontFace=#s_IconFontFace#

[CategoryTitle]
AccurateText=1
AntiAlias=1
Y=0r
Padding=0,[#s_CategoryTitleTopPadding],0,0
FontFace=#s_FontFace#
FontWeight=#s_TitleFontWeight#
FontSize=#s_FontSize1#
InlineSetting=CharacterSpacing | [#s_VarTitleNudge] | *
InlinePattern=^.
DynamicVariables=1

[CategoryTitleSeparator]
X=0
Y=0R
H=[#s_CategoryTitleBottomPadding]
W=[#s_RightPanelW]

;Variable styles
[VarTitle]
AccurateText=1
AntiAlias=1
Y=0R
X=0
Padding=[#s_VariableXPadding],0,[#s_VariableXPadding],0
FontFace=#s_FontFace#
FontSize=#s_FontSize2#
FontWeight=#s_TitleFontWeight#
InlineSetting=CharacterSpacing | [#s_VarTitleNudge] | *
InlinePattern=^.

[VarDescription]
AccurateText=1
AntiAlias=1
X=0
Y=0R
Padding=[#s_VariableXPadding],0,[#s_VariableXPadding],0
FontFace=#s_FontFace#
FontSize=#s_FontSize4#

[VarStringValue]
AccurateText=1
AntiAlias=1
Y=0R
Padding=[#s_VariableXPadding],[#s_ValueYPadding],[#s_VariableXPadding],[#s_ValueYPadding]
FontFace=#s_FontFace#
FontSize=#s_FontSize3#
MouseOverAction=[!SetOption #CURRENTSECTION# FontColor [#s_SelectedColor]][!SetOption #CURRENTSECTION# FontWeight [#s_SelectedFontWeight]][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# FontColor [#s_FontColor]][!SetOption #CURRENTSECTION# FontWeight [#s_FontWeight]][!UpdateMeter #CURRENTSECTION#][!Redraw]

[VarColorString]
Y=0r
X=0R
Padding=[#s_ColorStringLeftPadding],([#s_ColorSize] - [#s_FontSize3]),[#s_VariableXPadding],(([#s_ColorSize] - [#s_FontSize3]) + [#s_ValueYPadding])

[Link1]
MouseOverAction=[!SetOption #CURRENTSECTION# FontColor [#s_SelectedColor]][!SetOption #CURRENTSECTION# InlineSetting "Underline"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# FontColor [#s_FontColor]][!SetOption #CURRENTSECTION# InlineSetting ""][!UpdateMeter #CURRENTSECTION#][!Redraw]

[Link]
FontColor=[#s_FontColor]

[VarToggleValue]
X=(([#s_ToggleSize] / 2) + [#s_VariableXPadding])
DynamicVariables=1

[VarColorValue]
X=[#s_VariableXPadding]
Y=[#s_ValueYPadding]R

