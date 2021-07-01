param (
    [Parameter()]
    [System.Collections.Hashtable]
    $Variable,
    [Parameter()]
    [System.Collections.Hashtable]
    $Options
)

$ini = @"
[VariableIcon$($Variable.Index)]
Meter=String
Text=$($Variable.Icon)
MeterStyle=VariableIcon | $($Options.Container)

[VariableTitle$($Variable.Index)]
Meter=String
Text=$($Variable.Name)
MeterStyle=VarTitle | $($Options.Container)

[VariableDescription$($Variable.Index)]
Meter=String
Text=$($Variable.Description)
MeterStyle=VarDescription | $($Options.Container)

[ToggleOff$($Variable.Index)]
Meter=Shape
Shape=Line 0,0,([#s_ToggleLength]),0 | Extend Line
Shape2=Ellipse ([#s_TogglePadding]/2),0,(([#s_ToggleSize] - ([#s_TogglePadding] * 2))/2),(([#s_ToggleSize] - ([#s_TogglePadding] * 2))/2) | Extend Circle
Circle=StrokeWidth 0 | Fill Color [#s_RightPanelBackgroundColor]
Line=StrokeWidth [#s_ToggleSize] | Stroke Color [#s_FontColor] | StrokeStartCap Round | StrokeEndCap Round
Hidden=([#$($Variable.Key)])
Y=([VariableDescription$($Variable.Index):Y] + [VariableDescription$($Variable.Index):H] + ([#s_ToggleSize] / 2) + [#s_ValueYPadding])
MeterStyle=VarToggleValue | $($Options.Container)
LeftMouseUpAction=[!WriteKeyValue Variables "$($Variable.Key)" 1 "$($Options.SettingsFile)"][!SetVariable "$($Variable.Key)" 1][!Update][!Redraw][#s_OnChangeAction]

[ToggleOn$($Variable.Index)]
Meter=Shape
Shape=Line 0,0,([#s_ToggleLength]),0 | Extend Line
Shape2=Ellipse (([#s_ToggleLength]) - ([#s_TogglePadding]/2)),0,(([#s_ToggleSize] - ([#s_TogglePadding] * 2))/2),(([#s_ToggleSize] - ([#s_TogglePadding] * 2))/2) | Extend Circle
Circle=StrokeWidth 0 | Fill Color [#s_RightPanelBackgroundColor]
Line=StrokeWidth [#s_ToggleSize] | Stroke Color [#s_ToggleActiveColor] | StrokeStartCap Round | StrokeEndCap Round
Hidden=([#$($Variable.Key)] - 1)
Y=([VariableDescription$($Variable.Index):Y] + [VariableDescription$($Variable.Index):H] + ([#s_ToggleSize] / 2) + [#s_ValueYPadding])
MeterStyle=VarToggleValue | $($Options.Container)
LeftMouseUpAction=[!WriteKeyValue Variables "$($Variable.Key)" 0 "$($Options.SettingsFile)"][!SetVariable "$($Variable.Key)" 0][!Update][!Redraw][#s_OnChangeAction]

[ClearFloat$($Variable.Index)]
Meter=Image
W=[#s_RightPanelW]
H=([#s_ValueYPadding] + [#s_ToggleSize] + [#s_ValueYPadding])
MeterStyle=$($Options.Container)
Y=([VariableDescription$($Variable.Index):Y] + [VariableDescription$($Variable.Index):H])
DynamicVariables=1


"@

return $ini