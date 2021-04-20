[ListIcon{Index}]
Meter=String
Text={Icon}
Y=[#s_ListAboutTopPadding]R
MeterStyle=ListIcon | ListAboutIcon | {Container}
[ListItem{Index}]
Meter=String
Text={Name}
MeterStyle=ListItem | ListAboutItem | {Container}
W=([#s_LeftPanelW] - ([ListIcon{Index}:W] + [#s_ListRightPadding]))
FontWeight=([#s_CurrentCategory] = {Index}) ? [#s_SelectedFontWeight] : [#s_VariableTitleFontWeight]
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory {Index} "includes\Variables.inc"][!Refresh]
ToolTipTitle={Name}
ToolTipText={Tooltip}

