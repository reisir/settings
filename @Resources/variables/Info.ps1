param (
    [Parameter()]
    [System.Collections.Hashtable]
    $Variable,
    [Parameter()]
    [String]
    $SettingsFile
)

$ini = @"
[VariableIcon$($Variable.Index)]
Meter=String
Text=$($Variable.Icon)
MeterStyle=VariableIcon | RightPanel

[VariableTitle$($Variable.Index)]
Meter=String
Text=$($Variable.Name)
MeterStyle=VarTitle

[VariableDescription$($Variable.Index)]
Meter=String
Text=$($Variable.Description)
MeterStyle=VarDescription | RightPanel

[VariableValue$($Variable.Index)]
Meter=String
Text=$($Variable.Key)
MeterStyle=VarStringValue | Link$($Variable.Link)
LeftMouseUpAction=["$($Variable.Value)"]

[MeasureLinkStatus$($Variable.Index)]
Measure=Calc
Formula=$($Variable.Link)
IfCondition=(0 = #CURRENTSECTION#)
IfTrueAction=[!DisableMouseAction VariableValue$($Variable.Index) LeftMouseUpAction]
"@

return $ini