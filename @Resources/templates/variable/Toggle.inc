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
Y=([#s_VariablePadding])R
MeterStyle=VarToggleValue | {Container}
LeftMouseUpAction=[!WriteKeyValue Variables "{RealName}" 0 "{SettingsFile}"][!SetOption "ToggleOff{Index}" Hidden 0][!SetOption "ClearFloat{Index}" Hidden 1][!UpdateMeter "ToggleOff{Index}"][!SetOption "ToggleOn{Index}" Hidden 0][!UpdateMeter "ToggleOn{Index}"][!Redraw][!Log "Toggled {Name} off"]
[ToggleOff{Index}]
Meter=Shape
Shape=Line 0,0,([#s_ToggleLength]),0 | Extend Line
Shape2=Ellipse (([#s_ToggleLength]) - ([#s_TogglePadding]/2)),0,(([#s_ToggleSize] - ([#s_TogglePadding] * 2))/2),(([#s_ToggleSize] - ([#s_TogglePadding] * 2))/2) | Extend Circle
Circle=StrokeWidth 0 | Fill Color [#s_RightPanelBackgroundColor]
Line=StrokeWidth [#s_ToggleSize] | Stroke Color [#s_FontColor] | StrokeStartCap Round | StrokeEndCap Round
Hidden=([#{RealName}])
Y=0r
MeterStyle=VarToggleValue | {Container}
LeftMouseUpAction=[!WriteKeyValue Variables "{RealName}" 1 "{SettingsFile}"][!SetOption "ToggleOff{Index}" Hidden 1][!SetOption "ClearFloat{Index}" Hidden 0][!UpdateMeter "ToggleOff{Index}"][!SetOption "ToggleOn{Index}" Hidden 1][!UpdateMeter "ToggleOn{Index}"][!Redraw][!Log "Toggled {Name} on"]
[ClearFloat{Index}]
Meter=Image
W=10
H=([#s_VariablePadding])
Hidden=([#{RealName}] - 1)
SolidColor=255,0,0
MeterStyle={Container}
X=0r
Y=0R

