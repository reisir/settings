[TitleBar]
Meter=Shape
Shape=Rectangle 0,0,(#s_RightPanelW# + #s_LeftPanelW#),(#s_TopHeight#),(#s_BackgroundRounding#) | Extend BackgroundModifiers
Shape2=Rectangle 0,(#s_TopHeight# - (#s_BackgroundRounding#)),(#s_RightPanelW# + #s_LeftPanelW#),(([#s_HideTopCorrector] = 0) ? #s_BackgroundRounding# : 0) | Extend BackgroundModifiers
BackgroundModifiers=Fill Color #s_TopBarColor# | StrokeWidth 0

