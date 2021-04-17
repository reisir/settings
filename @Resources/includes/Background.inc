[Background]
Meter=Shape
Shape=Rectangle 0,0,(#s_RightPanelW# + #s_LeftPanelW#),(#s_PanelH#),(#s_BackgroundRounding#) | Extend BackgroundModifiers
Shape2=Rectangle (#s_LeftPanelW#),0,(#s_RightPanelW#),(#s_PanelH#),(#s_BackgroundRounding#) | Extend PanelModifiers
Shape3=Rectangle (#s_LeftPanelW#),0,(#s_BackgroundRounding#),(#s_PanelH#) | Extend PanelModifiers
PanelModifiers=Fill Color #s_RightPanelBackgroundColor# | StrokeWidth 0
BackgroundModifiers=Fill Color #s_LeftPanelBackgroundColor# | StrokeWidth 0

[LeftPanelContainer]
Meter=Shape
Shape=Rectangle 0,0,(#s_LeftPanelW#),(#s_PanelH#) | Extend PanelModifiers
PanelModifiers=Fill Color 255,255,255 | StrokeWidth 0
MouseScrollDownAction=[!EnableMeasure "ScrollDownLeftPanel"][!UpdateMeasure "ScrollDownLeftPanel"]
MouseScrollUpAction=[!EnableMeasure "ScrollUpLeftPanel"][!UpdateMeasure "ScrollUpLeftPanel"]
MouseActionCursor=0

[RightPanelContainer]
Meter=Shape
Shape=Rectangle 0,0,(#s_RightPanelW#),(#s_PanelH#) | Extend PanelModifiers
PanelModifiers=Fill Color 255,255,255 | StrokeWidth 0
X=(#s_LeftPanelW#)
MouseScrollDownAction=[!EnableMeasure "ScrollDownRightPanel"][!UpdateMeasure "ScrollDownRightPanel"]
MouseScrollUpAction=[!EnableMeasure "ScrollUpRightPanel"][!UpdateMeasure "ScrollUpRightPanel"]
MouseActionCursor=0

[LeftPanel]
Container=LeftPanelContainer

[RightPanel]
Container=RightPanelContainer

[FirstItem]
H=0
W=0
X=0
SolidColor=0,0,0,0
DynamicVariables=1
[LastITem]
H=0
W=0
Y=0R
X=0
SolidColor=0,0,0,0

