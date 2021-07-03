param (
    [Parameter()]
    [System.Collections.Hashtable]
    $Variable,
    [Parameter()]
    [String]
    $SettingsFile
)

$ini = &"$variableTitleScript" -Variable $Variable

$ini += @"
[VariableValue$($Variable.Index)]
Meter=String
Text=$($Variable.Key)
MeterStyle=VarString | Link$($Variable.Link)
LeftMouseUpAction=["$($Variable.Value)"]

[MeasureLinkStatus$($Variable.Index)]
Measure=Calc
Formula=$($Variable.Link)
IfCondition=(0 = #CURRENTSECTION#)
IfTrueAction=[!DisableMouseAction VariableValue$($Variable.Index) LeftMouseUpAction]
"@

return $ini

