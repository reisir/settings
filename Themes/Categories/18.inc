[FirstRight]
Meter=Image
MeterStyle=FirstItem | FirstRightPanel
Y=([#s_ScrollRight] + [#s_TopHeight])
SolidColor=0,0,0,0
W=0
H=0

[CategoryIcon18]
Meter=String
Text=
MeterStyle=CategoryIcon | RightPanel

[Title18]
Meter=String
Text=Color
MeterStyle=CategoryTitle
W=([#s_RightPanelW] - [CategoryIcon18:W])

[CategoryDescription18]
Meter=String
Text=
MeterStyle=VarDescription | ThickDescription | RightPanel

[CategoryTitleSeparator18]
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
Text=Color circle radius 
ClipStringW=([#s_RightPanelW] - ([#s_VariableXPadding] * 2) - [VarIcon0:W])
Padding=[#s_VariableXPadding],[#s_VariableYPadding],[#s_VariableXPadding],[#s_VariableYPadding]

FontFace=#s_FontFace#

[VariableDescription0]
Meter=String
MeterStyle=VarDescription | RightPanel
Text=s_ColorSize
FontFace=#s_FontFace#
Y=(-[#s_VariableYPadding])R



[VariableValue0]
Meter=String
Text=[#s_ColorSize]
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
DefaultValue=[#s_ColorSize]
Command1=[!WriteKeyValue "Variables" "s_ColorSize" "$UserInput$" "#SKINSPATH#settings\@Resources\Themes\1.inc"][#s_SaveScroll][!Refresh][&MainLua:OnChangeAction()]
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
Text=Color circle stroke width 
ClipStringW=([#s_RightPanelW] - ([#s_VariableXPadding] * 2) - [VarIcon1:W])
Padding=[#s_VariableXPadding],[#s_VariableYPadding],[#s_VariableXPadding],[#s_VariableYPadding]

FontFace=#s_FontFace#

[VariableDescription1]
Meter=String
MeterStyle=VarDescription | RightPanel
Text=s_ColorStrokeWidth
FontFace=#s_FontFace#
Y=(-[#s_VariableYPadding])R



[VariableValue1]
Meter=String
Text=[#s_ColorStrokeWidthDefault]
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
DefaultValue=[#s_ColorStrokeWidthDefault]
Command1=[!WriteKeyValue "Variables" "s_ColorStrokeWidthDefault" "$UserInput$" "#SKINSPATH#settings\@Resources\Themes\1.inc"][#s_SaveScroll][!Refresh][&MainLua:OnChangeAction()]
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
Text=Color circle stroke width on hover 
ClipStringW=([#s_RightPanelW] - ([#s_VariableXPadding] * 2) - [VarIcon2:W])
Padding=[#s_VariableXPadding],[#s_VariableYPadding],[#s_VariableXPadding],[#s_VariableYPadding]

FontFace=#s_FontFace#

[VariableDescription2]
Meter=String
MeterStyle=VarDescription | RightPanel
Text=s_ColorStrokeWidthSelected
FontFace=#s_FontFace#
Y=(-[#s_VariableYPadding])R



[VariableValue2]
Meter=String
Text=[#s_ColorStrokeWidthSelected]
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
DefaultValue=[#s_ColorStrokeWidthSelected]
Command1=[!WriteKeyValue "Variables" "s_ColorStrokeWidthSelected" "$UserInput$" "#SKINSPATH#settings\@Resources\Themes\1.inc"][#s_SaveScroll][!Refresh][&MainLua:OnChangeAction()]
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
Text=Color circle stroke color 
ClipStringW=([#s_RightPanelW] - ([#s_VariableXPadding] * 2) - [VarIcon3:W])
Padding=[#s_VariableXPadding],[#s_VariableYPadding],[#s_VariableXPadding],[#s_VariableYPadding]

FontFace=#s_FontFace#

[VariableDescription3]
Meter=String
MeterStyle=VarDescription | RightPanel
Text=s_ColorStrokeColor (will change to s_Selected when hovered)
FontFace=#s_FontFace#
Y=(-[#s_VariableYPadding])R



[VariableContainer3]
MeterStyle=VariableContainer | RightPanel
Meter=Image
H=([ColorVariableValue3:H] > [ColorStringValue3:H]) ? [ColorVariableValue3:H] : [ColorStringValue3:H]

[ColorVariableValueContainer3]
Meter=Shape
X=[#s_VariableXPadding]r
Y=r
Shape=Ellipse ([#s_ColorSize]+[#s_ColorStrokeWidth]),([#s_ColorSize]+[#s_ColorStrokeWidth]),([#s_ColorSize]+[#s_ColorStrokeWidth]) | Fill Color 200,200,200 | StrokeWidth [#s_ColorStrokeWidth]

[ColorTransparentBackground3]
Meter=Image
ImageName=#CURRENTPATH#Addons\TrpBg
H=([#s_ColorSize]*2)
W=([#s_ColorSize]*2)
Container=ColorVariableValueContainer3

[ColorVariableValue3]
Meter=Shape
X=0
Y=0
Shape=Ellipse ([#s_ColorSize]+[#s_ColorStrokeWidth]/2),([#s_ColorSize]+[#s_ColorStrokeWidth]/2),[#s_ColorSize],[#s_ColorSize] | Fill Color [#s_ColorStrokeColor] | StrokeWidth [#s_ColorStrokeWidth] | Extend Outline
Outline=Stroke Color [#s_ColorStrokeColor]
MeterStyle=VarColor
LeftMouseUpAction=[!CommandMeasure ColorPickerUI "SetColor('s_ColorStrokeColor', 'Variables', 'rgb', [[#SKINSPATH#settings\@Resources\Themes\1.inc]])"]
Container=ColorVariableValueContainer3

[ColorStringValue3]
Meter=String
X=(2*[#s_ColorSize]+[#s_VariableXPadding]+10)
Text=[#s_ColorStrokeColor]
MeterStyle=VarString | VarColorString
FontFace=#s_FontFace#
LeftMouseUpAction=[!CommandMeasure ColorPickerUI "SetColor('s_ColorStrokeColor', 'Variables', 'rgb', [[#SKINSPATH#settings\@Resources\Themes\1.inc]])"]
Container=VariableContainer3


[VarIcon4]
Meter=String
MeterStyle=VarIcon | RightPanel
Padding=[#s_VariableXPadding],[#s_VariableIconTopPadding],[#s_VariableIconGap],0
Hidden=1

[VariableTitle4]
Meter=String
MeterStyle=VarTitle
Text=Gap between the circle and the string 
ClipStringW=([#s_RightPanelW] - ([#s_VariableXPadding] * 2) - [VarIcon4:W])
Padding=[#s_VariableXPadding],[#s_VariableYPadding],[#s_VariableXPadding],[#s_VariableYPadding]

FontFace=#s_FontFace#

[VariableDescription4]
Meter=String
MeterStyle=VarDescription | RightPanel
Text=s_ColorStringLeftPadding
FontFace=#s_FontFace#
Y=(-[#s_VariableYPadding])R



[VariableValue4]
Meter=String
Text=[#s_ColorStringLeftPadding]
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
DefaultValue=[#s_ColorStringLeftPadding]
Command1=[!WriteKeyValue "Variables" "s_ColorStringLeftPadding" "$UserInput$" "#SKINSPATH#settings\@Resources\Themes\1.inc"][#s_SaveScroll][!Refresh][&MainLua:OnChangeAction()]
OnDismissAction=[!SetOption VariableValue4 FontColor "[#s_FontColor]"][!UpdateMeter VariableValue4][!Redraw]
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


