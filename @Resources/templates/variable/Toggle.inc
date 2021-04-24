[VariableIcon{Index}]
Meter=String
Text={Icon}
MeterStyle=VariableIcon | {Container}
Hidden={Hidden}
[VariableTitle{Index}]
Meter=String
Text={Name}
MeterStyle=VarTitle | {Container}
[VariableDescription{Index}]
Meter=String
Text={Description}
MeterStyle=VarDescription | {Container}

[ToggleOff{Index}]
Meter=Shape
Shape=Line 0,0,([#s_ToggleLength]),0 | Extend Line
Shape2=Ellipse ([#s_TogglePadding]/2),0,(([#s_ToggleSize] - ([#s_TogglePadding] * 2))/2),(([#s_ToggleSize] - ([#s_TogglePadding] * 2))/2) | Extend Circle
Circle=StrokeWidth 0 | Fill Color [#s_RightPanelBackgroundColor]
Line=StrokeWidth [#s_ToggleSize] | Stroke Color [#s_FontColor] | StrokeStartCap Round | StrokeEndCap Round
Hidden=([#{Key}])
Y=([VariableDescription{Index}:Y] + [VariableDescription{Index}:H] + ([#s_ToggleSize] / 2) + [#s_ValueYPadding])
MeterStyle=VarToggleValue | {Container}
LeftMouseUpAction=[!WriteKeyValue Variables "{Key}" 1 "{SettingsFile}"][!SetVariable "{Key}" 1][!Update][!Redraw][#s_OnChangeAction]

[ToggleOn{Index}]
Meter=Shape
Shape=Line 0,0,([#s_ToggleLength]),0 | Extend Line
Shape2=Ellipse (([#s_ToggleLength]) - ([#s_TogglePadding]/2)),0,(([#s_ToggleSize] - ([#s_TogglePadding] * 2))/2),(([#s_ToggleSize] - ([#s_TogglePadding] * 2))/2) | Extend Circle
Circle=StrokeWidth 0 | Fill Color [#s_RightPanelBackgroundColor]
Line=StrokeWidth [#s_ToggleSize] | Stroke Color [#s_ToggleActiveColor] | StrokeStartCap Round | StrokeEndCap Round
Hidden=([#{Key}] - 1)
Y=([VariableDescription{Index}:Y] + [VariableDescription{Index}:H] + ([#s_ToggleSize] / 2) + [#s_ValueYPadding])
MeterStyle=VarToggleValue | {Container}
LeftMouseUpAction=[!WriteKeyValue Variables "{Key}" 0 "{SettingsFile}"][!SetVariable "{Key}" 0][!Update][!Redraw][#s_OnChangeAction]

[ClearFloat{Index}]
Meter=Image
W=[#s_RightPanelW]
H=([#s_ValueYPadding] + [#s_ToggleSize] + [#s_ValueYPadding])
MeterStyle={Container}
Y=([VariableDescription{Index}:Y] + [VariableDescription{Index}:H])
DynamicVariables=1

