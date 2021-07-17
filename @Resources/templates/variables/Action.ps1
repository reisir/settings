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

[VariableValue$($Variable.Index)]
Meter=String
Text=$($Variable.Key)
MeterStyle=VarString | RightPanel | Link$($Variable.Link)
$(FontFace)

$(if($Variable.Value) {
if( @("[", "!") -contains $Variable.Value.Trim().SubString(0,1)){
"LeftMouseUpAction=$($Variable.Value)"
} else {
"LeftMouseUpAction=[`"$($Variable.Value)`"]"
}
})

[MeasureLinkStatus$($Variable.Index)]
Measure=Calc
Formula=$($Variable.Link)
IfCondition=(0 = #CURRENTSECTION#)
IfTrueAction=[!DisableMouseAction VariableValue$($Variable.Index) LeftMouseUpAction]
"@

