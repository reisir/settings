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
MeterStyle=ListIcon | ListAboutIcon
Y=([ListItem$($Category.Index):H] / 2 - [#CURRENTSECTION#:H] / 2) 
Container=ListItem$($Category.Index)
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory $($Category.Index) "$($InternalSettingsFile)"][!Refresh]

[ListTitle$($Category.Index)]
Meter=String
Text=$($Category.Name)
MeterStyle=ListItem | ListAboutItem
W=([#s_LeftPanelW] - ([ListIcon$($Category.Index):W] + [#s_ListRightPadding]))
Y=([ListItem$($Category.Index):H] / 2 - [#CURRENTSECTION#:H] / 2)
FontWeight=([#s_CurrentCategory] = $($Category.Index)) ? [#s_SelectedFontWeight] : [#s_VariableTitleFontWeight]
ToolTipTitle=$($Category.Name)
ToolTipText=$($Category.Tooltip)
Container=ListItem$($Category.Index)
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory $($Category.Index) "$($InternalSettingsFile)"][!Refresh]
"@

return $ini
