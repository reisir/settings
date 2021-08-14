param(
    [Parameter(Mandatory)]
    [System.Collections.Hashtable]
    $Variable,
    [Parameter(Mandatory)]
    [String]
    $SettingsFile
)

$Variable.Width = if ($Variable.Width -match '^\s*(\d+\.?\d*?)\s*$') { $matches[1] } else { $RmApi.VariableStr("s_SliderDefaultWidth") }
$Variable.MinValue = if ($Variable.MinValue -match '^\s*(\d+\.?\d*?)\s*$') { $matches[1] } else { $RmApi.VariableStr("s_SliderDefaultMinValue") }
$Variable.MaxValue = if ($Variable.MaxValue -match '^\s*(\d+\.?\d*?)\s*$') { $matches[1] } else { $RmApi.VariableStr("s_SliderDefaultMaxValue") }

$scroll = $Variable.Scroll -split '\s*,\s*'
$scrollHash = @{
    'Increment'  = if (($scroll[0] -match '^\d+$') -or ($scroll[0] -is [Double])) { $scroll[0] }else { 1 };
    'Decrement'  = if (($scroll[1] -match '^\d+$') -or ($scroll[1] -is [Double])) { $scroll[1] }else { $(if (($scroll[0] -match '^\d+$') -or ($scroll[0] -is [Double])) { $scroll[0] } else { 1 }) };
    'isInverted' = if ($scroll[2] -in @(0, 1)) { $scroll[2] }else { 0 }
}

Remove-Variable scroll

$doubler = {
    param(
        $ini,
        $precision
    )
    return "(Round(($ini),$precision))"
}

