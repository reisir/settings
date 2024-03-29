; Default categories use common styles


[CategoryIcon]
AntiAlias=1
DynamicVariables=1
Padding=[#s_CategoryTitleXPadding],[#s_CategoryIconTopPadding],0,0
FontSize=#s_CategoryTitleSize#
FontFace=#s_IconFontFace#
SolidColor=[#s_DebugCategoryIconColor[#s_DebugColors]] 
FontColor=[#s_FontColor]

[CategoryTitle]
AntiAlias=1
Y=0r
X=0R
Padding=0,[#s_CategoryTitleTopPadding],0,0
ClipString=2
FontFace=#s_FontFace#
FontWeight=#s_CategoryTitleFontWeight#
FontSize=#s_CategoryTitleSize#
DynamicVariables=1
SolidColor=[#s_DebugCategoryTitleColor[#s_DebugColors]] 
FontColor=[#s_FontColor]

[ThickDescription]
FontWeight=[#s_CategoryDescriptionFontWeight]

[CategoryTitleSeparator]
H=[#s_CategoryTitleBottomPadding]
W=[#s_RightPanelW]
SolidColor=[#s_DebugSeparatorColor[#s_DebugColors]] 


[FirstItem]
H=0
W=0
X=0
SolidColor=0,0,0,0
DynamicVariables=1

[LastItem]
H=0
W=0
Y=0R
X=0
SolidColor=0,0,0,0

[FirstRightPanel]
X=[#s_LeftPanelW]

[FirstLeftPanel]
X=0

[LeftPanel]
X=0
DynamicVariables=1
Y=0R

[RightPanel]
X=#s_LeftPanelW#
DynamicVariables=1
Y=0R


[ListIcon]
FontFace=#s_IconFontFace#
AntiAlias=1
Y=0R
X=0
SolidColor=[#s_DebugListIconColor[#s_DebugColors]] 
FontColor=[#s_FontColor]
DynamicVariables=1

[ListItem]
Padding=0,[#s_ListYPadding],0,[#s_ListYPadding]
SolidColor=[#s_DebugListColor[#s_DebugColors]] 
FontFace=#s_FontFace#
ClipString=2
FontColor=[#s_FontColor]
DynamicVariables=1
AntiAlias=1
X=0R
Y=0r


[VariableContainer]
W=[#s_RightPanelW]
SolidColor=255,255,255
Y=0R


[VarIcon]
AntiAlias=1
Y=0R
X=0R
FontSize=[#s_VarTitleSize]
FontWeight=[#s_VariableTitleFontWeight]
SolidColor=[#s_DebugVarIconColor[#s_DebugColors]] 
FontColor=[#s_FontColor]

[VarTitle]
AntiAlias=1
Y=0r
X=0R
ClipString=2
FontFace=[#s_FontFace]
FontSize=[#s_VarTitleSize]
FontWeight=[#s_VariableTitleFontWeight]
SolidColor=[#s_DebugVariableTitleColor[#s_DebugColors]] 
FontColor=[#s_FontColor]

[VarDescription]
AntiAlias=1
ClipString=2
FontFace=[#s_FontFace]
FontSize=[#s_VarDescriptionSize]
SolidColor=[#s_DebugDescriptionColor[#s_DebugColors]] 
FontColor=[#s_FontColor]
;TODO: change this to variable description padding
Padding=[#s_VariableXPadding],0,[#s_VariableXPadding],0
W=([#s_RightPanelW] - [#s_VariableXPadding] * 2)


[ListAboutIcon]
Padding=[#s_ListAboutLeftPadding],[#s_ListYPadding],0,[#s_ListYPadding]
FontSize=#s_ListAboutSize#
FontColor=[#s_FontColor]

[ListAboutItem]
FontSize=#s_ListAboutSize#
FontColor=[#s_FontColor]


; Credit is a singleton, doesn't share styles


[ListDefaultIcon]
Padding=[#s_ListDefaultLeftPadding],[#s_ListYPadding],0,[#s_ListYPadding]
FontSize=#s_ListDefaultSize#
FontColor=[#s_FontColor]

[ListDefaultItem]
FontSize=#s_ListDefaultSize#
FontColor=[#s_FontColor]


[ListTopicIcon]
Padding=[#s_ListTopicLeftPadding],[#s_ListYPadding],0,[#s_ListYPadding]
FontSize=#s_ListTopicSize#
FontColor=[#s_FontColor]

[ListTopicItem]
FontSize=#s_ListTopicSize#
FontColor=[#s_FontColor]


; Info variables use String variable styles

[Link]
MouseOverAction=
MouseLeaveAction=
[Link0]
MouseOverAction=
MouseLeaveAction=
[Link1]
MouseOverAction=[!SetOption #CURRENTSECTION# FontColor [#s_SelectedColor]][!SetOption #CURRENTSECTION# InlineSetting "Underline"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# FontColor [#s_FontColor]][!SetOption #CURRENTSECTION# InlineSetting ""][!UpdateMeter #CURRENTSECTION#][!Redraw]
[Link2]


[VarColor]
X=[#s_VariableXPadding]
Y=1R
SolidColor=[#s_DebugColorColor[#s_DebugColors]] 
MouseOverAction=[!SetOption #CURRENTSECTION# "Outline" "Stroke Color [#s_SelectedColor]"][!SetVariable s_ColorStrokeWidth [#s_ColorStrokeWidthSelected]][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# "Outline" "Stroke Color [#s_ColorStrokeColor]"][!SetVariable s_ColorStrokeWidth [#s_ColorStrokeWidthDefault]][!UpdateMeter #CURRENTSECTION#][!Redraw]

[VarColorString]
Y=0r
FontColor=[#s_FontColor]
Padding=0,([#s_ColorSize] - [#s_VarTextSize]),0,(([#s_ColorSize] - [#s_VarTextSize]) + [#s_VariableYPadding])
SolidColor=[#s_DebugColorColor[#s_DebugColors]] 


; Integer variables use String variable styles


[VarString]
AntiAlias=1
FontColor=[#s_FontColor]
FontFace=[#s_FontFace]
FontSize=[#s_VarTextSize]
ClipString=2
Padding=[#s_VariableXPadding],[#s_VariableYPadding],[#s_VariableXPadding],[#s_VariableYPadding]
ClipStringW=([#s_RightPanelW] - [#s_VariableXPadding] * 2)
SolidColor=[#s_DebugValueColor[#s_DebugColors]] 
MouseOverAction=[!SetOption #CURRENTSECTION# FontColor [#s_SelectedColor]][!SetOption #CURRENTSECTION# FontWeight [#s_SelectedFontWeight]][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# FontColor [#s_FontColor]][!SetOption #CURRENTSECTION# FontWeight [#s_FontWeight]][!UpdateMeter #CURRENTSECTION#][!Redraw]


[VarToggle]
X=(([#s_ToggleSize] / 2) + [#s_VariableXPadding])
Y=([#s_ToggleSize] / 2)
DynamicVariables=1
SolidColor=[#s_DebugToggleColor[#s_DebugColors]] 
Padding=0,[#s_VariableYPadding],0,[#s_VariableYPadding]


