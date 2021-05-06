[VariableIcon{Index}]
Meter=String
Text={Icon}
MeterStyle=VariableIcon | {Container}
Hidden={Hidden}
[VariableTitle{Index}]
Meter=String
Text={Name}
MeterStyle=VarTitle | {Container}
Hidden={Hidden}
[VariableDescription{Index}]
Meter=String
Text={Description}
MeterStyle=VarDescription | {Container}
Hidden={Hidden}
[VariableValue{Index}]
Meter=String
Text={Key}
MeterStyle=VarStringValue | Link{Link} | {Container}
Hidden={Hidden}
LeftMouseUpAction=["{Value}"]
[MeasureLinkStatus{Index}]
Measure=Calc
Formula={Link}
IfCondition=(0 = #CURRENTSECTION#)
IfTrueAction=[!DisableMouseAction VariableValue{Index} LeftMouseUpAction]
Disabled={Hidden}

