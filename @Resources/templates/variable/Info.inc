[Var{Index}]
Meter=String
Text={Name}
MeterStyle=VarTitle | {Container}
[Var{Index}Description]
Meter=String
Text={Description}
MeterStyle=VarDescription | {Container}
[Value{Index}]
Meter=String
Text={Key}
MeterStyle=VarStringValue | Link{Link} | {Container}
Hidden={Hidden}
LeftMouseUpAction=["{Value}"]
[MeasureLinkStatus{0}]
Measure=Calc
IfCondition={Link} = 1
IfFalseAction=[!DisableMouseAction Value{Index} LeftMouseUpAction]

