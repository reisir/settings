[CategoryIcon]
AccurateText=1
AntiAlias=1
DynamicVariables=1
Padding=[#s_CategoryTitleXPadding],[#s_CategoryIconTopPadding],0,0
FontSize=#s_FontSize1#
FontFace=#s_IconFontFace#
SolidColor=[#s_DebugCategoryIconColor[#s_DebugColors]] 
FontColor=[#s_FontColor]

[CategoryTitle]
AccurateText=1
AntiAlias=1
Y=0r
X=0R
Padding=0,[#s_CategoryTitleTopPadding],0,0
ClipString=2
FontFace=#s_FontFace#
FontWeight=#s_CategoryTitleFontWeight#
FontSize=#s_FontSize1#
InlineSetting=CharacterSpacing | [#s_TitleIconNudge] | *
InlinePattern=^.
DynamicVariables=1
SolidColor=[#s_DebugCategoryTitleColor[#s_DebugColors]] 
FontColor=[#s_FontColor]

[ThickDescription]
FontWeight=[#s_CategoryDescriptionFontWeight]

[CategoryTitleSeparator]
H=[#s_CategoryTitleBottomPadding]
W=[#s_RightPanelW]
SolidColor=[#s_DebugSeparatorColor[#s_DebugColors]] 

[VarTitle]
AccurateText=1
AntiAlias=1
Y=0r
X=0R
ClipString=2
FontFace=[#s_FontFace]
FontSize=[#s_FontSize2]
FontWeight=[#s_VariableTitleFontWeight]
InlineSetting=CharacterSpacing | [#s_TitleIconNudge] | *
InlinePattern=^.
SolidColor=[#s_DebugVariableTitleColor[#s_DebugColors]] 
FontColor=[#s_FontColor]
Padding=[#s_VariableXPadding],[#s_VariableYPadding],[#s_VariableXPadding],[#s_VariableYPadding]
W=([#s_RightPanelW] - [#s_VariableXPadding] * 2)

[VarDescription]
AccurateText=1
AntiAlias=1
ClipString=2
FontFace=[#s_FontFace]
FontSize=[#s_FontSize4]
SolidColor=[#s_DebugDescriptionColor[#s_DebugColors]] 
FontColor=[#s_FontColor]
;TODO: change this to variable description padding
Padding=[#s_VariableXPadding],0,[#s_VariableXPadding],0
W=([#s_RightPanelW] - [#s_VariableXPadding] * 2)

[VarStringValue]
AccurateText=1
AntiAlias=1
FontColor=[#s_FontColor]
FontFace=[#s_FontFace]
FontSize=[#s_FontSize3]
ClipString=2
Padding=[#s_VariableXPadding],[#s_VariableYPadding],[#s_VariableXPadding],[#s_VariableYPadding]
W=([#s_RightPanelW] - [#s_VariableXPadding] * 2)
SolidColor=[#s_DebugValueColor[#s_DebugColors]] 
MouseOverAction=[!SetOption #CURRENTSECTION# FontColor [#s_SelectedColor]][!SetOption #CURRENTSECTION# FontWeight [#s_SelectedFontWeight]][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# FontColor [#s_FontColor]][!SetOption #CURRENTSECTION# FontWeight [#s_FontWeight]][!UpdateMeter #CURRENTSECTION#][!Redraw]

[VarContainer]
W=[#s_RightPanelW]
SolidColor=255,255,255
Y=0R

[Link]
MouseOverAction=
MouseLeaveAction=
[Link0]
MouseOverAction=
MouseLeaveAction=
[Link1]
MouseOverAction=[!SetOption #CURRENTSECTION# FontColor [#s_SelectedColor]][!SetOption #CURRENTSECTION# InlineSetting "Underline"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# FontColor [#s_FontColor]][!SetOption #CURRENTSECTION# InlineSetting ""][!UpdateMeter #CURRENTSECTION#][!Redraw]

[VarToggleValue]
X=(([#s_ToggleSize] / 2) + [#s_VariableXPadding])
Y=([#s_ToggleSize] / 2)
DynamicVariables=1
SolidColor=[#s_DebugToggleColor[#s_DebugColors]] 
Padding=0,[#s_VariableYPadding],0,[#s_VariableYPadding]

[VarColorValue]
X=[#s_VariableXPadding]
Y=1R
SolidColor=[#s_DebugColorColor[#s_DebugColors]] 
MouseOverAction=[!SetOption #CURRENTSECTION# "Outline" "Stroke Color [#s_SelectedColor]"][!SetVariable s_ColorStrokeWidth [#s_ColorStrokeWidthSelected]][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# "Outline" "Stroke Color [#s_ColorStrokeColor]"][!SetVariable s_ColorStrokeWidth [#s_ColorStrokeWidthDefault]][!UpdateMeter #CURRENTSECTION#][!Redraw]

[VarColorString]
Y=0r
X=[#s_VariableXPadding]R
FontColor=[#s_FontColor]
Padding=0,([#s_ColorSize] - [#s_FontSize3]),0,(([#s_ColorSize] - [#s_FontSize3]) + [#s_VariableYPadding])

