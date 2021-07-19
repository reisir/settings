param (
    [Parameter()]
    [System.Collections.Hashtable]
    $Category
)

$ini = @"
$(ListContainer)

[ListIcon$($Category.Index)]
Meter=String
Text=$($Category.Icon)
Container=ListItem$($Category.Index)
MeterStyle=ListIcon | ListDefaultIcon
Y=([#s_List$($Category.Type)TopPadding] + (([ListItem$($Category.Index):H] - [#s_List$($Category.Type)TotalPadding]) / 2) - ([#CURRENTSECTION#:H] / 2))
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory $($Category.Index) "[#s_CurrentFile]"][#s_SaveLeftScroll][!Refresh]

[ListTitle$($Category.Index)]
Meter=String
Text=$($Category.Name)
MeterStyle=ListItem | ListDefaultItem 
ClipStringW=([#s_LeftPanelW] - [ListIcon$($Category.Index):W] - [#s_ListRightPadding] - [#s_ListDefaultGap])
Y=([#s_List$($Category.Type)TopPadding] + (([ListItem$($Category.Index):H] - [#s_List$($Category.Type)TotalPadding]) / 2) - ([#CURRENTSECTION#:H] / 2))
$(ListX)
FontWeight=([#s_CurrentCategory] = $($Category.Index)) ? [#s_SelectedFontWeight] : [#s_FontWeight]
Container=ListItem$($Category.Index)
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory $($Category.Index) "[#s_CurrentFile]"][#s_SaveLeftScroll][!Refresh]

$(SelectedIndicator)

"@

return $ini
