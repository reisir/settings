
function ListContainer {
    return @"
[ListItem$($Category.Index)]
Meter=Image
W=[#s_LeftPanelW]
H=([ListIcon$($Category.Index):H] > [ListTitle$($Category.Index):H]) ? [ListIcon$($Category.Index):H] : [ListTitle$($Category.Index):H]
Padding=0,[#s_List$($Category.Type)TopPadding],0,[#s_List$($Category.Type)BottomPadding]
SolidColor=255,255,255
MeterStyle=LeftPanel


"@
}

function ListX { 
    if ($Category.Icon) {
        return "X=([#s_List$($Category.Type)Gap])R`n"
    }
    else {
        return "X=R`n"
    }
}

function SelectedIndicator {
    return @"
[ListSelectedIndicator$($Category.Index)]
Meter=Shape
Shape=Rectangle 0,[#s_SelectorPadding],([#s_SelectorWidth] * 2),((([ListIcon$($Category.Index):H] > [ListTitle$($Category.Index):H]) ? [ListIcon$($Category.Index):H] : [ListTitle$($Category.Index):H]) - ([#s_SelectorPadding] * 2)),[#s_SelectorRounding] | Extend Line, Square
Line=StrokeWidth 0
Square=Fill Color [#s_SelectedColor]
X=(-[#s_SelectorWidth])
Y=([#s_List$($Category.Type)TopPadding])
DynamicVariables=1
Container=ListItem$($Category.Index)
Hidden=([#s_CurrentCategory] = $($Category.Index)) ? 0 : 1


"@
}