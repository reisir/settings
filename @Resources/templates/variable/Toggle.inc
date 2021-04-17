[Var{Index}]
Meter=String
Text={Name}
MeterStyle=VarTitle | {Container}
[Var{Index}Description]
Meter=String
Text={Description}
MeterStyle=VarDescription | {Container}

[ToggleOn{Index}]
Meter=Shape
Shape=Line 0,0,([#s_ToggleLength]),0 | Extend Line
Shape2=Ellipse ([#s_TogglePadding]/2),0,(([#s_ToggleSize] - ([#s_TogglePadding] * 2))/2),(([#s_ToggleSize] - ([#s_TogglePadding] * 2))/2) | Extend Circle
Circle=StrokeWidth 0 | Fill Color [#s_RightPanelBackgroundColor]
Line=StrokeWidth [#s_ToggleSize] | Stroke Color [#s_ToggleActiveColor] | StrokeStartCap Round | StrokeEndCap Round
Hidden=([#{RealName}] - 1)
Y=([Var{Index}Description:Y] + [Var{Index}Description:H] + ([#s_ToggleSize] / 2) + [#s_VariableTopPadding])
MeterStyle=VarToggleValue | {Container}
LeftMouseUpAction=[!WriteKeyValue Variables "{RealName}" 0 "{SettingsFile}"][!SetVariable "{RealName}" 0][!Update][!Redraw][!Log "Toggled {Name} off"]

[ToggleOff{Index}]
Meter=Shape
Shape=Line 0,0,([#s_ToggleLength]),0 | Extend Line
Shape2=Ellipse (([#s_ToggleLength]) - ([#s_TogglePadding]/2)),0,(([#s_ToggleSize] - ([#s_TogglePadding] * 2))/2),(([#s_ToggleSize] - ([#s_TogglePadding] * 2))/2) | Extend Circle
Circle=StrokeWidth 0 | Fill Color [#s_RightPanelBackgroundColor]
Line=StrokeWidth [#s_ToggleSize] | Stroke Color [#s_FontColor] | StrokeStartCap Round | StrokeEndCap Round
Hidden=([#{RealName}])
Y=([Var{Index}Description:Y] + [Var{Index}Description:H] + ([#s_ToggleSize] / 2) + [#s_VariableTopPadding])
MeterStyle=VarToggleValue | {Container}
LeftMouseUpAction=[!WriteKeyValue Variables "{RealName}" 1 "{SettingsFile}"][!SetVariable "{RealName}" 1][!Update][!Redraw][!Log "Toggled {Name} on"]

[ClearFloat{Index}]
Meter=Image
W=100
H=([#s_VariableTopPadding] + [#s_ToggleSize])
MeterStyle={Container}
Y=([Var{Index}Description:Y] + [Var{Index}Description:H])
DynamicVariables=1
