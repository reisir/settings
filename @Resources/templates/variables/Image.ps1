param (
    [Parameter()]
    [System.Collections.Hashtable]
    $Variable,
    [Parameter()]
    [String]
    $SettingsFile
)

if (-not $Variable.Width) {
    $Variable.Width=320
}
if (-not $Variable.Height) {
    $Variable.Height=180
}
if (-not $Variable.Rounding) {
    $Variable.Rounding=5
}
if (-not $Variable.InitialDirectory -or $Variable.InitialDirectory -match '^\s*$') {
    $Variable.InitialDirectory="::{20D04FE0-3AEA-1069-A2D8-08002B30309D}"
}

return @"
$(Title)

[VariableContainer$($Variable.Index)]
Meter=Shape
X=([#s_LeftPanelW]+[#s_VariableXPadding])
W=$($Variable.Width)
H=$($Variable.Height)
Shape=Rectangle 0,0,$($Variable.Width),$($Variable.Height),$($Variable.Rounding)
SolidColor=0,0,0,0
MeterStyle=VariableContainer | RightPanel

[VariablePreview$($Variable.Index)]
Meter=Image
W=$($Variable.Width)
H=$($Variable.Height)
SolidColor=0,0,0,200
PreserveAspectRatio=1
ImageName=#$($Variable.Key)#
Container=VariableContainer$($Variable.Index)
LeftMouseUpAction=[!CommandMeasure FileChoose$($Variable.Index) "ChooseImage 1"]

[FileChoose$($Variable.Index)]
Measure=Plugin
Plugin=FileChoose
UseNewStyle=1
ImageInitialDirectory=$($Variable.InitialDirectory)
ReturnValue=Path
Command1=[!WriteKeyValue Variables $($Variable.Key) "`$Path`$" "$SettingsFile"][#s_SaveScroll][#s_OnChangeAction][!Refresh]
"@