
[MeasureRadio{Index}{Label}]
Measure=String
String=[#{Key}]
IfMatch=^{Option}$
IfMatchAction=[!SetOption RadioString{Index}{Label} InlinePattern ".*"][!SetOption RadioButton{Index}{Label} Text "[\xECCB]"][!Update][!Redraw]
[RadioButton{Index}{Label}]
Meter=String
Text=[\xECCA]
FontSize=15
MeterStyle=VariableIcon | {Container}
LeftMouseUpAction=[!WriteKeyValue Variables {Key} "{Option}" "{SettingsFile}"][#s_OnChangeAction][!Refresh]
[RadioString{Index}{Label}]
Meter=String
Text={Label}
Y=-1r
Padding=0,0,[#s_VariableXPadding],[#s_ValueYPadding]
MeterStyle=VarStringValue | VarColorString | {Container}
InlinePattern=^$
InlineSetting=Weight | 600
LeftMouseUpAction=[!WriteKeyValue Variables {Key} "{Option}" "{SettingsFile}"][#s_OnChangeAction][!Refresh]
