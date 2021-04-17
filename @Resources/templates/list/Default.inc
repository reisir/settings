[ListIcon{Index}]
Meter=String
Text={Icon}
MeterStyle=CategoryListIcon | {Container}
[ListItem{Index}]
Meter=String
Text={Category}
MeterStyle=CategoryListItem | {Container}
X=([ListIcon{Index}:W] > #s_ListIconLeftPadding# ? ([ListIcon{Index}:W]) : ([#s_ListIconLeftPadding] - [#s_ListItemLeftPadding]))r
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory {Index} "includes\Variables.inc"][!Refresh]


