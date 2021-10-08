[Background]
Meter=Shape
Shape=Rectangle 0,0,(#s_LeftPanelW#),(#s_PanelH#),(#s_BackgroundRounding#) | Extend BackgroundModifiers
Shape2=Rectangle (#s_LeftPanelW#),0, (-#s_BackgroundRounding#) ,(#s_PanelH#) | Extend BackgroundModifiers
Shape3=Rectangle 0,0,(#s_LeftPanelW#),(#s_PanelH#),(#s_BackgroundRounding#+1)
Shape4=Combine Shape2 | Exclude Shape3
Shape5=Rectangle (#s_LeftPanelW#),0,(#s_RightPanelW#),(#s_PanelH#),(#s_BackgroundRounding#) | Extend PanelModifiers
Shape6=Rectangle (#s_LeftPanelW#),0,#s_BackgroundRounding#,(#s_PanelH#) | Extend PanelModifiers
Shape7=Rectangle (#s_LeftPanelW#),0,(#s_RightPanelW#),(#s_PanelH#),(#s_BackgroundRounding#+1)
Shape8=Combine Shape6 | Exclude Shape7
PanelModifiers=Fill Color #s_RightPanelBackgroundColor# | StrokeWidth 0
BackgroundModifiers=Fill Color #s_LeftPanelBackgroundColor# | StrokeWidth 0

[LeftScrollArea]
Meter=Shape
Shape=Rectangle 0,#s_TopHeight#,#s_LeftPanelW#,#s_PanelH# | StrokeWidth 0 | Fill Color 0,0,0,0
MouseScrollDownAction=[!EnableMeasure ScrollDownLeft][!UpdateMeasure ScrollDownLeft]
MouseScrollUpAction=[!EnableMeasure ScrollUpLeft][!UpdateMeasure ScrollUpLeft]
MouseActionCursor=0

[RightScrollArea]
Meter=Shape
Shape=Rectangle #s_LeftPanelW#,#s_TopHeight#,#s_RightPanelW#,#s_PanelH# | StrokeWidth 0 | Fill Color 0,0,0,0
MouseScrollDownAction=[!EnableMeasure ScrollDownRight][!UpdateMeasure ScrollDownRight]
MouseScrollUpAction=[!EnableMeasure ScrollUpRight][!UpdateMeasure ScrollUpRight]
MouseActionCursor=0

[LeftMaxScrollAmount]
Measure=Calc 
Formula=Abs([FirstLeft:Y] - [LastLeft:Y]) - [#s_PanelH] + [#s_LeftScrollIndicatorYPadding]
DynamicVariables=1

[LeftScrollPercentage]
Measure=Calc
Formula=Clamp(([#s_ScrollLeft] / LeftMaxScrollAmount), -1, 0) * -1
DynamicVariables=1

[LeftScrollIndicatorHeight]
Measure=Calc
Formula=([#s_LeftScrollIndicatorMaxHeight] * ([#s_PanelH] / ([LeftMaxScrollAmount] + [#s_PanelH])))
DynamicVariables=1
IfCondition=LeftScrollIndicatorHeight < [#s_LeftScrollIndicatorMaxHeight]
IfTrueAction=[!UpdateMeter LeftScrollIndicator][!ShowMeter LeftScrollIndicator][!Delay 0][!Redraw]
IfConditionMode=2

[LeftScrollIndicatorPosition]
Measure=Calc
Formula=([#s_LeftScrollIndicatorYPadding] + ([LeftScrollPercentage] * ([#s_LeftScrollIndicatorMaxHeight] - [LeftScrollIndicator:H])) + [#s_TopHeight])
DynamicVariables=1

[LeftScrollIndicator]
Meter=Shape
Shape=Rectangle 0,0,[#s_LeftScrollIndicatorWidth],[LeftScrollIndicatorHeight],([#s_LeftScrollIndicatorRounding] * [#s_LeftScrollIndicatorWidth] / 2) | StrokeWidth 0 | Extend FillModifiers
FillModifiers=Fill Color [#s_LeftScrollIndicatorColor]
X=([#s_LeftPanelW] - [#s_LeftScrollIndicatorXPadding] - [#s_LeftScrollIndicatorWidth])
Y=([#s_LeftScrollIndicatorYPadding] + ([LeftScrollPercentage] * ([#s_LeftScrollIndicatorMaxHeight] - [#CURRENTSECTION#:H])) + [#s_TopHeight])
DynamicVariables=1
Hidden=1

[RightMaxScrollAmount]
Measure=Calc 
Formula=Abs([FirstRight:Y] - [LastRight:Y]) - [#s_PanelH] + [#s_RightScrollIndicatorYPadding]
DynamicVariables=1

[RightScrollPercentage]
Measure=Calc
Formula=Clamp(([#s_ScrollRight] / RightMaxScrollAmount), -1, 0) * -1
DynamicVariables=1

[RightScrollIndicatorHeight]
Measure=Calc
Formula=([#s_RightScrollIndicatorMaxHeight] * ([#s_PanelH] / ([RightMaxScrollAmount] + [#s_PanelH])))
DynamicVariables=1
IfCondition=RightScrollIndicatorHeight < [#s_RightScrollIndicatorMaxHeight]
IfTrueAction=[!UpdateMeter RightScrollIndicator][!ShowMeter RightScrollIndicator][!Delay 0][!Redraw]
IfConditionMode=2

[RightScrollIndicator]
Meter=Shape
Shape=Rectangle 0,0,[#s_RightScrollIndicatorWidth],[RightScrollIndicatorHeight],([#s_RightScrollIndicatorRounding] * [#s_RightScrollIndicatorWidth] / 2) | StrokeWidth 0 | Extend FillModifiers
FillModifiers=Fill Color [#s_RightScrollIndicatorColor]
X=([#s_LeftPanelW] + [#s_RightPanelW] - [#s_RightScrollIndicatorXPadding] - [#s_RightScrollIndicatorWidth])
Y=([#s_RightScrollIndicatorYPadding] + ([RightScrollPercentage] * ([#s_RightScrollIndicatorMaxHeight] - [#CURRENTSECTION#:H])) + [#s_TopHeight])
DynamicVariables=1
Hidden=([RightMaxScrollAmount] > 0 ? 0 : 1) 

