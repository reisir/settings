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

[VariableValue$($Variable.Index)]
Meter=String
Text=$($Variable.Key)
MeterStyle=VarStringValue | Link$($Variable.Link) | $($Options.Container)
LeftMouseUpAction=["$($Variable.Value)"]

[MeasureLinkStatus$($Variable.Index)]
Measure=Calc
Formula=$($Variable.Link)
IfCondition=(0 = #CURRENTSECTION#)
IfTrueAction=[!DisableMouseAction VariableValue$($Variable.Index) LeftMouseUpAction]


"@

return $ini