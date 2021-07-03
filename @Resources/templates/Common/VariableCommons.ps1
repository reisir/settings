# Common functions for variable scripts

function FontFace {
    if($Variable.Font) {
        return "FontFace=$($Variable.Font)"
    } else {
        return "FontFace=#s_FontFace#"
    }
}

function Title {
    return @"
[VariableTitle$($Variable.Index)]
Meter=String
MeterStyle=VarTitle | RightPanel
Text=$($Variable.Name)
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

function UsePlugin {
    param (
        [Parameter()]
        [String]
        $Plugin
    )

    $usedPlugins[$Plugin] = $true
    
}