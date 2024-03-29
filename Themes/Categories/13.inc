[FirstRight]
Meter=Image
MeterStyle=FirstItem | FirstRightPanel
Y=([#s_ScrollRight] + [#s_TopHeight])
SolidColor=0,0,0,0
W=0
H=0

[CategoryIcon13]
Meter=String
Text=
MeterStyle=CategoryIcon | RightPanel

[Title13]
Meter=String
Text=About items
MeterStyle=CategoryTitle
W=([#s_RightPanelW] - [CategoryIcon13:W])

[CategoryDescription13]
Meter=String
Text=
MeterStyle=VarDescription | ThickDescription | RightPanel

[CategoryTitleSeparator13]
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
Text=About item top padding 
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
Text=[#s_ListAboutTopPadding]
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
DefaultValue=[#s_ListAboutTopPadding]
Command1=[!WriteKeyValue "Variables" "s_ListAboutTopPadding" "$UserInput$" "#SKINSPATH#settings\@Resources\Themes\1.inc"][#s_SaveScroll][!Refresh][&MainLua:OnChangeAction()]
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
Text=About item bottom padding 
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
Text=[#s_ListAboutBottomPadding]
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
DefaultValue=[#s_ListAboutBottomPadding]
Command1=[!WriteKeyValue "Variables" "s_ListAboutBottomPadding" "$UserInput$" "#SKINSPATH#settings\@Resources\Themes\1.inc"][#s_SaveScroll][!Refresh][&MainLua:OnChangeAction()]
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
Text=About item left padding 
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
Text=[#s_ListAboutLeftPadding]
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
DefaultValue=[#s_ListAboutLeftPadding]
Command1=[!WriteKeyValue "Variables" "s_ListAboutLeftPadding" "$UserInput$" "#SKINSPATH#settings\@Resources\Themes\1.inc"][#s_SaveScroll][!Refresh][&MainLua:OnChangeAction()]
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
Text=About item icon gap 
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
Text=[#s_ListAboutGap]
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
DefaultValue=[#s_ListAboutGap]
Command1=[!WriteKeyValue "Variables" "s_ListAboutGap" "$UserInput$" "#SKINSPATH#settings\@Resources\Themes\1.inc"][#s_SaveScroll][!Refresh][&MainLua:OnChangeAction()]
OnDismissAction=[!SetOption VariableValue3 FontColor "[#s_FontColor]"][!UpdateMeter VariableValue3][!Redraw]
InputNumber=1

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


