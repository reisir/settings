[ListIcon{Index}]
Meter=String
Text={Icon}
MeterStyle=CategoryListIcon | {Container}
[ListItem{Index}]
Meter=String
Text={Category}
MeterStyle=CategoryListAboutItem | {Container}
FontWeight=([#s_CurrentCategory] = {Index}) ? [#s_SelectedFontWeight] : [#s_TitleFontWeight]
X=([ListIcon{Index}:W] > #s_ListIconLeftPadding# ? ([ListIcon{Index}:W]) : 0)r
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory {Index} "includes\Variables.inc"][!Refresh]

