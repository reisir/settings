[FirstRight]
Meter=String
Text=First
FontColor=0,0,0,0
MeterStyle=FirstItem | FirstRightPanel
Y=[#s_ScrollRight]

[CategoryIcon0]
Meter=String
Text=
MeterStyle=CategoryIcon | RightPanel
Y=0
Padding=[#s_CategoryTitleXPadding],[#s_CategoryTitleXPadding],0,0
[Title0]
Meter=String
Text=Settings
MeterStyle=CategoryTitle
W=([#s_RightPanelW] - [CategoryIcon0:W])
Padding=0,[#s_CategoryTitleXPadding],0,0
[CategoryDescription0]
Meter=String
Text=a skin that generates settings skins for other skins.
MeterStyle=VarDescription | RightPanel
[CategoryTitleSeparator1]
Meter=Image
MeterStyle=CategoryTitleSeparator | RightPanel
H=([#s_CategoryTitleBottomPadding] / 2)

[VariableIcon0]
Meter=String
Text=
MeterStyle=VariableIcon | RightPanel
[Var0]
Meter=String
Text=Selected file 
MeterStyle=VarTitle | RightPanel
[Var0Description]
Meter=String
Text=[#s_DynamicVariableFile]
MeterStyle=VarDescription | RightPanel
[Value0]
Meter=String
Text=Click to open directory
MeterStyle=VarString | RightPanel
LeftMouseUpAction=["#ROOTCONFIGPATH#[#s_DynamicVariableDirectory]"]


[VariableIcon1]
Meter=String
Text=[\xE90F] 
MeterStyle=VariableIcon | RightPanel
FontSize=14
Y=5R
[Var1]
Meter=String
Text=Generation 
MeterStyle=VarTitle | RightPanel
Y=-5r
[Var1Description]
Meter=String
Text=This will delete all files in "[#s_Skin]\settings" and copy over the generated settings skin.
W=([#s_GeneratorRightPanelWidth] - [#s_VariableXPadding] * 2)
MeterStyle=VarDescription | RightPanel
[Value1]
Meter=String
Text=Generate & Inject
MeterStyle=VarString | RightPanel
LeftMouseUpAction=[!CommandMeasure Generator Construct]

; [Generate]
; Meter=String
; Text=Generate & Inject
; InlineSetting=Face | [#s_IconFontFace]
; InlinePattern=[\xE90F]
; MeterStyle=Center | VarString | VarTitle | RightPanel
; Y=([#s_GeneratorPanelHeight] - [Generate:H] - [#s_VariableYPadding])
; StringAlign=Center
; X=([#s_GeneratorRightPanelWidth] / 2)
; W=
; DynamicVariables=1
; Padding=10,0,10,0
; LeftMouseUpAction=

