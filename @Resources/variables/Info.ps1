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

[VariableValue$($Options.Index)]
Meter=String
Text=$($Variable.Key)
MeterStyle=VarStringValue | Link$($Variable.Properties.Link) | $($Options.Container)
LeftMouseUpAction=["$($Variable.Value)"]

[MeasureLinkStatus$($Options.Index)]
Measure=Calc
Formula=$($Variable.Properties.Link)
IfCondition=(0 = #CURRENTSECTION#)
IfTrueAction=[!DisableMouseAction VariableValue$($Options.Index) LeftMouseUpAction]


"@

return $ini