$scroll = if ($scrollHash.isInverted -eq 0) {
    @"
MouseScrollUpAction=[!SetVariable $($Variable.Key) "$(&($doubler) -string "(Clamp([#$($Variable.Key)]+$($scrollHash.Increment), $($Variable.MinValue), $($Variable.MaxValue)))"-precision $Variable.Precision)"][!WriteKeyValue Variables $($Variable.Key) "[#$($Variable.Key)]" "$SettingsFile"][!SetOption SliderBlob$($Variable.Index) X "([#s_LeftPanelW]+[#s_VariableXPadding]+$($Variable.Width)*([#$($Variable.Key)]-($($Variable.MinValue)))/($($Variable.MaxValue - $Variable.MinValue)))"][!UpdateMeterGroup Sliders$($Variable.Index)][#s_SaveScroll][!Update][!Redraw][#s_OnChangeAction]
MouseScrollDownAction=[!SetVariable $($Variable.Key) "$(&($doubler) -string "(Clamp([#$($Variable.Key)]-$($scrollHash.Increment), $($Variable.MinValue), $($Variable.MaxValue)))"-precision $Variable.Precision)"][!WriteKeyValue Variables $($Variable.Key) "[#$($Variable.Key)]" "$SettingsFile"][!SetOption SliderBlob$($Variable.Index) X "([#s_LeftPanelW]+[#s_VariableXPadding]+$($Variable.Width)*([#$($Variable.Key)]-($($Variable.MinValue)))/($($Variable.MaxValue - $Variable.MinValue)))"][!UpdateMeterGroup Sliders$($Variable.Index)][#s_SaveScroll][!Update][!Redraw][#s_OnChangeAction]
"@
}
else {
    @"
MouseScrollDownAction=[!SetVariable $($Variable.Key) "$(&($doubler) -string "(Clamp([#$($Variable.Key)]+$($scrollHash.Increment), $($Variable.MinValue), $($Variable.MaxValue)))"-precision $Variable.Precision)"][!WriteKeyValue Variables $($Variable.Key) "[#$($Variable.Key)]" "$SettingsFile"][!SetOption SliderBlob$($Variable.Index) X "([#s_LeftPanelW]+[#s_VariableXPadding]+$($Variable.Width)*([#$($Variable.Key)]-($($Variable.MinValue)))/($($Variable.MaxValue - $Variable.MinValue)))"][!UpdateMeterGroup Sliders$($Variable.Index)][#s_SaveScroll][!Update][!Redraw][#s_OnChangeAction]
MouseScrollUpAction=[!SetVariable $($Variable.Key) "$(&($doubler) -string "(Clamp([#$($Variable.Key)]-$($scrollHash.Increment), $($Variable.MinValue), $($Variable.MaxValue)))"-precision $Variable.Precision)"][!WriteKeyValue Variables $($Variable.Key) "[#$($Variable.Key)]" "$SettingsFile"][!SetOption SliderBlob$($Variable.Index) X "([#s_LeftPanelW]+[#s_VariableXPadding]+$($Variable.Width)*([#$($Variable.Key)]-($($Variable.MinValue)))/($($Variable.MaxValue - $Variable.MinValue)))"][!UpdateMeterGroup Sliders$($Variable.Index)][#s_SaveScroll][!Update][!Redraw][#s_OnChangeAction]
"@
}

$ini = @"
$(Title)

[Slider$($Variable.Index)]
Measure=Plugin
Plugin=Mouse
LeftMouseDragAction=[!SetOption SliderBlob$($Variable.Index) X "(Clamp(`$MouseX$,[#s_LeftPanelW]+[#s_VariableXPadding],([#s_LeftPanelW]+[#s_VariableXPadding]+$($Variable.Width))))"][!UpdateMeter SliderBlob$($Variable.Index)][!UpdateMeasure SliderCalc$($Variable.Index)]
LeftMouseUpAction=[!CommandMeasure Slider$($Variable.Index) "Stop"][#s_OnChangeAction][!Delay 150][!EnableMouseAction SliderBar$($Variable.Index) "LeftMouseUpAction"]
RelativeToSkin=1
RequireDragging=1
DynamicVariables=1

[SliderCalc$($Variable.Index)]
Measure=Calc
Formula=[SliderBlob$($Variable.Index):X]
MinValue=([#s_LeftPanelW]+[#s_VariableXPadding])
MaxValue=([#s_LeftPanelW]+[#s_VariableXPadding]+$($Variable.Width))
OnChangeAction=[!SetVariable $($Variable.Key) "$(&($doubler) -string "($($Variable.MinValue)+(([SliderCalc$($Variable.Index):%]/100)*($($Variable.MaxValue)-($($Variable.MinValue)))))"-precision $Variable.Precision)"][!WriteKeyValue Variables $($Variable.Key) "[#$($Variable.Key)]" "$SettingsFile"][!UpdateMeterGroup Sliders$($Variable.Index)][!Redraw]
DynamicVariables=1

[SliderBar$($Variable.Index)]
Meter=Shape
X=([#s_LeftPanelW]+[#s_VariableXPadding])
Y=[#s_VariableYPadding]R
Shape=Rectangle 0,0,$($Variable.Width),6,3 | Fill Color FFFFFF | StrokeWidth 0
Shape2=Rectangle 0,0,($($Variable.Width)*([#$($Variable.Key)]-($($Variable.MinValue)))/($($Variable.MaxValue)-($($Variable.MinValue)))),6,3 | Fill Color [#s_SelectedColor] | StrokeWidth 0
DynamicVariables=1
$scroll
LeftMouseUpAction=[!SetVariable $($Variable.Key) "$(&($doubler) -string "(($($Variable.MinValue))+($($Variable.MaxValue)-($($Variable.MinValue)))*(`$MouseX`$/$($Variable.Width)))"-precision $Variable.Precision)"][!WriteKeyValue Variables $($Variable.Key) "[#$($Variable.Key)]" "$SettingsFile"][!SetOption SliderBlob$($Variable.Index) X "([#s_LeftPanelW]+[#s_VariableXPadding]+$($Variable.Width)*([#$($Variable.Key)]-($($Variable.MinValue)))/($($Variable.MaxValue)-($($Variable.MinValue))))"][!UpdateMeterGroup Sliders$($Variable.Index)][#s_SaveScroll][!Update][!Redraw][#s_OnChangeAction]
Group=Sliders$($Variable.Index)

[SliderBlob$($Variable.Index)]
Meter=Shape
X=([#s_LeftPanelW]+[#s_VariableXPadding]+$($Variable.Width)*([#$($Variable.Key)]-($($Variable.MinValue)))/($($Variable.MaxValue)-($($Variable.MinValue))))
Y=3r
Shape=Ellipse 0,0,6,6 | Fill Color [#s_SelectedColor] | StrokeWidth 0
Shape2=Ellipse 0,0,3,3 | Fill Color FFFFFF | StrokeWidth 0
LeftMouseDownAction=[!DisableMouseAction SliderBar$($Variable.Index) "LeftMouseUpAction"][!CommandMeasure Slider$($Variable.Index) "Start"]
Group=Sliders$($Variable.Index)

[SliderValue$($Variable.Index)]
Meter=String
X=([#s_LeftPanelW] + [#s_VariableXPadding] + $($Variable.Width) + [#s_SliderValuePadding])
Y=(-([#CURRENTSECTION#:H] / 2) + ([SliderBlob$($Variable.Index):H] / 2))R
Text=[#$($Variable.Key)]
FontSize=12
Text=[#$($Variable.Key)]
StringAlign=LeftCenter
Padding=0,0,0,0
MeterStyle=VarString | VarColorString
DynamicVariables=1
Group=Sliders$($Variable.Index)
"@

return $ini