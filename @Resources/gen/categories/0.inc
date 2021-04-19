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

[Title0]
Meter=String
Text=Settings 
MeterStyle=CategoryTitle | RightPanel
W=([#s_RightPanelW] - [CategoryIcon0:W])

[CategoryDescription0]
Meter=String
Text=a settings skin generator skin
MeterStyle=VarDescription | RightPanel

[CategoryTitleSeparator0]
Meter=Image
MeterStyle=CategoryTitleSeparator | RightPanel

[Var0]
Meter=String
Text=File 
MeterStyle=VarTitle | RightPanel
[Var0Description]
Meter=String
Text=File to process.
MeterStyle=VarDescription | RightPanel
[Value0]
Meter=String
Text=[&MeasureSkin]\[#s_File].[#s_Type]
MeterStyle=VarStringValue | RightPanel
LeftMouseUpAction=["[#s_Directory]"]
Hidden=

[Generate]
Meter=String
Text=Generate
InlineSetting=Face | [#s_IconFontFace]
InlinePattern=[\xE90F]
MeterStyle=Center | VarStringValue | VarTitle | RightPanel
Y=([#s_GeneratorPanelHeight] - [Generate:H] - [#s_ValueYPadding])
StringAlign=Center
X=(([#s_GeneratorRightPanelWidth] / 2) - (([Generate:W] + [Open:W]) / 2) + [Generate:W] / 2)
W=
DynamicVariables=1
Padding=10,0,10,0
LeftMouseUpAction=[!CommandMeasure Generator Construct][!Delay 1][!RefreshApp]

[Open]
Meter=String
Text=Open skin
InlineSetting=Face | [#s_IconFontFace]
InlinePattern=[\xE90F]
MeterStyle=Center | VarStringValue | VarTitle | RightPanel
Y=([#s_GeneratorPanelHeight] - [Generate:H] - [#s_ValueYPadding])
StringAlign=Center
Padding=10,0,10,0
W=
X=R
DynamicVariables=1
LeftMouseUpAction=[!ActivateConfig "Settings\settings" "settings.ini"]
