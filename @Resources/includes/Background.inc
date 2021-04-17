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

[CategoryListSelectedIndicator]
Meter=Shape
Shape=Rectangle 0,[#s_SelectorPadding],([#s_SelectorWidth] * 2),([ListItem[#s_CurrentCategory]:H] - ([#s_SelectorPadding] * 2)),[#s_SelectorRounding] | Extend Line, Square
Line=StrokeWidth 0
Square=Fill Color [#s_SelectedColor]
X=(-[#s_SelectorWidth])
Y=([ListIcon[#s_CurrentCategory]:Y])
DynamicVariables=1
MeterStyle=GenLeft

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

