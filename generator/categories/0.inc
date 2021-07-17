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
Padding=[#s_CategoryTitleXPadding],[#s_CategoryIconTopPadding],0,0
[Title0]
Meter=String
Text=Settings
MeterStyle=GenTitle
W=([#s_RightPanelW] - [CategoryIcon0:W])
Padding=0,0,0,0
[CategoryDescription0]
Meter=String
Text=a skin that generates settings skins for other skins.
MeterStyle=VarDescription | ThickDescription | RightPanel
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
[Value0]
Meter=String
Text=Click to open directory
MeterStyle=RightPanel | VarString
LeftMouseUpAction=["#ROOTCONFIGPATH#[#s_DynamicVariableDirectory]"]

[VarIcon1]
Meter=String
Text=[\xE90F] 
MeterStyle=RightPanel | GenSmallIcon
FontSize=14
[Var1]
Meter=String
Text=Generation 
MeterStyle=RightPanel | GenSmallTitle
[Var1Description]
Meter=String
Text=This will delete all files in "[#s_Skin]\settings" and copy over the generated settings skin.
W=([#s_GeneratorRightPanelWidth] - [#s_VariableXPadding] * 2)
MeterStyle=RightPanel | GenDesc
[Value1]
Meter=String
Text=Generate & Inject
MeterStyle=RightPanel | VarString
LeftMouseUpAction=[!CommandMeasure Generator Construct]


