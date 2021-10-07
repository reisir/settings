param (
    [Parameter()]
    [System.Collections.Hashtable]
    $Variable,
    [Parameter()]
    [String]
    $SettingsFile
)

$chooseAction='ChooseFile'
if ($Variable.ChooseFolder -match '1') {
    $chooseAction='ChooseFolder'
}
if (-not $Variable.InitialDirectory -or $Variable.InitialDirectory -match '^\s*$') {
    $Variable.InitialDirectory="::{20D04FE0-3AEA-1069-A2D8-08002B30309D}"
}

return @"
$(Title)

[VariableValue$($Variable.Index)]
Meter=String
Text=[#$($Variable.Key)]
MeterStyle=VarString | RightPanel
$(FontFace)
LeftMouseUpAction=[!CommandMeasure "FileChoose$($Variable.Index)" "$chooseAction 1"]

[FileChoose$($Variable.Index)]
Measure=Plugin
Plugin=FileChoose
UseNewStyle=1
FileInitialDirectory=$($Variable.InitialDirectory)
ReturnValue=Path
Command1=[!WriteKeyValue Variables $($Variable.Key) "`$Path`$" "$SettingsFile"][#s_SaveScroll][#s_OnChangeAction][!Refresh]
"@
