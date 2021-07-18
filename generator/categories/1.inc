[FirstRight]
Meter=Image
MeterStyle=FirstItem | FirstRightPanel
Y=([#s_GenTopHeight])
SolidColor=0,0,0,0
W=0
H=0

[CategoryIcon0]
Meter=String
Text=
MeterStyle=RightPanel | GenIcon
[Title0]
Meter=String
Text=Generation
MeterStyle=GenTitle
W=([#s_RightPanelW] - [CategoryIcon0:W])
Padding=0,0,0,0
[CategoryDescription0]
Meter=String
Text=
MeterStyle=RightPanel | GenDesc | ThickDescription
[CategoryTitleSeparator0]
Meter=Image
MeterStyle=RightPanel | GenSeparator

[VarIcon0]
Meter=String
Text= 
MeterStyle=RightPanel | GenSmallIcon
[Var0]
Meter=String
Text=Selected file 
MeterStyle=RightPanel | GenSmallTitle
[Var0Description]
Meter=String
Text=[#s_DynamicVariableFile]
MeterStyle=RightPanel | GenDesc
; [Value0]
; Meter=String
; Text=Click to open directory
; MeterStyle=RightPanel | VarString | GenString
; LeftMouseUpAction=["#ROOTCONFIGPATH#[#s_DynamicVariableDirectory]"]

[VarIcon2]
Meter=String
Text= 
MeterStyle=RightPanel | GenSmallIcon
[Var2]
Meter=String
Text=Auto Inject
MeterStyle=RightPanel | GenSmallTitle
[Var2Description]
Meter=String
Text=Copies the generated Settings to your skin
W=([#s_GeneratorRightPanelWidth] - [#s_VariableXPadding] * 2)
MeterStyle=RightPanel | GenDesc

[VariableContainer2]
MeterStyle=RightPanel | VariableContainer
Meter=Image
H=(20 + 7)
X=r
Y=R

[ToggleOff2]
Meter=Shape
Shape=Line 0,0,(25),0 | Extend Line
Shape2=Ellipse (2.5/2),0,((20 - (2.5 * 2))/2),((20 - (2.5 * 2))/2) | Extend Circle
Circle=StrokeWidth 0 | Fill Color [#s_RightPanelBackgroundColor]
Line=StrokeWidth 20 | Stroke Color [#s_FontColor] | StrokeStartCap Round | StrokeEndCap Round
Hidden=([#s_AutoInject])
LeftMouseUpAction=[!WriteKeyValue Variables "s_AutoInject" 1][!Refresh]
MeterStyle=VarToggle
Container=VariableContainer2

[ToggleOn2]
Meter=Shape
Shape=Line 0,0,(25),0 | Extend Line
Shape2=Ellipse ((25) - (2.5/2)),0,((20 - (2.5 * 2))/2),((20 - (2.5 * 2))/2) | Extend Circle
Circle=StrokeWidth 0 | Fill Color [#s_RightPanelBackgroundColor]
Line=StrokeWidth 20 | Stroke Color [#s_ToggleActiveColor] | StrokeStartCap Round | StrokeEndCap Round
Hidden=([#s_AutoInject] - 1)
LeftMouseUpAction=[!WriteKeyValue Variables "s_AutoInject" 0][!Refresh]
MeterStyle=VarToggle
Container=VariableContainer2



[VarIcon1]
Meter=String
Text= 
MeterStyle=RightPanel | GenSmallIcon
[Var1]
Meter=String
Text=Generation 
MeterStyle=RightPanel | GenSmallTitle
[Var1Description]
Meter=String
Text=[#s_GenerateDescription[#s_AutoInject]]
W=([#s_GeneratorRightPanelWidth] - [#s_VariableXPadding] * 2)
MeterStyle=RightPanel | GenDesc

[Generate]
Meter=String
Text=[#s_GenerateText[#s_AutoInject]]
; X=62
; Y=((20 / 2) - ([#CURRENTSECTION#:H] / 2)) + ([#s_VariableYPadding])
; Container=VariableContainer2
FontSize=12
Padding=20,0,0,0
MeterStyle=RightPanel | VarString | GenString 
DynamicVariables=1
LeftMouseUpAction=[!CommandMeasure Generator Construct]
