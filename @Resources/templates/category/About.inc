[CategoryIcon{Index}]
Meter=String
Text={Icon}
MeterStyle=CategoryIcon | {Container}

[Title{Index}]
Meter=String
Text={Name}
MeterStyle=CategoryTitle | {Container}
X=([CategoryIcon{Index}:W] > #s_ListItemPadding# ? ([CategoryIcon{Index}:W]) : 0)r

[CategoryDescription{Index}]
Meter=String
Text={Description}
MeterStyle=VarDescription | {Container}

