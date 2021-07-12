[Background]
Meter=Shape
Shape=Rectangle 0,0,(#s_RightPanelW# + #s_LeftPanelW#),(#s_PanelH# + #s_TopHeight#),(#s_BackgroundRounding#) | Extend BackgroundModifiers
Shape2=Rectangle (#s_LeftPanelW#),0,(#s_RightPanelW#),(#s_PanelH#),(#s_BackgroundRounding#) | Extend PanelModifiers
Shape3=Rectangle (#s_LeftPanelW#),0,(([#s_HidePanelCorrector] = 0) ? #s_BackgroundRounding# : 0),(#s_PanelH#) | Extend PanelModifiers
PanelModifiers=Fill Color #s_RightPanelBackgroundColor# | StrokeWidth 0
BackgroundModifiers=Fill Color #s_LeftPanelBackgroundColor# | StrokeWidth 0

[LeftScrollArea]
Meter=Shape
Shape=Rectangle 0,#s_TopHeight#,#s_LeftPanelW#,#s_PanelH# | StrokeWidth 0 | Fill Color 0,0,0,0
MouseScrollDownAction=[!EnableMeasure ScrollDownLeft][!UpdateMeasure ScrollDownLeft]
MouseScrollUpAction=[!EnableMeasure ScrollUpLeft][!UpdateMeasure ScrollUpLeft]

[RightScrollArea]
Meter=Shape
Shape=Rectangle #s_LeftPanelW#,#s_TopHeight#,#s_RightPanelW#,#s_PanelH# | StrokeWidth 0 | Fill Color 0,0,0,0
MouseScrollDownAction=[!EnableMeasure ScrollDownRight][!UpdateMeasure ScrollDownRight]
MouseScrollUpAction=[!EnableMeasure ScrollUpRight][!UpdateMeasure ScrollUpRight]

[LeftMaxScrollAmount]
Measure=Calc 
Formula=Abs([FirstLeft:Y] - [LastLeft:Y]) - [#s_PanelH]
DynamicVariables=1

[LeftScrollPercentage]
Measure=Calc
Formula=Clamp(([#s_ScrollLeft] / LeftMaxScrollAmount), -1, 0) * -1
DynamicVariables=1

[LeftScrollIndicatorHeight]
Measure=Calc
Formula=([#s_LeftScrollIndicatorMaxHeight] * ([#s_PanelH] / ([LeftMaxScrollAmount] + [#s_PanelH])))
DynamicVariables=1

[LeftScrollIndicator]
Meter=Shape
Shape=Rectangle 0,0,[#s_LeftScrollIndicatorWidth],[LeftScrollIndicatorHeight],([#s_LeftScrollIndicatorRounding] * [#s_LeftScrollIndicatorWidth] / 2) | StrokeWidth 0 | Extend FillModifiers
FillModifiers=Fill Color [#s_LeftScrollIndicatorColor]
X=([#s_LeftPanelW] - [#s_LeftScrollIndicatorXPadding] - [#s_LeftScrollIndicatorWidth])
Y=([#s_LeftScrollIndicatorYPadding] + ([LeftScrollPercentage] * ([#s_LeftScrollIndicatorMaxHeight] - [#CURRENTSECTION#:H])) + [#s_TopHeight])
DynamicVariables=1
Hidden=([LeftMaxScrollAmount] > 0 ? 0 : 1)

[RightMaxScrollAmount]
Measure=Calc 
Formula=Abs([FirstRight:Y] - [LastRight:Y]) - [#s_PanelH]
DynamicVariables=1

[RightScrollPercentage]
Measure=Calc
Formula=Clamp(([#s_ScrollRight] / RightMaxScrollAmount), -1, 0) * -1
DynamicVariables=1

[RightScrollIndicatorHeight]
Measure=Calc
Formula=([#s_RightScrollIndicatorMaxHeight] * ([#s_PanelH] / ([RightMaxScrollAmount] + [#s_PanelH])))
DynamicVariables=1

[RightScrollIndicator]
Meter=Shape
Shape=Rectangle 0,0,[#s_RightScrollIndicatorWidth],[RightScrollIndicatorHeight],([#s_RightScrollIndicatorRounding] * [#s_RightScrollIndicatorWidth] / 2) | StrokeWidth 0 | Extend FillModifiers
FillModifiers=Fill Color [#s_RightScrollIndicatorColor]
X=([#s_LeftPanelW] + [#s_RightPanelW] - [#s_RightScrollIndicatorXPadding] - [#s_RightScrollIndicatorWidth])
Y=([#s_RightScrollIndicatorYPadding] + ([RightScrollPercentage] * ([#s_RightScrollIndicatorMaxHeight] - [#CURRENTSECTION#:H])) + [#s_TopHeight])
DynamicVariables=1
Hidden=([RightMaxScrollAmount] > 0 ? 0 : 1)
 

