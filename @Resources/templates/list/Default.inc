[ListIcon{Index}]
Meter=String
Text={Icon}
MeterStyle=ListIcon | ListDefaultIcon | {Container}
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory {Index} "{InternalVariables}"][!Refresh]
[ListItem{Index}]
Meter=String
Text={Name}
MeterStyle=ListItem | ListDefaultItem | {Container}
W=([#s_LeftPanelW] - ([ListIcon{Index}:W] + [#s_ListRightPadding]))
FontWeight=([#s_CurrentCategory] = {Index}) ? [#s_SelectedFontWeight] : [#s_FontWeight]
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory {Index} "{InternalVariables}"][!Refresh]
ToolTipTitle={Name}
ToolTipText={Tooltip}


