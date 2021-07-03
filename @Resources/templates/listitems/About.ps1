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
Y=([#s_ListAboutTopPadding] + (([ListItem$($Category.Index):H] / 2 - [#CURRENTSECTION#:H] / 2)))R
MeterStyle=ListIcon | ListAboutIcon | LeftPanel
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory $($Category.Index) "$($InternalSettingsFile)"][!Refresh]

[ListItem$($Category.Index)]
Meter=String
Text=$($Category.Name)
MeterStyle=ListItem | ListAboutItem
W=([#s_LeftPanelW] - ([ListIcon$($Category.Index):W] + [#s_ListRightPadding]))
Y=(([#CURRENTSECTION#:H] /2 - [ListIcon$($Category.Index):H] / 2) * -1)r
FontWeight=([#s_CurrentCategory] = $($Category.Index)) ? [#s_SelectedFontWeight] : [#s_VariableTitleFontWeight]
ToolTipTitle=$($Category.Name)
ToolTipText=$($Category.Tooltip)
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory $($Category.Index) "$($InternalSettingsFile)"][!Refresh]
"@

return $ini
