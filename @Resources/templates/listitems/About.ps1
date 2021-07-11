param (
    [Parameter()]
    [System.Collections.Hashtable]
    $Category,
    [Parameter()]
    [String]
    $InternalSettingsFile
)

$ini = @"
$(ListContainer)

[ListIcon$($Category.Index)]
Meter=String
Text=$($Category.Icon)
Container=ListItem$($Category.Index)
MeterStyle=ListIcon | ListAboutIcon
Y=([#s_List$($Category.Type)TopPadding] + (([ListItem$($Category.Index):H] - [#s_List$($Category.Type)TotalPadding]) / 2) - ([#CURRENTSECTION#:H] / 2))
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory $($Category.Index) "$($InternalSettingsFile)"][!Refresh]

[ListTitle$($Category.Index)]
Meter=String
Text=$($Category.Name)
MeterStyle=ListItem | ListAboutItem
ClipStringW=([#s_LeftPanelW] - [ListIcon$($Category.Index):W] - [#s_ListRightPadding] - [#s_ListAboutGap])
Y=([#s_List$($Category.Type)TopPadding] + (([ListItem$($Category.Index):H] - [#s_List$($Category.Type)TotalPadding]) / 2) - ([#CURRENTSECTION#:H] / 2))
$(ListX)
FontWeight=([#s_CurrentCategory] = $($Category.Index)) ? [#s_SelectedFontWeight] : [#s_VariableTitleFontWeight]
Container=ListItem$($Category.Index)
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory $($Category.Index) "$($InternalSettingsFile)"][!Refresh]
"@

return $ini
