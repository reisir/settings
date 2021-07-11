
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
    if($Category.Icon) {
        return "X=([#s_List$($Category.Type)Gap])R`n"
    } else {
        return "X=R`n"
    }
}
