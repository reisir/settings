[FirstRightPanel]
Meter=String
Text=First
FontColor=0,0,0,0
MeterStyle=FirstItem | RightPanel
Y=[#s_ScrollRightPanel]

[CategoryIcon0]
Meter=String
Text=
MeterStyle=CategoryIcon | RightPanel
Y=0
Padding=[#s_CategoryTitleXPadding],[#s_CategoryTitleXPadding],0,0
[Title0]
Meter=String
Text=Settings
MeterStyle=CategoryTitle | RightPanel
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

[Var0]
Meter=String
Text=Selected file 
MeterStyle=VarTitle | RightPanel
[Var0Description]
Meter=String
Text=[#s_DynamicFilePath]
MeterStyle=VarDescription | RightPanel
[Value0]
Meter=String
Text=Click to open directory
MeterStyle=VarStringValue | RightPanel
LeftMouseUpAction=["#SKINSPATH#[#s_DynamicDirectory]"]

[Var1]
Meter=String
Text=Generation [\xE90F] 
MeterStyle=VarTitle | RightPanel
InlineSetting=Face | [#s_IconFontFace]
InlinePattern=[\xE90F]
InlineSetting2=Size | [#s_FontSize3]
InlinePattern2=[\xE90F]
[Var1Description]
Meter=String
Text=This will remove old files.
MeterStyle=VarDescription | RightPanel
[Value1]
Meter=String
Text=Generate & Inject
MeterStyle=VarStringValue | RightPanel
LeftMouseUpAction=[!CommandMeasure Generator Construct]

; [Generate]
; Meter=String
; Text=Generate & Inject
; InlineSetting=Face | [#s_IconFontFace]
; InlinePattern=[\xE90F]
; MeterStyle=Center | VarStringValue | VarTitle | RightPanel
; Y=([#s_GeneratorPanelHeight] - [Generate:H] - [#s_ValueYPadding])
; StringAlign=Center
; X=([#s_GeneratorRightPanelWidth] / 2)
; W=
; DynamicVariables=1
; Padding=10,0,10,0
; LeftMouseUpAction=

