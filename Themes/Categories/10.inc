[FirstRight]
Meter=Image
MeterStyle=FirstItem | FirstRightPanel
Y=([#s_ScrollRight] + [#s_TopHeight])
SolidColor=0,0,0,0
W=0
H=0

[CategoryIcon10]
Meter=String
Text=
MeterStyle=CategoryIcon | RightPanel

[Title10]
Meter=String
Text=Category
MeterStyle=CategoryTitle
W=([#s_RightPanelW] - [CategoryIcon10:W])

[CategoryDescription10]
Meter=String
Text=
MeterStyle=VarDescription | ThickDescription | RightPanel

[CategoryTitleSeparator10]
Meter=Image
MeterStyle=CategoryTitleSeparator | RightPanel


[VarIcon0]
Meter=String
MeterStyle=VarIcon | RightPanel
Padding=[#s_VariableXPadding],[#s_VariableIconTopPadding],[#s_VariableIconGap],0
Hidden=1

[VariableTitle0]
Meter=String
MeterStyle=VarTitle
Text=Category title top and bottom padding 
ClipStringW=([#s_RightPanelW] - ([#s_VariableXPadding] * 2) - [VarIcon0:W])
Padding=[#s_VariableXPadding],[#s_VariableYPadding],[#s_VariableXPadding],[#s_VariableYPadding]

FontFace=#s_FontFace#

[VariableDescription0]
Meter=String
MeterStyle=VarDescription | RightPanel
Text=
FontFace=#s_FontFace#



[VariableValue0]
Meter=String
Text=[#s_CategoryTitleXPadding]
MeterStyle=VarString | RightPanel
FontFace=#s_FontFace#
LeftMouseUpAction=[!CommandMeasure "InputText0" "ExecuteBatch All"][!SetOption #CURRENTSECTION# FontColor "0,0,0,0"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[InputText0]
Measure=Plugin
Plugin=InputText
SolidColor=[#s_RightPanelBackgroundColor]
FontColor=[#s_FontColor]
FontFace=#s_FontFace#
FontSize=[#s_InputTextFontSize]
X=([VariableValue0:X] + [#s_VariableXPadding])
Y=([VariableValue0:Y] + [#s_VariableYPadding])
H=[VariableValue0:H]
W=([#s_RightPanelW] - ([#s_VariableXPadding] * 2))
DynamicVariables=1
DefaultValue=[#s_CategoryTitleXPadding]
Command1=[!WriteKeyValue "Variables" "s_CategoryTitleXPadding" "$UserInput$" "#SKINSPATH#settings\@Resources\Themes\1.inc"][#s_SaveScroll][!Refresh][&MainLua:OnChangeAction()]
OnDismissAction=[!SetOption VariableValue0 FontColor "[#s_FontColor]"][!UpdateMeter VariableValue0][!Redraw]
InputNumber=1


[VarIcon1]
Meter=String
MeterStyle=VarIcon | RightPanel
Padding=[#s_VariableXPadding],[#s_VariableIconTopPadding],[#s_VariableIconGap],0
Hidden=1

[VariableTitle1]
Meter=String
MeterStyle=VarTitle
Text=Category title top padding 
ClipStringW=([#s_RightPanelW] - ([#s_VariableXPadding] * 2) - [VarIcon1:W])
Padding=[#s_VariableXPadding],[#s_VariableYPadding],[#s_VariableXPadding],[#s_VariableYPadding]

FontFace=#s_FontFace#

[VariableDescription1]
Meter=String
MeterStyle=VarDescription | RightPanel
Text=
FontFace=#s_FontFace#



[VariableValue1]
Meter=String
Text=[#s_CategoryTitleTopPadding]
MeterStyle=VarString | RightPanel
FontFace=#s_FontFace#
LeftMouseUpAction=[!CommandMeasure "InputText1" "ExecuteBatch All"][!SetOption #CURRENTSECTION# FontColor "0,0,0,0"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[InputText1]
Measure=Plugin
Plugin=InputText
SolidColor=[#s_RightPanelBackgroundColor]
FontColor=[#s_FontColor]
FontFace=#s_FontFace#
FontSize=[#s_InputTextFontSize]
X=([VariableValue1:X] + [#s_VariableXPadding])
Y=([VariableValue1:Y] + [#s_VariableYPadding])
H=[VariableValue1:H]
W=([#s_RightPanelW] - ([#s_VariableXPadding] * 2))
DynamicVariables=1
DefaultValue=[#s_CategoryTitleTopPadding]
Command1=[!WriteKeyValue "Variables" "s_CategoryTitleTopPadding" "$UserInput$" "#SKINSPATH#settings\@Resources\Themes\1.inc"][#s_SaveScroll][!Refresh][&MainLua:OnChangeAction()]
OnDismissAction=[!SetOption VariableValue1 FontColor "[#s_FontColor]"][!UpdateMeter VariableValue1][!Redraw]
InputNumber=1


[VarIcon2]
Meter=String
MeterStyle=VarIcon | RightPanel
Padding=[#s_VariableXPadding],[#s_VariableIconTopPadding],[#s_VariableIconGap],0
Hidden=1

[VariableTitle2]
Meter=String
MeterStyle=VarTitle
Text=Category title bottom padding 
ClipStringW=([#s_RightPanelW] - ([#s_VariableXPadding] * 2) - [VarIcon2:W])
Padding=[#s_VariableXPadding],[#s_VariableYPadding],[#s_VariableXPadding],[#s_VariableYPadding]

FontFace=#s_FontFace#

[VariableDescription2]
Meter=String
MeterStyle=VarDescription | RightPanel
Text=
FontFace=#s_FontFace#



[VariableValue2]
Meter=String
Text=[#s_CategoryTitleBottomPadding]
MeterStyle=VarString | RightPanel
FontFace=#s_FontFace#
LeftMouseUpAction=[!CommandMeasure "InputText2" "ExecuteBatch All"][!SetOption #CURRENTSECTION# FontColor "0,0,0,0"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[InputText2]
Measure=Plugin
Plugin=InputText
SolidColor=[#s_RightPanelBackgroundColor]
FontColor=[#s_FontColor]
FontFace=#s_FontFace#
FontSize=[#s_InputTextFontSize]
X=([VariableValue2:X] + [#s_VariableXPadding])
Y=([VariableValue2:Y] + [#s_VariableYPadding])
H=[VariableValue2:H]
W=([#s_RightPanelW] - ([#s_VariableXPadding] * 2))
DynamicVariables=1
DefaultValue=[#s_CategoryTitleBottomPadding]
Command1=[!WriteKeyValue "Variables" "s_CategoryTitleBottomPadding" "$UserInput$" "#SKINSPATH#settings\@Resources\Themes\1.inc"][#s_SaveScroll][!Refresh][&MainLua:OnChangeAction()]
OnDismissAction=[!SetOption VariableValue2 FontColor "[#s_FontColor]"][!UpdateMeter VariableValue2][!Redraw]
InputNumber=1


[VarIcon3]
Meter=String
MeterStyle=VarIcon | RightPanel
Padding=[#s_VariableXPadding],[#s_VariableIconTopPadding],[#s_VariableIconGap],0
Hidden=1

[VariableTitle3]
Meter=String
MeterStyle=VarTitle
Text=Category title font weight 
ClipStringW=([#s_RightPanelW] - ([#s_VariableXPadding] * 2) - [VarIcon3:W])
Padding=[#s_VariableXPadding],[#s_VariableYPadding],[#s_VariableXPadding],[#s_VariableYPadding]

FontFace=#s_FontFace#

[VariableDescription3]
Meter=String
MeterStyle=VarDescription | RightPanel
Text=
FontFace=#s_FontFace#



[VariableValue3]
Meter=String
Text=[#s_CategoryTitleFontWeight]
MeterStyle=VarString | RightPanel
FontFace=#s_FontFace#
LeftMouseUpAction=[!CommandMeasure "InputText3" "ExecuteBatch All"][!SetOption #CURRENTSECTION# FontColor "0,0,0,0"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[InputText3]
Measure=Plugin
Plugin=InputText
SolidColor=[#s_RightPanelBackgroundColor]
FontColor=[#s_FontColor]
FontFace=#s_FontFace#
FontSize=[#s_InputTextFontSize]
X=([VariableValue3:X] + [#s_VariableXPadding])
Y=([VariableValue3:Y] + [#s_VariableYPadding])
H=[VariableValue3:H]
W=([#s_RightPanelW] - ([#s_VariableXPadding] * 2))
DynamicVariables=1
DefaultValue=[#s_CategoryTitleFontWeight]
Command1=[!WriteKeyValue "Variables" "s_CategoryTitleFontWeight" "$UserInput$" "#SKINSPATH#settings\@Resources\Themes\1.inc"][#s_SaveScroll][!Refresh][&MainLua:OnChangeAction()]
OnDismissAction=[!SetOption VariableValue3 FontColor "[#s_FontColor]"][!UpdateMeter VariableValue3][!Redraw]
InputNumber=1


[VarIcon4]
Meter=String
MeterStyle=VarIcon | RightPanel
Padding=[#s_VariableXPadding],[#s_VariableIconTopPadding],[#s_VariableIconGap],0
Hidden=1

[VariableTitle4]
Meter=String
MeterStyle=VarTitle
Text=Category description font weight 
ClipStringW=([#s_RightPanelW] - ([#s_VariableXPadding] * 2) - [VarIcon4:W])
Padding=[#s_VariableXPadding],[#s_VariableYPadding],[#s_VariableXPadding],[#s_VariableYPadding]

FontFace=#s_FontFace#

[VariableDescription4]
Meter=String
MeterStyle=VarDescription | RightPanel
Text=
FontFace=#s_FontFace#



[VariableValue4]
Meter=String
Text=[#s_CategoryDescriptionFontWeight]
MeterStyle=VarString | RightPanel
FontFace=#s_FontFace#
LeftMouseUpAction=[!CommandMeasure "InputText4" "ExecuteBatch All"][!SetOption #CURRENTSECTION# FontColor "0,0,0,0"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[InputText4]
Measure=Plugin
Plugin=InputText
SolidColor=[#s_RightPanelBackgroundColor]
FontColor=[#s_FontColor]
FontFace=#s_FontFace#
FontSize=[#s_InputTextFontSize]
X=([VariableValue4:X] + [#s_VariableXPadding])
Y=([VariableValue4:Y] + [#s_VariableYPadding])
H=[VariableValue4:H]
W=([#s_RightPanelW] - ([#s_VariableXPadding] * 2))
DynamicVariables=1
DefaultValue=[#s_CategoryDescriptionFontWeight]
Command1=[!WriteKeyValue "Variables" "s_CategoryDescriptionFontWeight" "$UserInput$" "#SKINSPATH#settings\@Resources\Themes\1.inc"][#s_SaveScroll][!Refresh][&MainLua:OnChangeAction()]
OnDismissAction=[!SetOption VariableValue4 FontColor "[#s_FontColor]"][!UpdateMeter VariableValue4][!Redraw]
InputNumber=1


[VarIcon5]
Meter=String
MeterStyle=VarIcon | RightPanel
Padding=[#s_VariableXPadding],[#s_VariableIconTopPadding],[#s_VariableIconGap],0
Hidden=1

[VariableTitle5]
Meter=String
MeterStyle=VarTitle
Text=Category icon nudge 
ClipStringW=([#s_RightPanelW] - ([#s_VariableXPadding] * 2) - [VarIcon5:W])
Padding=[#s_VariableXPadding],[#s_VariableYPadding],[#s_VariableXPadding],[#s_VariableYPadding]

FontFace=#s_FontFace#

[VariableDescription5]
Meter=String
MeterStyle=VarDescription | RightPanel
Text=Visually center the category icon
FontFace=#s_FontFace#
Y=(-[#s_VariableYPadding])R



[VariableValue5]
Meter=String
Text=[#s_CategoryIconNudge]
MeterStyle=VarString | RightPanel
FontFace=#s_FontFace#
LeftMouseUpAction=[!CommandMeasure "InputText5" "ExecuteBatch All"][!SetOption #CURRENTSECTION# FontColor "0,0,0,0"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[InputText5]
Measure=Plugin
Plugin=InputText
SolidColor=[#s_RightPanelBackgroundColor]
FontColor=#s_FontColor#
FontFace=#s_FontFace#
FontSize=#s_InputTextFontSize#
X=([VariableValue5:X] + [#s_VariableXPadding])
Y=([VariableValue5:Y] + [#s_VariableYPadding])
H=[VariableValue5:H]
W=([#s_RightPanelW] - ([#s_VariableXPadding] * 2))
DynamicVariables=1
DefaultValue=[#s_CategoryIconNudge]
Command1=[!WriteKeyValue "Variables" "s_CategoryIconNudge" "$UserInput$" "#SKINSPATH#settings\@Resources\Themes\1.inc"][#s_SaveScroll][!Refresh][&MainLua:OnChangeAction()]
OnDismissAction=[!SetOption VariableValue5 FontColor "[#s_FontColor]"][!UpdateMeter VariableValue5][!Redraw]

[LastRight]
Meter=String
Text=Last
FontColor=255,0,0,0
MeterStyle=LastItem | RightPanel

[ScrollDownRight]
Measure=Calc
Formula=[#s_ScrollRight] - [#s_ScrollSpeed]
IfCondition=([LastRight:Y] > [#s_PanelH])
IfTrueAction=[!SetVariable "s_ScrollRight" "[&ScrollDownRight]"][!DisableMeasure "ScrollDownRight"][!Update][#s_SaveScroll]
IfFalseAction=[!DisableMeasure "ScrollDownRight"]
IfConditionMode=1
Disabled=1
DynamicVariables=1

[ScrollUpRight]
Measure=Calc
Formula=[#s_ScrollRight] + [#s_ScrollSpeed]
IfCondition=([FirstRight:Y] < [#s_TopHeight])
IfTrueAction=[!SetVariable "s_ScrollRight" "[&ScrollUpRight]"][!DisableMeasure "ScrollUpRight"][!Update][#s_SaveScroll]
IfFalseAction=[!DisableMeasure "ScrollUpRight"]
IfConditionMode=1
Disabled=1
DynamicVariables=1


