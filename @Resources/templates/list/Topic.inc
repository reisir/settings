[ListIcon{Index}]
Meter=String
Text={Icon}
MeterStyle=ListIcon | ListTopicIcon | {Container}
[ListItem{Index}]
Meter=String
Text={Name}
MeterStyle=ListItem | ListTopicItem | {Container}
W=([#s_LeftPanelW] - ([ListIcon{Index}:W] + [#s_ListRightPadding]))
FontWeight=([#s_CurrentCategory] = {Index}) ? [#s_SelectedFontWeight] : [#s_FontWeight]
ToolTipTitle={Name}
ToolTipText={Tooltip}

