;Category list styles
[CategoryListIcon]
X=0
Y=0R
FontSize=#s_FontSize3#
FontFace=#s_IconFontFace#
Padding=([#s_ListIconLeftPadding] + [#s_VarTitleNudge]),[#s_ListIconTopPadding],0,[#s_ListItemPadding]
AccurateText=1
AntiAlias=1

[CategoryListItem]
Y=0r
FontSize=#s_FontSize3#
FontFace=#s_FontFace#
Padding=[#s_ListItemLeftPadding],[#s_ListItemTopPadding],[#s_ListItemPadding],[#s_ListItemPadding]
AccurateText=1
AntiAlias=1
DynamicVariables=1

[CategoryListSuperItem]
Y=0r
FontSize=#s_FontSize4#
FontFace=#s_FontFace#
Padding=[#s_ListItemLeftPadding],[#s_ListItemTopPadding],[#s_ListItemPadding],[#s_ListItemPadding]
AccurateText=1
AntiAlias=1
DynamicVariables=1

[CategoryListAboutItem]
Y=0r
FontSize=#s_FontSize2#
FontFace=#s_FontFace#
FontWeight=500
Padding=[#s_ListItemLeftPadding],[#s_ListItemTopPadding],[#s_ListItemPadding],[#s_ListItemPadding]
AccurateText=1
AntiAlias=1
DynamicVariables=1

;Category styles
[CategoryIcon]
X=0
Y=0R
FontSize=#s_FontSize1#
FontFace=#s_IconFontFace#
Padding=[#s_CategoryIconLeftPadding],[#s_CategoryIconTopPadding],0,[#s_VariablePadding]
AccurateText=1
AntiAlias=1

[CategoryTitle]
FontFace=#s_FontFace#
AccurateText=1
AntiAlias=1
FontWeight=#s_TitleFontWeight#
FontSize=#s_FontSize1#
Padding=0,[#s_CategoryTitleTopPadding],0,[#s_VariablePadding]
Y=0r
DynamicVariables=1

;Variable styles
[VarTitle]
FontFace=#s_FontFace#
AccurateText=1
AntiAlias=1
FontSize=#s_FontSize2#
FontWeight=#s_TitleFontWeight#
Padding=0,[#s_VariableTopPadding],[#s_VariablePadding],[#s_VariablePadding]
Y=0R
X=[#s_VariableXPadding]
InlineSetting=CharacterSpacing | [#s_VarTitleNudge] | *
InlinePattern=^.
;SolidColor=0,255,255

[VarDescription]
FontFace=#s_FontFace#
AccurateText=1
AntiAlias=1
X=[#s_VariableXPadding]
FontSize=#s_FontSize4#
Padding=0,0,[#s_VariableXPadding],0
Y=(-[#s_VariablePadding])R
;SolidColor=0,255,0

[VarStringValue]
FontFace=#s_FontFace#
AccurateText=1
AntiAlias=1
FontSize=#s_FontSize3#
Padding=[#s_VariableXPadding],[#s_VariableTopPadding],[#s_VariableXPadding],0
Y=0R
;SolidColor=255,0,0

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
Y=[#s_VariableTopPadding]R

