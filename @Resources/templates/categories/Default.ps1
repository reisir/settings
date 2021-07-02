param (
    [Parameter()]
    [System.Collections.Hashtable]
    $Category
)

$ini = @"
[CategoryIcon$($Category.Index)]
Meter=String
Text=$($Category.Icon)
MeterStyle=CategoryIcon | RightPanel

[Title$($Category.Index)]
Meter=String
Text=$($Category.Name)
MeterStyle=CategoryTitle
W=([#s_RightPanelW] - [CategoryIcon$($Category.Index):W])

[CategoryDescription$($Category.Index)]
Meter=String
Text=$($Category.Description)
MeterStyle=VarDescription | ThickDescription | RightPanel

[CategoryTitleSeparator$($Category.Index)]
Meter=Image
MeterStyle=CategoryTitleSeparator | RightPanel
"@

return $ini