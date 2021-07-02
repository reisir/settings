param (
    [Parameter()]
    [System.Collections.Hashtable]
    $Variable
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


"@

return $ini