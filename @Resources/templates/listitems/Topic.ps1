param (
    [Parameter()]
    [System.Collections.Hashtable]
    $Category,
    [Parameter()]
    [String]
    $InternalSettingsFile
)

$ini = @"
[ListItem$($Category.Index)]
Meter=Image
W=[#s_LeftPanelW]
H=([ListIcon$($Category.Index):H] > [ListTitle$($Category.Index):H]) ? [ListIcon$($Category.Index):H] : [ListTitle$($Category.Index):H]
SolidColor=255,255,255
MeterStyle=LeftPanel

[ListIcon$($Category.Index)]
Meter=String
Text=$($Category.Icon)
MeterStyle=ListIcon | ListTopicIcon
Y=([ListItem$($Category.Index):H] / 2 - [#CURRENTSECTION#:H] / 2) 
Container=ListItem$($Category.Index)

[ListTitle$($Category.Index)]
Meter=String
Text=$($Category.Name)
MeterStyle=ListItem | ListTopicItem 
W=([#s_LeftPanelW] - ([ListIcon$($Category.Index):W] + [#s_ListRightPadding]) - [#s_ListTopicGap])
Y=([ListItem$($Category.Index):H] / 2 - [#CURRENTSECTION#:H] / 2) 
FontWeight=([#s_CurrentCategory] = $($Category.Index)) ? [#s_SelectedFontWeight] : [#s_FontWeight]
Container=ListItem$($Category.Index)
ToolTipTitle=$($Category.Name)
ToolTipText=$($Category.Tooltip)
"@

return $ini
