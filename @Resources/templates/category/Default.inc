[CategoryIcon{Index}]
Meter=String
Text={Icon}
MeterStyle=CategoryIcon | {Container}

[Title{Index}]
Meter=String
Text={Name}
MeterStyle=CategoryTitle | {Container}
X=([CategoryIcon{Index}:W] > #s_CategoryTitleLeftPadding# ? ([CategoryIcon{Index}:W]) : [#s_VariableXPadding])r

[CategoryDescription{Index}]
Meter=String
Text={Description}
MeterStyle=VarDescription | {Container}

[CategoryTitleSeparator{Index}]
Meter=Image
MeterStyle=CategoryTitleSeparator | {Container}

