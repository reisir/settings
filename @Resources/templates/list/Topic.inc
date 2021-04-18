[ListIcon{Index}]
Meter=String
Text={Icon}
MeterStyle=CategoryListIcon | {Container}
[ListItem{Index}]
Meter=String
Text={Category}
MeterStyle=CategoryListTopicItem | {Container}
FontWeight=([#s_CurrentCategory] = {Index}) ? [#s_SelectedFontWeight] : [#s_FontWeight]
X=([ListIcon{Index}:W] > #s_ListIconLeftPadding# ? ([ListIcon{Index}:W]) : 0)r

