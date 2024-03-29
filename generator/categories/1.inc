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
Y=20R
Text= 
MeterStyle=RightPanel | GenSmallIcon
[Var0]
Meter=String
Text=Selected file
MeterStyle=RightPanel | GenSmallTitle
[Var0Description]
Meter=String
Text=
W=([#s_GeneratorRightPanelWidth] - [#s_VariableXPadding] * 2)
MeterStyle=RightPanel | GenDesc
[Value0]
Meter=String
Text=[#s_DynamicVariableFile]
MeterStyle=RightPanel | VarString
MouseOverAction=[]
MouseLeaveAction=[]

[SelectFile]
Meter=Shape
X=20r
Y=5R
Shape=Rectangle 0,0,([Select:W]+10),([Select:H]+10),5 | Fill Color 1975FF | StrokeWidth 0
DynamicVariables=1
LeftMouseUpAction=[!CommandMeasure FileChoose "ChooseFile 1"]

[Select]
Meter=String
Text=Select
X=5r
Y=6r
FontWeight=600
FontSize=12
Padding=0,0,0,0
MeterStyle=RightPanel | VarString 
DynamicVariables=1
MouseOverAction=[]
MouseLeaveAction=[]

[DropInfo]
Meter=String
Text=[\xE82F]
FontFace=Segoe MDL2 Assets
X=10R
Y=3r
FontWeight=500
FontSize=12
Padding=0,0,0,0
MeterStyle=RightPanel | VarString 
DynamicVariables=1
MouseOverAction=[]
MouseLeaveAction=[]
ToolTipText=You can drop a file too!

[VarIcon2]
Meter=String
Y=15R
Text= 
MeterStyle=RightPanel | GenSmallIcon
[Var2]
Meter=String
Text=Auto Inject
MeterStyle=RightPanel | GenSmallTitle
[Var2Description]
Meter=String
Text=Replaces [#s_Skin]\Settings directory
W=([#s_GeneratorRightPanelWidth] - [#s_VariableXPadding] * 2)
ClipString=1
MeterStyle=RightPanel | GenDesc
InlinePattern=.*
InlineSetting=Weight | 500
InlinePattern2=^(Replaces)\s.+\s(directory)$
InlineSetting2=Color | 238, 35, 13

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
Y=40R
Text= 
MeterStyle=RightPanel | GenSmallIcon

[GeneratorButton]
Meter=Shape
X=20r
Y=305
Shape=Rectangle 0,0,([Generate:W]+10),([Generate:H]+10),5 | Fill Color 1975FF | StrokeWidth 0
DynamicVariables=1
LeftMouseUpAction=[!CommandMeasure Generator Construct]

[Generate]
Meter=String
Text=[#s_GenerateText[#s_AutoInject]]
X=5r
Y=6r
FontWeight=600
FontSize=12
Padding=0,0,0,0
MeterStyle=RightPanel | VarString 
DynamicVariables=1
MouseOverAction=[]
MouseLeaveAction=[]
LeftMouseUpAction=[!CommandMeasure Generator Construct]