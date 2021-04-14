[Background]
Meter=Shape
Shape=Rectangle 0,0,(#s_RightPanelW# + #s_LeftPanelW#),(#s_PanelH#),(#s_BackgroundRounding#) | Extend BackgroundModifiers
BackgroundModifiers=Fill Color #s_RightPanelBackgroundColor# | StrokeWidth 0

[BGLeftPanel]
Meter=Shape
Shape=Rectangle 0,0,(#s_LeftPanelW#),(#s_PanelH#) | Extend PanelModifiers
PanelModifiers=Fill Color #s_LeftPanelBackgroundColor# | StrokeWidth 0
Container=Background

[BGRightPanel]
Meter=Shape
Shape=Rectangle 0,0,(#s_RightPanelW#),(#s_PanelH#) | Extend PanelModifiers
PanelModifiers=Fill Color #s_RightPanelBackgroundColor# | StrokeWidth 0
Container=Background
X=0R

[LeftPanel]
Meter=Shape
Shape=Rectangle 0,0,(#s_LeftPanelW#),(#s_PanelH#) | Extend PanelModifiers
PanelModifiers=Fill Color 255,255,255 | StrokeWidth 0

[RightPanel]
Meter=Shape
Shape=Rectangle 0,0,(#s_RightPanelW#),(#s_PanelH#) | Extend PanelModifiers
PanelModifiers=Fill Color 255,255,255 | StrokeWidth 0
X=(#s_LeftPanelW#)
