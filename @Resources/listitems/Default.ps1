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
MeterStyle=ListIcon | ListDefaultIcon | LeftPanel
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory $($Category.Index) "$($InternalSettingsFile)"][!Refresh]

[ListItem$($Category.Index)]
Meter=String
Text=$($Category.Name)
MeterStyle=ListItem | ListDefaultItem 
W=([#s_LeftPanelW] - ([ListIcon$($Category.Index):W] + [#s_ListRightPadding]))
FontWeight=([#s_CurrentCategory] = $($Category.Index)) ? [#s_SelectedFontWeight] : [#s_FontWeight]
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory $($Category.Index) "$($InternalSettingsFile)"][!Refresh]
ToolTipTitle=$($Category.Name)
ToolTipText=$($Category.Tooltip)
"@


return $ini