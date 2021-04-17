[Title0]
Meter=String
Text=Settings
MeterStyle=CategoryTitle | GenRight
X=[#s_VariableXPadding]
Container=GenRightContainer

[CategoryDescription0]
Meter=String
Text=a settings skin generator skin 
MeterStyle=VarDescription | GenRight

[Var0]
Meter=String
Text=File
MeterStyle=VarTitle | GenRight
[Var0Description]
Meter=String
Text=File to process.
MeterStyle=VarDescription | GenRight
[Value0]
Meter=String
Text=[&MeasureSkin]\[#s_File].[#s_Type]
MeterStyle=VarStringValue | GenRight
ToolTipTitle=Full path:
ToolTipText=[#s_SettingsFile]

[Generate]
Meter=String
Text=Generate
InlineSetting=Face | [#s_IconFontFace]
InlinePattern=[\xE90F]
MeterStyle=Center | CategoryTitle | GenRight
Y=([#s_GeneratorPanelHeight] - [Generate:H] - [#s_VariablePadding])
LeftMouseUpAction=[!CommandMeasure Generator Construct][!Delay 1][!RefreshApp]

;[GenerateIcon]
;Meter=String
;Text=[\xE90F]
;MeterStyle=CategoryIcon | Left | GenRight
;X=(-([GenerateIcon:W] + ([Generate:W] / 2)))r
;DynamicVariables=1
;FontSize=[#s_FontSize2]
;Y=(([Generate:H] - [GenerateIcon:H]) / 2)r

