[FirstRight]
Meter=Image
MeterStyle=FirstItem | FirstRightPanel
Y=([#s_ScrollRight] + [#s_TopHeight])
SolidColor=0,0,0,0
W=0
H=0

[CategoryIcon4]
Meter=String
Text=
MeterStyle=CategoryIcon | RightPanel

[Title4]
Meter=String
Text=Font
MeterStyle=CategoryTitle
W=([#s_RightPanelW] - [CategoryIcon4:W])

[CategoryDescription4]
Meter=String
Text=
MeterStyle=VarDescription | ThickDescription | RightPanel

[CategoryTitleSeparator4]
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
Text=Font face 
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
Text=[#s_FontFace]
MeterStyle=VarString | RightPanel
FontFace=#s_FontFace#
LeftMouseUpAction=[!CommandMeasure "InputText0" "ExecuteBatch All"][!SetOption #CURRENTSECTION# FontColor "0,0,0,0"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[InputText0]
Measure=Plugin
Plugin=InputText
SolidColor=[#s_RightPanelBackgroundColor]
FontColor=#s_FontColor#
FontFace=#s_FontFace#
FontSize=#s_InputTextFontSize#
X=([VariableValue0:X] + [#s_VariableXPadding])
Y=([VariableValue0:Y] + [#s_VariableYPadding])
H=[VariableValue0:H]
W=([#s_RightPanelW] - ([#s_VariableXPadding] * 2))
DynamicVariables=1
DefaultValue=[#s_FontFace]
Command1=[!WriteKeyValue "Variables" "s_FontFace" "$UserInput$" "#SKINSPATH#settings\@Resources\Themes\1.inc"][#s_SaveScroll][!Refresh][&MainLua:OnChangeAction()]
OnDismissAction=[!SetOption VariableValue0 FontColor "[#s_FontColor]"][!UpdateMeter VariableValue0][!Redraw]


[VarIcon1]
Meter=String
MeterStyle=VarIcon | RightPanel
Padding=[#s_VariableXPadding],[#s_VariableIconTopPadding],[#s_VariableIconGap],0
Hidden=1

[VariableTitle1]
Meter=String
MeterStyle=VarTitle
Text=Icon font face 
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
Text=[#s_IconFontFace]
MeterStyle=VarString | RightPanel
FontFace=#s_FontFace#
LeftMouseUpAction=[!CommandMeasure "InputText1" "ExecuteBatch All"][!SetOption #CURRENTSECTION# FontColor "0,0,0,0"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[InputText1]
Measure=Plugin
Plugin=InputText
SolidColor=[#s_RightPanelBackgroundColor]
FontColor=#s_FontColor#
FontFace=#s_FontFace#
FontSize=#s_InputTextFontSize#
X=([VariableValue1:X] + [#s_VariableXPadding])
Y=([VariableValue1:Y] + [#s_VariableYPadding])
H=[VariableValue1:H]
W=([#s_RightPanelW] - ([#s_VariableXPadding] * 2))
DynamicVariables=1
DefaultValue=[#s_IconFontFace]
Command1=[!WriteKeyValue "Variables" "s_IconFontFace" "$UserInput$" "#SKINSPATH#settings\@Resources\Themes\1.inc"][#s_SaveScroll][!Refresh][&MainLua:OnChangeAction()]
OnDismissAction=[!SetOption VariableValue1 FontColor "[#s_FontColor]"][!UpdateMeter VariableValue1][!Redraw]


[VarIcon2]
Meter=String
MeterStyle=VarIcon | RightPanel
Padding=[#s_VariableXPadding],[#s_VariableIconTopPadding],[#s_VariableIconGap],0
Hidden=1

[VariableTitle2]
Meter=String
MeterStyle=VarTitle
Text=Font color 
ClipStringW=([#s_RightPanelW] - ([#s_VariableXPadding] * 2) - [VarIcon2:W])
Padding=[#s_VariableXPadding],[#s_VariableYPadding],[#s_VariableXPadding],[#s_VariableYPadding]

FontFace=#s_FontFace#

[VariableDescription2]
Meter=String
MeterStyle=VarDescription | RightPanel
Text=
FontFace=#s_FontFace#



[VariableContainer2]
MeterStyle=VariableContainer | RightPanel
Meter=Image
H=([ColorVariableValue2:H] > [ColorStringValue2:H]) ? [ColorVariableValue2:H] : [ColorStringValue2:H]

[ColorVariableValueContainer2]
Meter=Shape
X=[#s_VariableXPadding]r
Y=r
Shape=Ellipse ([#s_ColorSize]+[#s_ColorStrokeWidth]),([#s_ColorSize]+[#s_ColorStrokeWidth]),([#s_ColorSize]+[#s_ColorStrokeWidth]) | Fill Color 200,200,200 | StrokeWidth [#s_ColorStrokeWidth]

[ColorTransparentBackground2]
Meter=Image
ImageName=#CURRENTPATH#Addons\TrpBg
H=([#s_ColorSize]*2)
W=([#s_ColorSize]*2)
Container=ColorVariableValueContainer2

[ColorVariableValue2]
Meter=Shape
X=0
Y=0
Shape=Ellipse ([#s_ColorSize]+[#s_ColorStrokeWidth]/2),([#s_ColorSize]+[#s_ColorStrokeWidth]/2),[#s_ColorSize],[#s_ColorSize] | Fill Color [#s_FontColor] | StrokeWidth [#s_ColorStrokeWidth] | Extend Outline
Outline=Stroke Color [#s_ColorStrokeColor]
MeterStyle=VarColor
LeftMouseUpAction=[!CommandMeasure ColorPickerUI "SetColor('s_FontColor', 'Variables', 'rgba', [[#SKINSPATH#settings\@Resources\Themes\1.inc]])"]
Container=ColorVariableValueContainer2

[ColorStringValue2]
Meter=String
X=(2*[#s_ColorSize]+[#s_VariableXPadding]+10)
Text=[#s_FontColor]
MeterStyle=VarString | VarColorString
FontFace=#s_FontFace#
LeftMouseUpAction=[!CommandMeasure ColorPickerUI "SetColor('s_FontColor', 'Variables', 'rgba', [[#SKINSPATH#settings\@Resources\Themes\1.inc]])"]
Container=VariableContainer2


[VarIcon3]
Meter=String
MeterStyle=VarIcon | RightPanel
Padding=[#s_VariableXPadding],[#s_VariableIconTopPadding],[#s_VariableIconGap],0
Hidden=1

[VariableTitle3]
Meter=String
MeterStyle=VarTitle
Text=Category Title Size
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
Text=[#s_CategoryTitleSize]
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
DefaultValue=[#s_CategoryTitleSize]
Command1=[!WriteKeyValue "Variables" "s_CategoryTitleSize" "$UserInput$" "#SKINSPATH#settings\@Resources\Themes\1.inc"][#s_SaveScroll][!Refresh][&MainLua:OnChangeAction()]
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
Text=Variable Title Size
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
Text=[#s_VarTitleSize]
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
DefaultValue=[#s_VarTitleSize]
Command1=[!WriteKeyValue "Variables" "s_VarTitleSize" "$UserInput$" "#SKINSPATH#settings\@Resources\Themes\1.inc"][#s_SaveScroll][!Refresh][&MainLua:OnChangeAction()]
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
Text=Variable Text Size
ClipStringW=([#s_RightPanelW] - ([#s_VariableXPadding] * 2) - [VarIcon5:W])
Padding=[#s_VariableXPadding],[#s_VariableYPadding],[#s_VariableXPadding],[#s_VariableYPadding]

FontFace=#s_FontFace#

[VariableDescription5]
Meter=String
MeterStyle=VarDescription | RightPanel
Text=
FontFace=#s_FontFace#



[VariableValue5]
Meter=String
Text=[#s_VarTextSize]
MeterStyle=VarString | RightPanel
FontFace=#s_FontFace#
LeftMouseUpAction=[!CommandMeasure "InputText5" "ExecuteBatch All"][!SetOption #CURRENTSECTION# FontColor "0,0,0,0"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[InputText5]
Measure=Plugin
Plugin=InputText
SolidColor=[#s_RightPanelBackgroundColor]
FontColor=[#s_FontColor]
FontFace=#s_FontFace#
FontSize=[#s_InputTextFontSize]
X=([VariableValue5:X] + [#s_VariableXPadding])
Y=([VariableValue5:Y] + [#s_VariableYPadding])
H=[VariableValue5:H]
W=([#s_RightPanelW] - ([#s_VariableXPadding] * 2))
DynamicVariables=1
DefaultValue=[#s_VarTextSize]
Command1=[!WriteKeyValue "Variables" "s_VarTextSize" "$UserInput$" "#SKINSPATH#settings\@Resources\Themes\1.inc"][#s_SaveScroll][!Refresh][&MainLua:OnChangeAction()]
OnDismissAction=[!SetOption VariableValue5 FontColor "[#s_FontColor]"][!UpdateMeter VariableValue5][!Redraw]
InputNumber=1


[VarIcon6]
Meter=String
MeterStyle=VarIcon | RightPanel
Padding=[#s_VariableXPadding],[#s_VariableIconTopPadding],[#s_VariableIconGap],0
Hidden=1

[VariableTitle6]
Meter=String
MeterStyle=VarTitle
Text=Variable Description Size
ClipStringW=([#s_RightPanelW] - ([#s_VariableXPadding] * 2) - [VarIcon6:W])
Padding=[#s_VariableXPadding],[#s_VariableYPadding],[#s_VariableXPadding],[#s_VariableYPadding]

FontFace=#s_FontFace#

[VariableDescription6]
Meter=String
MeterStyle=VarDescription | RightPanel
Text=
FontFace=#s_FontFace#



[VariableValue6]
Meter=String
Text=[#s_VarDescriptionSize]
MeterStyle=VarString | RightPanel
FontFace=#s_FontFace#
LeftMouseUpAction=[!CommandMeasure "InputText6" "ExecuteBatch All"][!SetOption #CURRENTSECTION# FontColor "0,0,0,0"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[InputText6]
Measure=Plugin
Plugin=InputText
SolidColor=[#s_RightPanelBackgroundColor]
FontColor=[#s_FontColor]
FontFace=#s_FontFace#
FontSize=[#s_InputTextFontSize]
X=([VariableValue6:X] + [#s_VariableXPadding])
Y=([VariableValue6:Y] + [#s_VariableYPadding])
H=[VariableValue6:H]
W=([#s_RightPanelW] - ([#s_VariableXPadding] * 2))
DynamicVariables=1
DefaultValue=[#s_VarDescriptionSize]
Command1=[!WriteKeyValue "Variables" "s_VarDescriptionSize" "$UserInput$" "#SKINSPATH#settings\@Resources\Themes\1.inc"][#s_SaveScroll][!Refresh][&MainLua:OnChangeAction()]
OnDismissAction=[!SetOption VariableValue6 FontColor "[#s_FontColor]"][!UpdateMeter VariableValue6][!Redraw]
InputNumber=1


[VarIcon7]
Meter=String
MeterStyle=VarIcon | RightPanel
Padding=[#s_VariableXPadding],[#s_VariableIconTopPadding],[#s_VariableIconGap],0
Hidden=1

[VariableTitle7]
Meter=String
MeterStyle=VarTitle
Text=Selected item font weight 
ClipStringW=([#s_RightPanelW] - ([#s_VariableXPadding] * 2) - [VarIcon7:W])
Padding=[#s_VariableXPadding],[#s_VariableYPadding],[#s_VariableXPadding],[#s_VariableYPadding]

FontFace=#s_FontFace#

[VariableDescription7]
Meter=String
MeterStyle=VarDescription | RightPanel
Text=
FontFace=#s_FontFace#



[VariableValue7]
Meter=String
Text=[#s_SelectedFontWeight]
MeterStyle=VarString | RightPanel
FontFace=#s_FontFace#
LeftMouseUpAction=[!CommandMeasure "InputText7" "ExecuteBatch All"][!SetOption #CURRENTSECTION# FontColor "0,0,0,0"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[InputText7]
Measure=Plugin
Plugin=InputText
SolidColor=[#s_RightPanelBackgroundColor]
FontColor=[#s_FontColor]
FontFace=#s_FontFace#
FontSize=[#s_InputTextFontSize]
X=([VariableValue7:X] + [#s_VariableXPadding])
Y=([VariableValue7:Y] + [#s_VariableYPadding])
H=[VariableValue7:H]
W=([#s_RightPanelW] - ([#s_VariableXPadding] * 2))
DynamicVariables=1
DefaultValue=[#s_SelectedFontWeight]
Command1=[!WriteKeyValue "Variables" "s_SelectedFontWeight" "$UserInput$" "#SKINSPATH#settings\@Resources\Themes\1.inc"][#s_SaveScroll][!Refresh][&MainLua:OnChangeAction()]
OnDismissAction=[!SetOption VariableValue7 FontColor "[#s_FontColor]"][!UpdateMeter VariableValue7][!Redraw]
InputNumber=1


[VarIcon8]
Meter=String
MeterStyle=VarIcon | RightPanel
Padding=[#s_VariableXPadding],[#s_VariableIconTopPadding],[#s_VariableIconGap],0
Hidden=1

[VariableTitle8]
Meter=String
MeterStyle=VarTitle
Text=List About Size
ClipStringW=([#s_RightPanelW] - ([#s_VariableXPadding] * 2) - [VarIcon8:W])
Padding=[#s_VariableXPadding],[#s_VariableYPadding],[#s_VariableXPadding],[#s_VariableYPadding]

FontFace=#s_FontFace#

[VariableDescription8]
Meter=String
MeterStyle=VarDescription | RightPanel
Text=
FontFace=#s_FontFace#



[VariableValue8]
Meter=String
Text=[#s_ListAboutSize]
MeterStyle=VarString | RightPanel
FontFace=#s_FontFace#
LeftMouseUpAction=[!CommandMeasure "InputText8" "ExecuteBatch All"][!SetOption #CURRENTSECTION# FontColor "0,0,0,0"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[InputText8]
Measure=Plugin
Plugin=InputText
SolidColor=[#s_RightPanelBackgroundColor]
FontColor=[#s_FontColor]
FontFace=#s_FontFace#
FontSize=[#s_InputTextFontSize]
X=([VariableValue8:X] + [#s_VariableXPadding])
Y=([VariableValue8:Y] + [#s_VariableYPadding])
H=[VariableValue8:H]
W=([#s_RightPanelW] - ([#s_VariableXPadding] * 2))
DynamicVariables=1
DefaultValue=[#s_ListAboutSize]
Command1=[!WriteKeyValue "Variables" "s_ListAboutSize" "$UserInput$" "#SKINSPATH#settings\@Resources\Themes\1.inc"][#s_SaveScroll][!Refresh][&MainLua:OnChangeAction()]
OnDismissAction=[!SetOption VariableValue8 FontColor "[#s_FontColor]"][!UpdateMeter VariableValue8][!Redraw]
InputNumber=1


[VarIcon9]
Meter=String
MeterStyle=VarIcon | RightPanel
Padding=[#s_VariableXPadding],[#s_VariableIconTopPadding],[#s_VariableIconGap],0
Hidden=1

[VariableTitle9]
Meter=String
MeterStyle=VarTitle
Text=List Default Size
ClipStringW=([#s_RightPanelW] - ([#s_VariableXPadding] * 2) - [VarIcon9:W])
Padding=[#s_VariableXPadding],[#s_VariableYPadding],[#s_VariableXPadding],[#s_VariableYPadding]

FontFace=#s_FontFace#

[VariableDescription9]
Meter=String
MeterStyle=VarDescription | RightPanel
Text=
FontFace=#s_FontFace#



[VariableValue9]
Meter=String
Text=[#s_ListDefaultSize]
MeterStyle=VarString | RightPanel
FontFace=#s_FontFace#
LeftMouseUpAction=[!CommandMeasure "InputText9" "ExecuteBatch All"][!SetOption #CURRENTSECTION# FontColor "0,0,0,0"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[InputText9]
Measure=Plugin
Plugin=InputText
SolidColor=[#s_RightPanelBackgroundColor]
FontColor=[#s_FontColor]
FontFace=#s_FontFace#
FontSize=[#s_InputTextFontSize]
X=([VariableValue9:X] + [#s_VariableXPadding])
Y=([VariableValue9:Y] + [#s_VariableYPadding])
H=[VariableValue9:H]
W=([#s_RightPanelW] - ([#s_VariableXPadding] * 2))
DynamicVariables=1
DefaultValue=[#s_ListDefaultSize]
Command1=[!WriteKeyValue "Variables" "s_ListDefaultSize" "$UserInput$" "#SKINSPATH#settings\@Resources\Themes\1.inc"][#s_SaveScroll][!Refresh][&MainLua:OnChangeAction()]
OnDismissAction=[!SetOption VariableValue9 FontColor "[#s_FontColor]"][!UpdateMeter VariableValue9][!Redraw]
InputNumber=1


[VarIcon10]
Meter=String
MeterStyle=VarIcon | RightPanel
Padding=[#s_VariableXPadding],[#s_VariableIconTopPadding],[#s_VariableIconGap],0
Hidden=1

[VariableTitle10]
Meter=String
MeterStyle=VarTitle
Text=List Topic Size
ClipStringW=([#s_RightPanelW] - ([#s_VariableXPadding] * 2) - [VarIcon10:W])
Padding=[#s_VariableXPadding],[#s_VariableYPadding],[#s_VariableXPadding],[#s_VariableYPadding]

FontFace=#s_FontFace#

[VariableDescription10]
Meter=String
MeterStyle=VarDescription | RightPanel
Text=
FontFace=#s_FontFace#



[VariableValue10]
Meter=String
Text=[#s_ListTopicSize]
MeterStyle=VarString | RightPanel
FontFace=#s_FontFace#
LeftMouseUpAction=[!CommandMeasure "InputText10" "ExecuteBatch All"][!SetOption #CURRENTSECTION# FontColor "0,0,0,0"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[InputText10]
Measure=Plugin
Plugin=InputText
SolidColor=[#s_RightPanelBackgroundColor]
FontColor=[#s_FontColor]
FontFace=#s_FontFace#
FontSize=[#s_InputTextFontSize]
X=([VariableValue10:X] + [#s_VariableXPadding])
Y=([VariableValue10:Y] + [#s_VariableYPadding])
H=[VariableValue10:H]
W=([#s_RightPanelW] - ([#s_VariableXPadding] * 2))
DynamicVariables=1
DefaultValue=[#s_ListTopicSize]
Command1=[!WriteKeyValue "Variables" "s_ListTopicSize" "$UserInput$" "#SKINSPATH#settings\@Resources\Themes\1.inc"][#s_SaveScroll][!Refresh][&MainLua:OnChangeAction()]
OnDismissAction=[!SetOption VariableValue10 FontColor "[#s_FontColor]"][!UpdateMeter VariableValue10][!Redraw]
InputNumber=1


[VarIcon11]
Meter=String
MeterStyle=VarIcon | RightPanel
Padding=[#s_VariableXPadding],[#s_VariableIconTopPadding],[#s_VariableIconGap],0
Hidden=1

[VariableTitle11]
Meter=String
MeterStyle=VarTitle
Text=Font weight 
ClipStringW=([#s_RightPanelW] - ([#s_VariableXPadding] * 2) - [VarIcon11:W])
Padding=[#s_VariableXPadding],[#s_VariableYPadding],[#s_VariableXPadding],[#s_VariableYPadding]

FontFace=#s_FontFace#

[VariableDescription11]
Meter=String
MeterStyle=VarDescription | RightPanel
Text=
FontFace=#s_FontFace#



[VariableValue11]
Meter=String
Text=[#s_FontWeight]
MeterStyle=VarString | RightPanel
FontFace=#s_FontFace#
LeftMouseUpAction=[!CommandMeasure "InputText11" "ExecuteBatch All"][!SetOption #CURRENTSECTION# FontColor "0,0,0,0"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[InputText11]
Measure=Plugin
Plugin=InputText
SolidColor=[#s_RightPanelBackgroundColor]
FontColor=[#s_FontColor]
FontFace=#s_FontFace#
FontSize=[#s_InputTextFontSize]
X=([VariableValue11:X] + [#s_VariableXPadding])
Y=([VariableValue11:Y] + [#s_VariableYPadding])
H=[VariableValue11:H]
W=([#s_RightPanelW] - ([#s_VariableXPadding] * 2))
DynamicVariables=1
DefaultValue=[#s_FontWeight]
Command1=[!WriteKeyValue "Variables" "s_FontWeight" "$UserInput$" "#SKINSPATH#settings\@Resources\Themes\1.inc"][#s_SaveScroll][!Refresh][&MainLua:OnChangeAction()]
OnDismissAction=[!SetOption VariableValue11 FontColor "[#s_FontColor]"][!UpdateMeter VariableValue11][!Redraw]
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


