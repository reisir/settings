param (
    [Parameter()]
    [System.Collections.Hashtable]
    $Variable,
    [Parameter()]
    [System.Collections.Hashtable]
    $Options
)

$ini = @"
[VariableIcon$($Options.Index)]
Meter=String
Text=$($Variable.Properties.Icon)
MeterStyle=VariableIcon | $($Options.Container)

[VariableTitle$($Options.Index)]
Meter=String
Text=$($Variable.Properties.Name)
MeterStyle=VarTitle | $($Options.Container)

[VariableDescription$($Options.Index)]
Meter=String
Text=$($Variable.Properties.Description)
MeterStyle=VarDescription | $($Options.Container)

[ToggleOff$($Options.Index)]
Meter=Shape
Shape=Line 0,0,([#s_ToggleLength]),0 | Extend Line
Shape2=Ellipse ([#s_TogglePadding]/2),0,(([#s_ToggleSize] - ([#s_TogglePadding] * 2))/2),(([#s_ToggleSize] - ([#s_TogglePadding] * 2))/2) | Extend Circle
Circle=StrokeWidth 0 | Fill Color [#s_RightPanelBackgroundColor]
Line=StrokeWidth [#s_ToggleSize] | Stroke Color [#s_FontColor] | StrokeStartCap Round | StrokeEndCap Round
Hidden=([#$($Variable.Key)])
Y=([VariableDescription$($Options.Index):Y] + [VariableDescription$($Options.Index):H] + ([#s_ToggleSize] / 2) + [#s_ValueYPadding])
MeterStyle=VarToggleValue | $($Options.Container)
LeftMouseUpAction=[!WriteKeyValue Variables "$($Variable.Key)" 1 "$($Options.SettingsFile)"][!SetVariable "$($Variable.Key)" 1][!Update][!Redraw][#s_OnChangeAction]

[ToggleOn$($Options.Index)]
Meter=Shape
Shape=Line 0,0,([#s_ToggleLength]),0 | Extend Line
Shape2=Ellipse (([#s_ToggleLength]) - ([#s_TogglePadding]/2)),0,(([#s_ToggleSize] - ([#s_TogglePadding] * 2))/2),(([#s_ToggleSize] - ([#s_TogglePadding] * 2))/2) | Extend Circle
Circle=StrokeWidth 0 | Fill Color [#s_RightPanelBackgroundColor]
Line=StrokeWidth [#s_ToggleSize] | Stroke Color [#s_ToggleActiveColor] | StrokeStartCap Round | StrokeEndCap Round
Hidden=([#$($Variable.Key)] - 1)
Y=([VariableDescription$($Options.Index):Y] + [VariableDescription$($Options.Index):H] + ([#s_ToggleSize] / 2) + [#s_ValueYPadding])
MeterStyle=VarToggleValue | $($Options.Container)
LeftMouseUpAction=[!WriteKeyValue Variables "$($Variable.Key)" 0 "$($Options.SettingsFile)"][!SetVariable "$($Variable.Key)" 0][!Update][!Redraw][#s_OnChangeAction]

[ClearFloat$($Options.Index)]
Meter=Image
W=[#s_RightPanelW]
H=([#s_ValueYPadding] + [#s_ToggleSize] + [#s_ValueYPadding])
MeterStyle=$($Options.Container)
Y=([VariableDescription$($Options.Index):Y] + [VariableDescription$($Options.Index):H])
DynamicVariables=1


"@

return $ini