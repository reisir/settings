param (
    [Parameter()]
    [System.Collections.Hashtable]
    $Overrides
)

return @"
[TitleBar]
Meter=Shape
Shape=Rectangle 0,0,(#s_RightPanelW# + #s_LeftPanelW#),(#s_TopHeight#),(#s_BackgroundRounding#) | Extend BackgroundModifiers
Shape2=Rectangle 0,(#s_TopHeight# - (#s_BackgroundRounding#)),(#s_RightPanelW# + #s_LeftPanelW#),(([#s_HideTopCorrector] = 0) ? #s_BackgroundRounding# : 0) | Extend BackgroundModifiers
BackgroundModifiers=Fill Color #s_TopBarColor# | StrokeWidth 0

[TitleString]
Meter=String
Text=$($Overrides.Title)
X=[#s_TitlePadding] 
Y=(([#s_TopHeight] / 2) - ([#CURRENTSECTION#:H] / 2))
;X=((([#s_LeftPanelW] + [#s_RightPanelW]) / 2) - ([#s_TitlePadding] / 2))
;W=(([#s_LeftPanelW] + [#s_RightPanelW]) - ([#s_TitlePadding] * 2))
StringAlign=[#s_TitleAlign]
FontFace=[#s_FontFace]
FontSize=[#s_TitleSize]
FontColor=[#s_FontColor]
AntiAlias=1
DynamicVariables=1


"@

