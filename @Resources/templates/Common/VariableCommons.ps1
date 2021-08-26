# Common functions for variable scripts

function FontFace {
    if ($Variable.Font) {
        return "FontFace=$($Variable.Font)"
    }
    else {
        return "FontFace=#s_FontFace#"
    }
}

function IconText {
    if ($Variable.Icon) {
        $icon = "Text=$($Variable.Icon)`n"
        if ($Variable.IconFont) {
            $icon += "FontFace=$($Variable.IconFont)`n"
        }
        else {
            $icon += "FontFace=#s_IconFontFace#`n"
        }
        return $icon
    }
    else {
        return "Hidden=1"
    }
}

function Title {
    return @"

[VarIcon$($Variable.Index)]
Meter=String
MeterStyle=VarIcon | RightPanel
Padding=[#s_VariableXPadding],[#s_VariableIconTopPadding],[#s_VariableIconGap],0
$(IconText)

[VariableTitle$($Variable.Index)]
Meter=String
MeterStyle=VarTitle
Text=$($Variable.Name)
ClipStringW=([#s_RightPanelW] - ([#s_VariableXPadding] * 2) - [VarIcon$($Variable.Index):W])
$(if($Variable.Icon) {
"Padding=0,[#s_VariableYPadding],[#s_VariableXPadding],[#s_VariableYPadding]`n"
}else {
"Padding=[#s_VariableXPadding],[#s_VariableYPadding],[#s_VariableXPadding],[#s_VariableYPadding]`n"
})
$(FontFace)

[VariableDescription$($Variable.Index)]
Meter=String
MeterStyle=VarDescription | RightPanel
Text=$($Variable.Description)
$(FontFace)
$(if($Variable.Description) { 
"Y=(-[#s_VariableYPadding])R`n"
})

"@
}
