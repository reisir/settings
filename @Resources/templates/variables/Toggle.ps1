param (
    [Parameter()]
    [System.Collections.Hashtable]
    $Variable,
    [Parameter()]
    [String]
    $SettingsFile
)

return @"
$(Title)

[VariableContainer$($Variable.Index)]
MeterStyle=VariableContainer | RightPanel
Meter=Image
H=([#s_ToggleSize] + [#s_VariableYPadding])

[ToggleOff$($Variable.Index)]
Meter=Shape
Shape=Line 0,0,([#s_ToggleLength]),0 | Extend Line
Shape2=Ellipse ([#s_TogglePadding]/2),0,(([#s_ToggleSize] - ([#s_TogglePadding] * 2))/2),(([#s_ToggleSize] - ([#s_TogglePadding] * 2))/2) | Extend Circle
Circle=StrokeWidth 0 | Fill Color [#s_RightPanelBackgroundColor]
Line=StrokeWidth [#s_ToggleSize] | Stroke Color [#s_FontColor] | StrokeStartCap Round | StrokeEndCap Round
$(if($Variable.Invert){
@"
Hidden=([#$($Variable.Key)] - 1)
LeftMouseUpAction=[!WriteKeyValue Variables "$($Variable.Key)" 0 "$($SettingsFile)"][!SetVariable "$($Variable.Key)" 0][#s_SaveScroll][!Update][!Redraw][&MainLua:OnChangeAction()]

"@
}else {
@"
Hidden=([#$($Variable.Key)])
LeftMouseUpAction=[!WriteKeyValue Variables "$($Variable.Key)" 1 "$($SettingsFile)"][!SetVariable "$($Variable.Key)" 1][#s_SaveScroll][!Update][!Redraw][&MainLua:OnChangeAction()]

"@
})
MeterStyle=VarToggle
Container=VariableContainer$($Variable.Index)

[ToggleOn$($Variable.Index)]
Meter=Shape
Shape=Line 0,0,([#s_ToggleLength]),0 | Extend Line
Shape2=Ellipse (([#s_ToggleLength]) - ([#s_TogglePadding]/2)),0,(([#s_ToggleSize] - ([#s_TogglePadding] * 2))/2),(([#s_ToggleSize] - ([#s_TogglePadding] * 2))/2) | Extend Circle
Circle=StrokeWidth 0 | Fill Color [#s_RightPanelBackgroundColor]
Line=StrokeWidth [#s_ToggleSize] | Stroke Color [#s_ToggleActiveColor] | StrokeStartCap Round | StrokeEndCap Round
$(if($Variable.Invert){
@"
Hidden=([#$($Variable.Key)])
LeftMouseUpAction=[!WriteKeyValue Variables "$($Variable.Key)" 1 "$($SettingsFile)"][!SetVariable "$($Variable.Key)" 1][#s_SaveScroll][!Update][!Redraw][&MainLua:OnChangeAction()]

"@
}else {
@"
Hidden=([#$($Variable.Key)] - 1)
LeftMouseUpAction=[!WriteKeyValue Variables "$($Variable.Key)" 0 "$($SettingsFile)"][!SetVariable "$($Variable.Key)" 0][#s_SaveScroll][!Update][!Redraw][&MainLua:OnChangeAction()]

"@
})
MeterStyle=VarToggle
Container=VariableContainer$($Variable.Index)
"@