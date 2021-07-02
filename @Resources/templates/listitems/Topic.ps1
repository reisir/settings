param (
    [Parameter()]
    [System.Collections.Hashtable]
    $Category,
    [Parameter()]
    [String]
    $InternalSettingsFile
)

$ini = @"
[ListIcon$($Category.Index)]
Meter=String
Text=$($Category.Icon)
Y=[#s_ListTopicTopPadding]R
MeterStyle=ListIcon | ListTopicIcon | LeftPanel

[ListItem$($Category.Index)]
Meter=String
Text=$($Category.Name)
MeterStyle=ListItem | ListTopicItem 
W=([#s_LeftPanelW] - ([ListIcon$($Category.Index):W] + [#s_ListRightPadding]))
FontWeight=([#s_CurrentCategory] = $($Category.Index)) ? [#s_SelectedFontWeight] : [#s_FontWeight]
ToolTipTitle=$($Category.Name)
ToolTipText=$($Category.Tooltip)
"@




return $ini