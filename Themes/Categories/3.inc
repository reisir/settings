[FirstRight]
Meter=Image
MeterStyle=FirstItem | FirstRightPanel
Y=([#s_ScrollRight] + [#s_TopHeight])
SolidColor=0,0,0,0
W=0
H=0

[CategoryIcon3]
Meter=String
Text=
MeterStyle=CategoryIcon | RightPanel

[Title3]
Meter=String
Text=Background
MeterStyle=CategoryTitle
W=([#s_RightPanelW] - [CategoryIcon3:W])

[CategoryDescription3]
Meter=String
Text=
MeterStyle=VarDescription | ThickDescription | RightPanel

[CategoryTitleSeparator3]
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
Text=Left panel width 
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
Text=[#s_LeftPanelW]
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
DefaultValue=[#s_LeftPanelW]
Command1=[!WriteKeyValue "Variables" "s_LeftPanelW" "$UserInput$" "#SKINSPATH#settings\@Resources\Themes\1.inc"][#s_SaveScroll][!Refresh][&MainLua:OnChangeAction()]
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
Text=Right panel width 
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
Text=[#s_RightPanelW]
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
DefaultValue=[#s_RightPanelW]
Command1=[!WriteKeyValue "Variables" "s_RightPanelW" "$UserInput$" "#SKINSPATH#settings\@Resources\Themes\1.inc"][#s_SaveScroll][!Refresh][&MainLua:OnChangeAction()]
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
Text=Skin height 
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
Text=[#s_PanelH]
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
DefaultValue=[#s_PanelH]
Command1=[!WriteKeyValue "Variables" "s_PanelH" "$UserInput$" "#SKINSPATH#settings\@Resources\Themes\1.inc"][#s_SaveScroll][!Refresh][&MainLua:OnChangeAction()]
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
Text=Right panel background color 
ClipStringW=([#s_RightPanelW] - ([#s_VariableXPadding] * 2) - [VarIcon3:W])
Padding=[#s_VariableXPadding],[#s_VariableYPadding],[#s_VariableXPadding],[#s_VariableYPadding]

FontFace=#s_FontFace#

[VariableDescription3]
Meter=String
MeterStyle=VarDescription | RightPanel
Text=
FontFace=#s_FontFace#



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
Shape=Ellipse ([#s_ColorSize]+[#s_ColorStrokeWidth]/2),([#s_ColorSize]+[#s_ColorStrokeWidth]/2),[#s_ColorSize],[#s_ColorSize] | Fill Color [#s_RightPanelBackgroundColor] | StrokeWidth [#s_ColorStrokeWidth] | Extend Outline
Outline=Stroke Color [#s_ColorStrokeColor]
MeterStyle=VarColor
LeftMouseUpAction=[!CommandMeasure ColorPickerUI "SetColor('s_RightPanelBackgroundColor', 'Variables', 'rgba', [[#SKINSPATH#settings\@Resources\Themes\1.inc]])"]
Container=ColorVariableValueContainer3

[ColorStringValue3]
Meter=String
X=(2*[#s_ColorSize]+[#s_VariableXPadding]+10)
Text=[#s_RightPanelBackgroundColor]
MeterStyle=VarString | VarColorString
FontFace=#s_FontFace#
LeftMouseUpAction=[!CommandMeasure ColorPickerUI "SetColor('s_RightPanelBackgroundColor', 'Variables', 'rgba', [[#SKINSPATH#settings\@Resources\Themes\1.inc]])"]
Container=VariableContainer3


[VarIcon4]
Meter=String
MeterStyle=VarIcon | RightPanel
Padding=[#s_VariableXPadding],[#s_VariableIconTopPadding],[#s_VariableIconGap],0
Hidden=1

[VariableTitle4]
Meter=String
MeterStyle=VarTitle
Text=Left panel background color 
ClipStringW=([#s_RightPanelW] - ([#s_VariableXPadding] * 2) - [VarIcon4:W])
Padding=[#s_VariableXPadding],[#s_VariableYPadding],[#s_VariableXPadding],[#s_VariableYPadding]

FontFace=#s_FontFace#

[VariableDescription4]
Meter=String
MeterStyle=VarDescription | RightPanel
Text=
FontFace=#s_FontFace#



[VariableContainer4]
MeterStyle=VariableContainer | RightPanel
Meter=Image
H=([ColorVariableValue4:H] > [ColorStringValue4:H]) ? [ColorVariableValue4:H] : [ColorStringValue4:H]

[ColorVariableValueContainer4]
Meter=Shape
X=[#s_VariableXPadding]r
Y=r
Shape=Ellipse ([#s_ColorSize]+[#s_ColorStrokeWidth]),([#s_ColorSize]+[#s_ColorStrokeWidth]),([#s_ColorSize]+[#s_ColorStrokeWidth]) | Fill Color 200,200,200 | StrokeWidth [#s_ColorStrokeWidth]

[ColorTransparentBackground4]
Meter=Image
ImageName=#CURRENTPATH#Addons\TrpBg
H=([#s_ColorSize]*2)
W=([#s_ColorSize]*2)
Container=ColorVariableValueContainer4

[ColorVariableValue4]
Meter=Shape
X=0
Y=0
Shape=Ellipse ([#s_ColorSize]+[#s_ColorStrokeWidth]/2),([#s_ColorSize]+[#s_ColorStrokeWidth]/2),[#s_ColorSize],[#s_ColorSize] | Fill Color [#s_LeftPanelBackgroundColor] | StrokeWidth [#s_ColorStrokeWidth] | Extend Outline
Outline=Stroke Color [#s_ColorStrokeColor]
MeterStyle=VarColor
LeftMouseUpAction=[!CommandMeasure ColorPickerUI "SetColor('s_LeftPanelBackgroundColor', 'Variables', 'rgba', [[#SKINSPATH#settings\@Resources\Themes\1.inc]])"]
Container=ColorVariableValueContainer4

[ColorStringValue4]
Meter=String
X=(2*[#s_ColorSize]+[#s_VariableXPadding]+10)
Text=[#s_LeftPanelBackgroundColor]
MeterStyle=VarString | VarColorString
FontFace=#s_FontFace#
LeftMouseUpAction=[!CommandMeasure ColorPickerUI "SetColor('s_LeftPanelBackgroundColor', 'Variables', 'rgba', [[#SKINSPATH#settings\@Resources\Themes\1.inc]])"]
Container=VariableContainer4


[VarIcon5]
Meter=String
MeterStyle=VarIcon | RightPanel
Padding=[#s_VariableXPadding],[#s_VariableIconTopPadding],[#s_VariableIconGap],0
Hidden=1

[VariableTitle5]
Meter=String
MeterStyle=VarTitle
Text=Background corner radius
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
Text=[#s_BackgroundRounding]
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
DefaultValue=[#s_BackgroundRounding]
Command1=[!WriteKeyValue "Variables" "s_BackgroundRounding" "$UserInput$" "#SKINSPATH#settings\@Resources\Themes\1.inc"][#s_SaveScroll][!Refresh][&MainLua:OnChangeAction()]
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
Text=FrostedGlass mode 
ClipStringW=([#s_RightPanelW] - ([#s_VariableXPadding] * 2) - [VarIcon6:W])
Padding=[#s_VariableXPadding],[#s_VariableYPadding],[#s_VariableXPadding],[#s_VariableYPadding]

FontFace=#s_FontFace#

[VariableDescription6]
Meter=String
MeterStyle=VarDescription | RightPanel
Text=Only available on Windows 10#CRLF#A certain Windows 10 update made Acrylic very laggy so it's not recommended.
FontFace=#s_FontFace#
Y=(-[#s_VariableYPadding])R


[RadioButton6None]
Meter=String
Text=[[&MainLua:Ternary('[#s_FrostedGlassMode]', '=', 'None', '\xECCB', '\xECCA')]]
X=([#s_LeftPanelW]+[#s_VariableXPadding])
Y=[#s_VariableYPadding]R
FontSize=15
MeterStyle=ListIcon | RightPanel
Group=RadioButton6
DynamicVariables=1
LeftMouseUpAction=[!SetVariable s_FrostedGlassMode "None"][!WriteKeyValue Variables s_FrostedGlassMode "None" "#SKINSPATH#settings\@Resources\Themes\1.inc"][!UpdateMeterGroup "RadioButton6"][#s_SaveScroll][!Update][!Redraw][&MainLua:OnChangeAction()]

[RadioString6None]
Meter=String
Text=None
X=5R
Y=-1r
FontWeight=([&MainLua:Ternary('[#s_FrostedGlassMode]', '=', 'None', '600', '400')]=0 ? 400 : [&MainLua:Ternary('[#s_FrostedGlassMode]', '=', 'None', '600', '400')])
Padding=0,0,[#s_VariableXPadding],[#s_VariableYPadding]
MeterStyle=VarString | VarColorString
Group=RadioButton6
DynamicVariables=1
LeftMouseUpAction=[!SetVariable s_FrostedGlassMode "None"][!WriteKeyValue Variables s_FrostedGlassMode "None" "#SKINSPATH#settings\@Resources\Themes\1.inc"][!UpdateMeterGroup "RadioButton6"][#s_SaveScroll][!Update][!Redraw][&MainLua:OnChangeAction()]

[RadioButton6Blur]
Meter=String
Text=[[&MainLua:Ternary('[#s_FrostedGlassMode]', '=', 'Blur', '\xECCB', '\xECCA')]]
X=([#s_LeftPanelW]+[#s_VariableXPadding])
Y=[#s_VariableYPadding]R
FontSize=15
MeterStyle=ListIcon | RightPanel
Group=RadioButton6
DynamicVariables=1
LeftMouseUpAction=[!SetVariable s_FrostedGlassMode "Blur"][!WriteKeyValue Variables s_FrostedGlassMode "Blur" "#SKINSPATH#settings\@Resources\Themes\1.inc"][!UpdateMeterGroup "RadioButton6"][#s_SaveScroll][!Update][!Redraw][&MainLua:OnChangeAction()]

[RadioString6Blur]
Meter=String
Text=Blur
X=5R
Y=-1r
FontWeight=([&MainLua:Ternary('[#s_FrostedGlassMode]', '=', 'Blur', '600', '400')]=0 ? 400 : [&MainLua:Ternary('[#s_FrostedGlassMode]', '=', 'Blur', '600', '400')])
Padding=0,0,[#s_VariableXPadding],[#s_VariableYPadding]
MeterStyle=VarString | VarColorString
Group=RadioButton6
DynamicVariables=1
LeftMouseUpAction=[!SetVariable s_FrostedGlassMode "Blur"][!WriteKeyValue Variables s_FrostedGlassMode "Blur" "#SKINSPATH#settings\@Resources\Themes\1.inc"][!UpdateMeterGroup "RadioButton6"][#s_SaveScroll][!Update][!Redraw][&MainLua:OnChangeAction()]

[RadioButton6Acrylic]
Meter=String
Text=[[&MainLua:Ternary('[#s_FrostedGlassMode]', '=', 'Acrylic', '\xECCB', '\xECCA')]]
X=([#s_LeftPanelW]+[#s_VariableXPadding])
Y=[#s_VariableYPadding]R
FontSize=15
MeterStyle=ListIcon | RightPanel
Group=RadioButton6
DynamicVariables=1
LeftMouseUpAction=[!SetVariable s_FrostedGlassMode "Acrylic"][!WriteKeyValue Variables s_FrostedGlassMode "Acrylic" "#SKINSPATH#settings\@Resources\Themes\1.inc"][!UpdateMeterGroup "RadioButton6"][#s_SaveScroll][!Update][!Redraw][&MainLua:OnChangeAction()]

[RadioString6Acrylic]
Meter=String
Text=Acrylic
X=5R
Y=-1r
FontWeight=([&MainLua:Ternary('[#s_FrostedGlassMode]', '=', 'Acrylic', '600', '400')]=0 ? 400 : [&MainLua:Ternary('[#s_FrostedGlassMode]', '=', 'Acrylic', '600', '400')])
Padding=0,0,[#s_VariableXPadding],[#s_VariableYPadding]
MeterStyle=VarString | VarColorString
Group=RadioButton6
DynamicVariables=1
LeftMouseUpAction=[!SetVariable s_FrostedGlassMode "Acrylic"][!WriteKeyValue Variables s_FrostedGlassMode "Acrylic" "#SKINSPATH#settings\@Resources\Themes\1.inc"][!UpdateMeterGroup "RadioButton6"][#s_SaveScroll][!Update][!Redraw][&MainLua:OnChangeAction()]




[VarIcon7]
Meter=String
MeterStyle=VarIcon | RightPanel
Padding=[#s_VariableXPadding],[#s_VariableIconTopPadding],[#s_VariableIconGap],0
Hidden=1

[VariableTitle7]
Meter=String
MeterStyle=VarTitle
Text=FrostedGlass border 
ClipStringW=([#s_RightPanelW] - ([#s_VariableXPadding] * 2) - [VarIcon7:W])
Padding=[#s_VariableXPadding],[#s_VariableYPadding],[#s_VariableXPadding],[#s_VariableYPadding]

FontFace=#s_FontFace#

[VariableDescription7]
Meter=String
MeterStyle=VarDescription | RightPanel
Text=All, None, Left, Right, Top and Bottom. Can be combined with pipes
FontFace=#s_FontFace#
Y=(-[#s_VariableYPadding])R



[VariableValue7]
Meter=String
Text=[#s_FrostedGlassBorders]
MeterStyle=VarString | RightPanel
FontFace=#s_FontFace#
LeftMouseUpAction=[!CommandMeasure "InputText7" "ExecuteBatch All"][!SetOption #CURRENTSECTION# FontColor "0,0,0,0"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[InputText7]
Measure=Plugin
Plugin=InputText
SolidColor=[#s_RightPanelBackgroundColor]
FontColor=#s_FontColor#
FontFace=#s_FontFace#
FontSize=#s_InputTextFontSize#
X=([VariableValue7:X] + [#s_VariableXPadding])
Y=([VariableValue7:Y] + [#s_VariableYPadding])
H=[VariableValue7:H]
W=([#s_RightPanelW] - ([#s_VariableXPadding] * 2))
DynamicVariables=1
DefaultValue=[#s_FrostedGlassBorders]
Command1=[!WriteKeyValue "Variables" "s_FrostedGlassBorders" "$UserInput$" "#SKINSPATH#settings\@Resources\Themes\1.inc"][#s_SaveScroll][!Refresh][&MainLua:OnChangeAction()]
OnDismissAction=[!SetOption VariableValue7 FontColor "[#s_FontColor]"][!UpdateMeter VariableValue7][!Redraw]

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


