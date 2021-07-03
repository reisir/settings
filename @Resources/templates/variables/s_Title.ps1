param (
    [Parameter()]
    [System.Collections.Hashtable]
    $Variable
)

$ini = @"
[VariableTitle$($Variable.Index)]
Meter=String
Text=$($Variable.Name)
MeterStyle=VarTitle | RightPanel

[VariableDescription$($Variable.Index)]
Meter=String
Text=$($Variable.Description)
MeterStyle=VarDescription | RightPanel
$(if($Variable.Description) { 
"Y=(-[#s_VariableYPadding])R`n"
})

"@

return $ini