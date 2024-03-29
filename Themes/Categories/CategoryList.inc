[FirstLeft]
Meter=Image
MeterStyle=FirstItem | FirstLeftPanel
Y=([#s_ScrollLeft] + [#s_TopHeight])
SolidColor=0,0,0,0
W=0
H=0

[ListItem0]
Meter=Image
W=[#s_LeftPanelW]
H=([ListIcon0:H] > [ListTitle0:H]) ? [ListIcon0:H] : [ListTitle0:H]
Padding=0,[#s_ListAboutTopPadding],0,[#s_ListAboutBottomPadding]
SolidColor=255,255,255
MeterStyle=LeftPanel



[ListIcon0]
Meter=String
Text=
Container=ListItem0
MeterStyle=ListIcon | ListAboutIcon
Y=([#s_ListAboutTopPadding] + (([ListItem0:H] - [#s_ListAboutTotalPadding]) / 2) - ([#CURRENTSECTION#:H] / 2))
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory 0 "[#s_CurrentFile]"][#s_SaveLeftScroll][!Delay 1][!Refresh]

[ListTitle0]
Meter=String
Text=Theme: [#s_Theme1Name] 
MeterStyle=ListItem | ListAboutItem
ClipStringW=([#s_LeftPanelW] - [ListIcon0:W] - [#s_ListRightPadding] - [#s_ListAboutGap])
Y=([#s_ListAboutTopPadding] + (([ListItem0:H] - [#s_ListAboutTotalPadding]) / 2) - ([#CURRENTSECTION#:H] / 2))
X=R

FontWeight=[#s_SelectedFontWeight]
Container=ListItem0
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory 0 "[#s_CurrentFile]"][#s_SaveLeftScroll][!Delay 1][!Refresh]

[ListSelectedIndicator0]
Meter=Shape
Shape=Rectangle 0,[#s_SelectorPadding],([#s_SelectorWidth] * 2),((([ListIcon0:H] > [ListTitle0:H]) ? [ListIcon0:H] : [ListTitle0:H]) - ([#s_SelectorPadding] * 2)),[#s_SelectorRounding] | Extend Line, Square
Line=StrokeWidth 0
Square=Fill Color [#s_SelectedColor]
X=(-[#s_SelectorWidth])
Y=([#s_ListAboutTopPadding])
DynamicVariables=1
Container=ListItem0
Hidden=([#s_CurrentCategory] = 0) ? 0 : 1




[ListItem1]
Meter=Image
W=[#s_LeftPanelW]
H=([ListIcon1:H] > [ListTitle1:H]) ? [ListIcon1:H] : [ListTitle1:H]
Padding=0,[#s_ListDefaultTopPadding],0,[#s_ListDefaultBottomPadding]
SolidColor=255,255,255
MeterStyle=LeftPanel



[ListIcon1]
Meter=String
Text=
Container=ListItem1
MeterStyle=ListIcon | ListDefaultIcon
Y=([#s_ListDefaultTopPadding] + (([ListItem1:H] - [#s_ListDefaultTotalPadding]) / 2) - ([#CURRENTSECTION#:H] / 2))
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory 1 "[#s_CurrentFile]"][#s_SaveLeftScroll][!Refresh]

[ListTitle1]
Meter=String
Text=Close button
MeterStyle=ListItem | ListDefaultItem 
ClipStringW=([#s_LeftPanelW] - [ListIcon1:W] - [#s_ListRightPadding] - [#s_ListDefaultGap])
Y=([#s_ListDefaultTopPadding] + (([ListItem1:H] - [#s_ListDefaultTotalPadding]) / 2) - ([#CURRENTSECTION#:H] / 2))
X=R

FontWeight=([#s_CurrentCategory] = 1) ? [#s_SelectedFontWeight] : [#s_FontWeight]
Container=ListItem1
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory 1 "[#s_CurrentFile]"][#s_SaveLeftScroll][!Refresh]

[ListSelectedIndicator1]
Meter=Shape
Shape=Rectangle 0,[#s_SelectorPadding],([#s_SelectorWidth] * 2),((([ListIcon1:H] > [ListTitle1:H]) ? [ListIcon1:H] : [ListTitle1:H]) - ([#s_SelectorPadding] * 2)),[#s_SelectorRounding] | Extend Line, Square
Line=StrokeWidth 0
Square=Fill Color [#s_SelectedColor]
X=(-[#s_SelectorWidth])
Y=([#s_ListDefaultTopPadding])
DynamicVariables=1
Container=ListItem1
Hidden=([#s_CurrentCategory] = 1) ? 0 : 1




[ListItem2]
Meter=Image
W=[#s_LeftPanelW]
H=([ListIcon2:H] > [ListTitle2:H]) ? [ListIcon2:H] : [ListTitle2:H]
Padding=0,[#s_ListDefaultTopPadding],0,[#s_ListDefaultBottomPadding]
SolidColor=255,255,255
MeterStyle=LeftPanel



[ListIcon2]
Meter=String
Text=
Container=ListItem2
MeterStyle=ListIcon | ListDefaultIcon
Y=([#s_ListDefaultTopPadding] + (([ListItem2:H] - [#s_ListDefaultTotalPadding]) / 2) - ([#CURRENTSECTION#:H] / 2))
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory 2 "[#s_CurrentFile]"][#s_SaveLeftScroll][!Refresh]

[ListTitle2]
Meter=String
Text=Title bar
MeterStyle=ListItem | ListDefaultItem 
ClipStringW=([#s_LeftPanelW] - [ListIcon2:W] - [#s_ListRightPadding] - [#s_ListDefaultGap])
Y=([#s_ListDefaultTopPadding] + (([ListItem2:H] - [#s_ListDefaultTotalPadding]) / 2) - ([#CURRENTSECTION#:H] / 2))
X=R

FontWeight=([#s_CurrentCategory] = 2) ? [#s_SelectedFontWeight] : [#s_FontWeight]
Container=ListItem2
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory 2 "[#s_CurrentFile]"][#s_SaveLeftScroll][!Refresh]

[ListSelectedIndicator2]
Meter=Shape
Shape=Rectangle 0,[#s_SelectorPadding],([#s_SelectorWidth] * 2),((([ListIcon2:H] > [ListTitle2:H]) ? [ListIcon2:H] : [ListTitle2:H]) - ([#s_SelectorPadding] * 2)),[#s_SelectorRounding] | Extend Line, Square
Line=StrokeWidth 0
Square=Fill Color [#s_SelectedColor]
X=(-[#s_SelectorWidth])
Y=([#s_ListDefaultTopPadding])
DynamicVariables=1
Container=ListItem2
Hidden=([#s_CurrentCategory] = 2) ? 0 : 1




[ListItem3]
Meter=Image
W=[#s_LeftPanelW]
H=([ListIcon3:H] > [ListTitle3:H]) ? [ListIcon3:H] : [ListTitle3:H]
Padding=0,[#s_ListDefaultTopPadding],0,[#s_ListDefaultBottomPadding]
SolidColor=255,255,255
MeterStyle=LeftPanel



[ListIcon3]
Meter=String
Text=
Container=ListItem3
MeterStyle=ListIcon | ListDefaultIcon
Y=([#s_ListDefaultTopPadding] + (([ListItem3:H] - [#s_ListDefaultTotalPadding]) / 2) - ([#CURRENTSECTION#:H] / 2))
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory 3 "[#s_CurrentFile]"][#s_SaveLeftScroll][!Refresh]

[ListTitle3]
Meter=String
Text=Background
MeterStyle=ListItem | ListDefaultItem 
ClipStringW=([#s_LeftPanelW] - [ListIcon3:W] - [#s_ListRightPadding] - [#s_ListDefaultGap])
Y=([#s_ListDefaultTopPadding] + (([ListItem3:H] - [#s_ListDefaultTotalPadding]) / 2) - ([#CURRENTSECTION#:H] / 2))
X=R

FontWeight=([#s_CurrentCategory] = 3) ? [#s_SelectedFontWeight] : [#s_FontWeight]
Container=ListItem3
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory 3 "[#s_CurrentFile]"][#s_SaveLeftScroll][!Refresh]

[ListSelectedIndicator3]
Meter=Shape
Shape=Rectangle 0,[#s_SelectorPadding],([#s_SelectorWidth] * 2),((([ListIcon3:H] > [ListTitle3:H]) ? [ListIcon3:H] : [ListTitle3:H]) - ([#s_SelectorPadding] * 2)),[#s_SelectorRounding] | Extend Line, Square
Line=StrokeWidth 0
Square=Fill Color [#s_SelectedColor]
X=(-[#s_SelectorWidth])
Y=([#s_ListDefaultTopPadding])
DynamicVariables=1
Container=ListItem3
Hidden=([#s_CurrentCategory] = 3) ? 0 : 1




[ListItem4]
Meter=Image
W=[#s_LeftPanelW]
H=([ListIcon4:H] > [ListTitle4:H]) ? [ListIcon4:H] : [ListTitle4:H]
Padding=0,[#s_ListDefaultTopPadding],0,[#s_ListDefaultBottomPadding]
SolidColor=255,255,255
MeterStyle=LeftPanel



[ListIcon4]
Meter=String
Text=
Container=ListItem4
MeterStyle=ListIcon | ListDefaultIcon
Y=([#s_ListDefaultTopPadding] + (([ListItem4:H] - [#s_ListDefaultTotalPadding]) / 2) - ([#CURRENTSECTION#:H] / 2))
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory 4 "[#s_CurrentFile]"][#s_SaveLeftScroll][!Refresh]

[ListTitle4]
Meter=String
Text=Font
MeterStyle=ListItem | ListDefaultItem 
ClipStringW=([#s_LeftPanelW] - [ListIcon4:W] - [#s_ListRightPadding] - [#s_ListDefaultGap])
Y=([#s_ListDefaultTopPadding] + (([ListItem4:H] - [#s_ListDefaultTotalPadding]) / 2) - ([#CURRENTSECTION#:H] / 2))
X=R

FontWeight=([#s_CurrentCategory] = 4) ? [#s_SelectedFontWeight] : [#s_FontWeight]
Container=ListItem4
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory 4 "[#s_CurrentFile]"][#s_SaveLeftScroll][!Refresh]

[ListSelectedIndicator4]
Meter=Shape
Shape=Rectangle 0,[#s_SelectorPadding],([#s_SelectorWidth] * 2),((([ListIcon4:H] > [ListTitle4:H]) ? [ListIcon4:H] : [ListTitle4:H]) - ([#s_SelectorPadding] * 2)),[#s_SelectorRounding] | Extend Line, Square
Line=StrokeWidth 0
Square=Fill Color [#s_SelectedColor]
X=(-[#s_SelectorWidth])
Y=([#s_ListDefaultTopPadding])
DynamicVariables=1
Container=ListItem4
Hidden=([#s_CurrentCategory] = 4) ? 0 : 1




[ListItem5]
Meter=Image
W=[#s_LeftPanelW]
H=([ListIcon5:H] > [ListTitle5:H]) ? [ListIcon5:H] : [ListTitle5:H]
Padding=0,[#s_ListTopicTopPadding],0,[#s_ListTopicBottomPadding]
SolidColor=255,255,255
MeterStyle=LeftPanel



[ListIcon5]
Meter=String
Text=
Container=ListItem5
MeterStyle=ListIcon | ListTopicIcon
Y=([#s_ListTopicTopPadding] + (([ListItem5:H] - [#s_ListTopicTotalPadding]) / 2) - ([#CURRENTSECTION#:H] / 2))


[ListTitle5]
Meter=String
Text=Indicators
MeterStyle=ListItem | ListTopicItem 
ClipStringW=([#s_LeftPanelW] - [ListIcon5:W] - [#s_ListRightPadding] - [#s_ListTopicGap])
Y=([#s_ListTopicTopPadding] + (([ListItem5:H] - [#s_ListTopicTotalPadding]) / 2) - ([#CURRENTSECTION#:H] / 2))
X=R

FontWeight=([#s_CurrentCategory] = 5) ? [#s_SelectedFontWeight] : [#s_FontWeight]
Container=ListItem5

[ListSelectedIndicator5]
Meter=Shape
Shape=Rectangle 0,[#s_SelectorPadding],([#s_SelectorWidth] * 2),((([ListIcon5:H] > [ListTitle5:H]) ? [ListIcon5:H] : [ListTitle5:H]) - ([#s_SelectorPadding] * 2)),[#s_SelectorRounding] | Extend Line, Square
Line=StrokeWidth 0
Square=Fill Color [#s_SelectedColor]
X=(-[#s_SelectorWidth])
Y=([#s_ListTopicTopPadding])
DynamicVariables=1
Container=ListItem5
Hidden=([#s_CurrentCategory] = 5) ? 0 : 1




[ListItem6]
Meter=Image
W=[#s_LeftPanelW]
H=([ListIcon6:H] > [ListTitle6:H]) ? [ListIcon6:H] : [ListTitle6:H]
Padding=0,[#s_ListDefaultTopPadding],0,[#s_ListDefaultBottomPadding]
SolidColor=255,255,255
MeterStyle=LeftPanel



[ListIcon6]
Meter=String
Text=
Container=ListItem6
MeterStyle=ListIcon | ListDefaultIcon
Y=([#s_ListDefaultTopPadding] + (([ListItem6:H] - [#s_ListDefaultTotalPadding]) / 2) - ([#CURRENTSECTION#:H] / 2))
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory 6 "[#s_CurrentFile]"][#s_SaveLeftScroll][!Refresh]

[ListTitle6]
Meter=String
Text=Right scroll indicator
MeterStyle=ListItem | ListDefaultItem 
ClipStringW=([#s_LeftPanelW] - [ListIcon6:W] - [#s_ListRightPadding] - [#s_ListDefaultGap])
Y=([#s_ListDefaultTopPadding] + (([ListItem6:H] - [#s_ListDefaultTotalPadding]) / 2) - ([#CURRENTSECTION#:H] / 2))
X=R

FontWeight=([#s_CurrentCategory] = 6) ? [#s_SelectedFontWeight] : [#s_FontWeight]
Container=ListItem6
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory 6 "[#s_CurrentFile]"][#s_SaveLeftScroll][!Refresh]

[ListSelectedIndicator6]
Meter=Shape
Shape=Rectangle 0,[#s_SelectorPadding],([#s_SelectorWidth] * 2),((([ListIcon6:H] > [ListTitle6:H]) ? [ListIcon6:H] : [ListTitle6:H]) - ([#s_SelectorPadding] * 2)),[#s_SelectorRounding] | Extend Line, Square
Line=StrokeWidth 0
Square=Fill Color [#s_SelectedColor]
X=(-[#s_SelectorWidth])
Y=([#s_ListDefaultTopPadding])
DynamicVariables=1
Container=ListItem6
Hidden=([#s_CurrentCategory] = 6) ? 0 : 1




[ListItem7]
Meter=Image
W=[#s_LeftPanelW]
H=([ListIcon7:H] > [ListTitle7:H]) ? [ListIcon7:H] : [ListTitle7:H]
Padding=0,[#s_ListDefaultTopPadding],0,[#s_ListDefaultBottomPadding]
SolidColor=255,255,255
MeterStyle=LeftPanel



[ListIcon7]
Meter=String
Text=
Container=ListItem7
MeterStyle=ListIcon | ListDefaultIcon
Y=([#s_ListDefaultTopPadding] + (([ListItem7:H] - [#s_ListDefaultTotalPadding]) / 2) - ([#CURRENTSECTION#:H] / 2))
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory 7 "[#s_CurrentFile]"][#s_SaveLeftScroll][!Refresh]

[ListTitle7]
Meter=String
Text=Left scroll indicator
MeterStyle=ListItem | ListDefaultItem 
ClipStringW=([#s_LeftPanelW] - [ListIcon7:W] - [#s_ListRightPadding] - [#s_ListDefaultGap])
Y=([#s_ListDefaultTopPadding] + (([ListItem7:H] - [#s_ListDefaultTotalPadding]) / 2) - ([#CURRENTSECTION#:H] / 2))
X=R

FontWeight=([#s_CurrentCategory] = 7) ? [#s_SelectedFontWeight] : [#s_FontWeight]
Container=ListItem7
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory 7 "[#s_CurrentFile]"][#s_SaveLeftScroll][!Refresh]

[ListSelectedIndicator7]
Meter=Shape
Shape=Rectangle 0,[#s_SelectorPadding],([#s_SelectorWidth] * 2),((([ListIcon7:H] > [ListTitle7:H]) ? [ListIcon7:H] : [ListTitle7:H]) - ([#s_SelectorPadding] * 2)),[#s_SelectorRounding] | Extend Line, Square
Line=StrokeWidth 0
Square=Fill Color [#s_SelectedColor]
X=(-[#s_SelectorWidth])
Y=([#s_ListDefaultTopPadding])
DynamicVariables=1
Container=ListItem7
Hidden=([#s_CurrentCategory] = 7) ? 0 : 1




[ListItem8]
Meter=Image
W=[#s_LeftPanelW]
H=([ListIcon8:H] > [ListTitle8:H]) ? [ListIcon8:H] : [ListTitle8:H]
Padding=0,[#s_ListDefaultTopPadding],0,[#s_ListDefaultBottomPadding]
SolidColor=255,255,255
MeterStyle=LeftPanel



[ListIcon8]
Meter=String
Text=
Container=ListItem8
MeterStyle=ListIcon | ListDefaultIcon
Y=([#s_ListDefaultTopPadding] + (([ListItem8:H] - [#s_ListDefaultTotalPadding]) / 2) - ([#CURRENTSECTION#:H] / 2))
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory 8 "[#s_CurrentFile]"][#s_SaveLeftScroll][!Refresh]

[ListTitle8]
Meter=String
Text=Selected indicator
MeterStyle=ListItem | ListDefaultItem 
ClipStringW=([#s_LeftPanelW] - [ListIcon8:W] - [#s_ListRightPadding] - [#s_ListDefaultGap])
Y=([#s_ListDefaultTopPadding] + (([ListItem8:H] - [#s_ListDefaultTotalPadding]) / 2) - ([#CURRENTSECTION#:H] / 2))
X=R

FontWeight=([#s_CurrentCategory] = 8) ? [#s_SelectedFontWeight] : [#s_FontWeight]
Container=ListItem8
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory 8 "[#s_CurrentFile]"][#s_SaveLeftScroll][!Refresh]

[ListSelectedIndicator8]
Meter=Shape
Shape=Rectangle 0,[#s_SelectorPadding],([#s_SelectorWidth] * 2),((([ListIcon8:H] > [ListTitle8:H]) ? [ListIcon8:H] : [ListTitle8:H]) - ([#s_SelectorPadding] * 2)),[#s_SelectorRounding] | Extend Line, Square
Line=StrokeWidth 0
Square=Fill Color [#s_SelectedColor]
X=(-[#s_SelectorWidth])
Y=([#s_ListDefaultTopPadding])
DynamicVariables=1
Container=ListItem8
Hidden=([#s_CurrentCategory] = 8) ? 0 : 1




[ListItem9]
Meter=Image
W=[#s_LeftPanelW]
H=([ListIcon9:H] > [ListTitle9:H]) ? [ListIcon9:H] : [ListTitle9:H]
Padding=0,[#s_ListTopicTopPadding],0,[#s_ListTopicBottomPadding]
SolidColor=255,255,255
MeterStyle=LeftPanel



[ListIcon9]
Meter=String
Text=
Container=ListItem9
MeterStyle=ListIcon | ListTopicIcon
Y=([#s_ListTopicTopPadding] + (([ListItem9:H] - [#s_ListTopicTotalPadding]) / 2) - ([#CURRENTSECTION#:H] / 2))


[ListTitle9]
Meter=String
Text=Categories
MeterStyle=ListItem | ListTopicItem 
ClipStringW=([#s_LeftPanelW] - [ListIcon9:W] - [#s_ListRightPadding] - [#s_ListTopicGap])
Y=([#s_ListTopicTopPadding] + (([ListItem9:H] - [#s_ListTopicTotalPadding]) / 2) - ([#CURRENTSECTION#:H] / 2))
X=R

FontWeight=([#s_CurrentCategory] = 9) ? [#s_SelectedFontWeight] : [#s_FontWeight]
Container=ListItem9

[ListSelectedIndicator9]
Meter=Shape
Shape=Rectangle 0,[#s_SelectorPadding],([#s_SelectorWidth] * 2),((([ListIcon9:H] > [ListTitle9:H]) ? [ListIcon9:H] : [ListTitle9:H]) - ([#s_SelectorPadding] * 2)),[#s_SelectorRounding] | Extend Line, Square
Line=StrokeWidth 0
Square=Fill Color [#s_SelectedColor]
X=(-[#s_SelectorWidth])
Y=([#s_ListTopicTopPadding])
DynamicVariables=1
Container=ListItem9
Hidden=([#s_CurrentCategory] = 9) ? 0 : 1




[ListItem10]
Meter=Image
W=[#s_LeftPanelW]
H=([ListIcon10:H] > [ListTitle10:H]) ? [ListIcon10:H] : [ListTitle10:H]
Padding=0,[#s_ListDefaultTopPadding],0,[#s_ListDefaultBottomPadding]
SolidColor=255,255,255
MeterStyle=LeftPanel



[ListIcon10]
Meter=String
Text=
Container=ListItem10
MeterStyle=ListIcon | ListDefaultIcon
Y=([#s_ListDefaultTopPadding] + (([ListItem10:H] - [#s_ListDefaultTotalPadding]) / 2) - ([#CURRENTSECTION#:H] / 2))
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory 10 "[#s_CurrentFile]"][#s_SaveLeftScroll][!Refresh]

[ListTitle10]
Meter=String
Text=Category
MeterStyle=ListItem | ListDefaultItem 
ClipStringW=([#s_LeftPanelW] - [ListIcon10:W] - [#s_ListRightPadding] - [#s_ListDefaultGap])
Y=([#s_ListDefaultTopPadding] + (([ListItem10:H] - [#s_ListDefaultTotalPadding]) / 2) - ([#CURRENTSECTION#:H] / 2))
X=R

FontWeight=([#s_CurrentCategory] = 10) ? [#s_SelectedFontWeight] : [#s_FontWeight]
Container=ListItem10
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory 10 "[#s_CurrentFile]"][#s_SaveLeftScroll][!Refresh]

[ListSelectedIndicator10]
Meter=Shape
Shape=Rectangle 0,[#s_SelectorPadding],([#s_SelectorWidth] * 2),((([ListIcon10:H] > [ListTitle10:H]) ? [ListIcon10:H] : [ListTitle10:H]) - ([#s_SelectorPadding] * 2)),[#s_SelectorRounding] | Extend Line, Square
Line=StrokeWidth 0
Square=Fill Color [#s_SelectedColor]
X=(-[#s_SelectorWidth])
Y=([#s_ListDefaultTopPadding])
DynamicVariables=1
Container=ListItem10
Hidden=([#s_CurrentCategory] = 10) ? 0 : 1




[ListItem11]
Meter=Image
W=[#s_LeftPanelW]
H=([ListIcon11:H] > [ListTitle11:H]) ? [ListIcon11:H] : [ListTitle11:H]
Padding=0,[#s_ListTopicTopPadding],0,[#s_ListTopicBottomPadding]
SolidColor=255,255,255
MeterStyle=LeftPanel



[ListIcon11]
Meter=String
Text=
Container=ListItem11
MeterStyle=ListIcon | ListTopicIcon
Y=([#s_ListTopicTopPadding] + (([ListItem11:H] - [#s_ListTopicTotalPadding]) / 2) - ([#CURRENTSECTION#:H] / 2))


[ListTitle11]
Meter=String
Text=Category list
MeterStyle=ListItem | ListTopicItem 
ClipStringW=([#s_LeftPanelW] - [ListIcon11:W] - [#s_ListRightPadding] - [#s_ListTopicGap])
Y=([#s_ListTopicTopPadding] + (([ListItem11:H] - [#s_ListTopicTotalPadding]) / 2) - ([#CURRENTSECTION#:H] / 2))
X=R

FontWeight=([#s_CurrentCategory] = 11) ? [#s_SelectedFontWeight] : [#s_FontWeight]
Container=ListItem11

[ListSelectedIndicator11]
Meter=Shape
Shape=Rectangle 0,[#s_SelectorPadding],([#s_SelectorWidth] * 2),((([ListIcon11:H] > [ListTitle11:H]) ? [ListIcon11:H] : [ListTitle11:H]) - ([#s_SelectorPadding] * 2)),[#s_SelectorRounding] | Extend Line, Square
Line=StrokeWidth 0
Square=Fill Color [#s_SelectedColor]
X=(-[#s_SelectorWidth])
Y=([#s_ListTopicTopPadding])
DynamicVariables=1
Container=ListItem11
Hidden=([#s_CurrentCategory] = 11) ? 0 : 1




[ListItem12]
Meter=Image
W=[#s_LeftPanelW]
H=([ListIcon12:H] > [ListTitle12:H]) ? [ListIcon12:H] : [ListTitle12:H]
Padding=0,[#s_ListDefaultTopPadding],0,[#s_ListDefaultBottomPadding]
SolidColor=255,255,255
MeterStyle=LeftPanel



[ListIcon12]
Meter=String
Text=
Container=ListItem12
MeterStyle=ListIcon | ListDefaultIcon
Y=([#s_ListDefaultTopPadding] + (([ListItem12:H] - [#s_ListDefaultTotalPadding]) / 2) - ([#CURRENTSECTION#:H] / 2))
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory 12 "[#s_CurrentFile]"][#s_SaveLeftScroll][!Refresh]

[ListTitle12]
Meter=String
Text=General
MeterStyle=ListItem | ListDefaultItem 
ClipStringW=([#s_LeftPanelW] - [ListIcon12:W] - [#s_ListRightPadding] - [#s_ListDefaultGap])
Y=([#s_ListDefaultTopPadding] + (([ListItem12:H] - [#s_ListDefaultTotalPadding]) / 2) - ([#CURRENTSECTION#:H] / 2))
X=R

FontWeight=([#s_CurrentCategory] = 12) ? [#s_SelectedFontWeight] : [#s_FontWeight]
Container=ListItem12
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory 12 "[#s_CurrentFile]"][#s_SaveLeftScroll][!Refresh]

[ListSelectedIndicator12]
Meter=Shape
Shape=Rectangle 0,[#s_SelectorPadding],([#s_SelectorWidth] * 2),((([ListIcon12:H] > [ListTitle12:H]) ? [ListIcon12:H] : [ListTitle12:H]) - ([#s_SelectorPadding] * 2)),[#s_SelectorRounding] | Extend Line, Square
Line=StrokeWidth 0
Square=Fill Color [#s_SelectedColor]
X=(-[#s_SelectorWidth])
Y=([#s_ListDefaultTopPadding])
DynamicVariables=1
Container=ListItem12
Hidden=([#s_CurrentCategory] = 12) ? 0 : 1




[ListItem13]
Meter=Image
W=[#s_LeftPanelW]
H=([ListIcon13:H] > [ListTitle13:H]) ? [ListIcon13:H] : [ListTitle13:H]
Padding=0,[#s_ListDefaultTopPadding],0,[#s_ListDefaultBottomPadding]
SolidColor=255,255,255
MeterStyle=LeftPanel



[ListIcon13]
Meter=String
Text=
Container=ListItem13
MeterStyle=ListIcon | ListDefaultIcon
Y=([#s_ListDefaultTopPadding] + (([ListItem13:H] - [#s_ListDefaultTotalPadding]) / 2) - ([#CURRENTSECTION#:H] / 2))
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory 13 "[#s_CurrentFile]"][#s_SaveLeftScroll][!Refresh]

[ListTitle13]
Meter=String
Text=About items
MeterStyle=ListItem | ListDefaultItem 
ClipStringW=([#s_LeftPanelW] - [ListIcon13:W] - [#s_ListRightPadding] - [#s_ListDefaultGap])
Y=([#s_ListDefaultTopPadding] + (([ListItem13:H] - [#s_ListDefaultTotalPadding]) / 2) - ([#CURRENTSECTION#:H] / 2))
X=R

FontWeight=([#s_CurrentCategory] = 13) ? [#s_SelectedFontWeight] : [#s_FontWeight]
Container=ListItem13
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory 13 "[#s_CurrentFile]"][#s_SaveLeftScroll][!Refresh]

[ListSelectedIndicator13]
Meter=Shape
Shape=Rectangle 0,[#s_SelectorPadding],([#s_SelectorWidth] * 2),((([ListIcon13:H] > [ListTitle13:H]) ? [ListIcon13:H] : [ListTitle13:H]) - ([#s_SelectorPadding] * 2)),[#s_SelectorRounding] | Extend Line, Square
Line=StrokeWidth 0
Square=Fill Color [#s_SelectedColor]
X=(-[#s_SelectorWidth])
Y=([#s_ListDefaultTopPadding])
DynamicVariables=1
Container=ListItem13
Hidden=([#s_CurrentCategory] = 13) ? 0 : 1




[ListItem14]
Meter=Image
W=[#s_LeftPanelW]
H=([ListIcon14:H] > [ListTitle14:H]) ? [ListIcon14:H] : [ListTitle14:H]
Padding=0,[#s_ListDefaultTopPadding],0,[#s_ListDefaultBottomPadding]
SolidColor=255,255,255
MeterStyle=LeftPanel



[ListIcon14]
Meter=String
Text=
Container=ListItem14
MeterStyle=ListIcon | ListDefaultIcon
Y=([#s_ListDefaultTopPadding] + (([ListItem14:H] - [#s_ListDefaultTotalPadding]) / 2) - ([#CURRENTSECTION#:H] / 2))
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory 14 "[#s_CurrentFile]"][#s_SaveLeftScroll][!Refresh]

[ListTitle14]
Meter=String
Text=Default items
MeterStyle=ListItem | ListDefaultItem 
ClipStringW=([#s_LeftPanelW] - [ListIcon14:W] - [#s_ListRightPadding] - [#s_ListDefaultGap])
Y=([#s_ListDefaultTopPadding] + (([ListItem14:H] - [#s_ListDefaultTotalPadding]) / 2) - ([#CURRENTSECTION#:H] / 2))
X=R

FontWeight=([#s_CurrentCategory] = 14) ? [#s_SelectedFontWeight] : [#s_FontWeight]
Container=ListItem14
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory 14 "[#s_CurrentFile]"][#s_SaveLeftScroll][!Refresh]

[ListSelectedIndicator14]
Meter=Shape
Shape=Rectangle 0,[#s_SelectorPadding],([#s_SelectorWidth] * 2),((([ListIcon14:H] > [ListTitle14:H]) ? [ListIcon14:H] : [ListTitle14:H]) - ([#s_SelectorPadding] * 2)),[#s_SelectorRounding] | Extend Line, Square
Line=StrokeWidth 0
Square=Fill Color [#s_SelectedColor]
X=(-[#s_SelectorWidth])
Y=([#s_ListDefaultTopPadding])
DynamicVariables=1
Container=ListItem14
Hidden=([#s_CurrentCategory] = 14) ? 0 : 1




[ListItem15]
Meter=Image
W=[#s_LeftPanelW]
H=([ListIcon15:H] > [ListTitle15:H]) ? [ListIcon15:H] : [ListTitle15:H]
Padding=0,[#s_ListDefaultTopPadding],0,[#s_ListDefaultBottomPadding]
SolidColor=255,255,255
MeterStyle=LeftPanel



[ListIcon15]
Meter=String
Text=
Container=ListItem15
MeterStyle=ListIcon | ListDefaultIcon
Y=([#s_ListDefaultTopPadding] + (([ListItem15:H] - [#s_ListDefaultTotalPadding]) / 2) - ([#CURRENTSECTION#:H] / 2))
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory 15 "[#s_CurrentFile]"][#s_SaveLeftScroll][!Refresh]

[ListTitle15]
Meter=String
Text=Topic items
MeterStyle=ListItem | ListDefaultItem 
ClipStringW=([#s_LeftPanelW] - [ListIcon15:W] - [#s_ListRightPadding] - [#s_ListDefaultGap])
Y=([#s_ListDefaultTopPadding] + (([ListItem15:H] - [#s_ListDefaultTotalPadding]) / 2) - ([#CURRENTSECTION#:H] / 2))
X=R

FontWeight=([#s_CurrentCategory] = 15) ? [#s_SelectedFontWeight] : [#s_FontWeight]
Container=ListItem15
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory 15 "[#s_CurrentFile]"][#s_SaveLeftScroll][!Refresh]

[ListSelectedIndicator15]
Meter=Shape
Shape=Rectangle 0,[#s_SelectorPadding],([#s_SelectorWidth] * 2),((([ListIcon15:H] > [ListTitle15:H]) ? [ListIcon15:H] : [ListTitle15:H]) - ([#s_SelectorPadding] * 2)),[#s_SelectorRounding] | Extend Line, Square
Line=StrokeWidth 0
Square=Fill Color [#s_SelectedColor]
X=(-[#s_SelectorWidth])
Y=([#s_ListDefaultTopPadding])
DynamicVariables=1
Container=ListItem15
Hidden=([#s_CurrentCategory] = 15) ? 0 : 1




[ListItem16]
Meter=Image
W=[#s_LeftPanelW]
H=([ListIcon16:H] > [ListTitle16:H]) ? [ListIcon16:H] : [ListTitle16:H]
Padding=0,[#s_ListTopicTopPadding],0,[#s_ListTopicBottomPadding]
SolidColor=255,255,255
MeterStyle=LeftPanel



[ListIcon16]
Meter=String
Text=
Container=ListItem16
MeterStyle=ListIcon | ListTopicIcon
Y=([#s_ListTopicTopPadding] + (([ListItem16:H] - [#s_ListTopicTotalPadding]) / 2) - ([#CURRENTSECTION#:H] / 2))


[ListTitle16]
Meter=String
Text=Variables
MeterStyle=ListItem | ListTopicItem 
ClipStringW=([#s_LeftPanelW] - [ListIcon16:W] - [#s_ListRightPadding] - [#s_ListTopicGap])
Y=([#s_ListTopicTopPadding] + (([ListItem16:H] - [#s_ListTopicTotalPadding]) / 2) - ([#CURRENTSECTION#:H] / 2))
X=R

FontWeight=([#s_CurrentCategory] = 16) ? [#s_SelectedFontWeight] : [#s_FontWeight]
Container=ListItem16

[ListSelectedIndicator16]
Meter=Shape
Shape=Rectangle 0,[#s_SelectorPadding],([#s_SelectorWidth] * 2),((([ListIcon16:H] > [ListTitle16:H]) ? [ListIcon16:H] : [ListTitle16:H]) - ([#s_SelectorPadding] * 2)),[#s_SelectorRounding] | Extend Line, Square
Line=StrokeWidth 0
Square=Fill Color [#s_SelectedColor]
X=(-[#s_SelectorWidth])
Y=([#s_ListTopicTopPadding])
DynamicVariables=1
Container=ListItem16
Hidden=([#s_CurrentCategory] = 16) ? 0 : 1




[ListItem17]
Meter=Image
W=[#s_LeftPanelW]
H=([ListIcon17:H] > [ListTitle17:H]) ? [ListIcon17:H] : [ListTitle17:H]
Padding=0,[#s_ListDefaultTopPadding],0,[#s_ListDefaultBottomPadding]
SolidColor=255,255,255
MeterStyle=LeftPanel



[ListIcon17]
Meter=String
Text=
Container=ListItem17
MeterStyle=ListIcon | ListDefaultIcon
Y=([#s_ListDefaultTopPadding] + (([ListItem17:H] - [#s_ListDefaultTotalPadding]) / 2) - ([#CURRENTSECTION#:H] / 2))
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory 17 "[#s_CurrentFile]"][#s_SaveLeftScroll][!Refresh]

[ListTitle17]
Meter=String
Text=Variable
MeterStyle=ListItem | ListDefaultItem 
ClipStringW=([#s_LeftPanelW] - [ListIcon17:W] - [#s_ListRightPadding] - [#s_ListDefaultGap])
Y=([#s_ListDefaultTopPadding] + (([ListItem17:H] - [#s_ListDefaultTotalPadding]) / 2) - ([#CURRENTSECTION#:H] / 2))
X=R

FontWeight=([#s_CurrentCategory] = 17) ? [#s_SelectedFontWeight] : [#s_FontWeight]
Container=ListItem17
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory 17 "[#s_CurrentFile]"][#s_SaveLeftScroll][!Refresh]

[ListSelectedIndicator17]
Meter=Shape
Shape=Rectangle 0,[#s_SelectorPadding],([#s_SelectorWidth] * 2),((([ListIcon17:H] > [ListTitle17:H]) ? [ListIcon17:H] : [ListTitle17:H]) - ([#s_SelectorPadding] * 2)),[#s_SelectorRounding] | Extend Line, Square
Line=StrokeWidth 0
Square=Fill Color [#s_SelectedColor]
X=(-[#s_SelectorWidth])
Y=([#s_ListDefaultTopPadding])
DynamicVariables=1
Container=ListItem17
Hidden=([#s_CurrentCategory] = 17) ? 0 : 1




[ListItem18]
Meter=Image
W=[#s_LeftPanelW]
H=([ListIcon18:H] > [ListTitle18:H]) ? [ListIcon18:H] : [ListTitle18:H]
Padding=0,[#s_ListDefaultTopPadding],0,[#s_ListDefaultBottomPadding]
SolidColor=255,255,255
MeterStyle=LeftPanel



[ListIcon18]
Meter=String
Text=
Container=ListItem18
MeterStyle=ListIcon | ListDefaultIcon
Y=([#s_ListDefaultTopPadding] + (([ListItem18:H] - [#s_ListDefaultTotalPadding]) / 2) - ([#CURRENTSECTION#:H] / 2))
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory 18 "[#s_CurrentFile]"][#s_SaveLeftScroll][!Refresh]

[ListTitle18]
Meter=String
Text=Color
MeterStyle=ListItem | ListDefaultItem 
ClipStringW=([#s_LeftPanelW] - [ListIcon18:W] - [#s_ListRightPadding] - [#s_ListDefaultGap])
Y=([#s_ListDefaultTopPadding] + (([ListItem18:H] - [#s_ListDefaultTotalPadding]) / 2) - ([#CURRENTSECTION#:H] / 2))
X=R

FontWeight=([#s_CurrentCategory] = 18) ? [#s_SelectedFontWeight] : [#s_FontWeight]
Container=ListItem18
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory 18 "[#s_CurrentFile]"][#s_SaveLeftScroll][!Refresh]

[ListSelectedIndicator18]
Meter=Shape
Shape=Rectangle 0,[#s_SelectorPadding],([#s_SelectorWidth] * 2),((([ListIcon18:H] > [ListTitle18:H]) ? [ListIcon18:H] : [ListTitle18:H]) - ([#s_SelectorPadding] * 2)),[#s_SelectorRounding] | Extend Line, Square
Line=StrokeWidth 0
Square=Fill Color [#s_SelectedColor]
X=(-[#s_SelectorWidth])
Y=([#s_ListDefaultTopPadding])
DynamicVariables=1
Container=ListItem18
Hidden=([#s_CurrentCategory] = 18) ? 0 : 1




[ListItem19]
Meter=Image
W=[#s_LeftPanelW]
H=([ListIcon19:H] > [ListTitle19:H]) ? [ListIcon19:H] : [ListTitle19:H]
Padding=0,[#s_ListDefaultTopPadding],0,[#s_ListDefaultBottomPadding]
SolidColor=255,255,255
MeterStyle=LeftPanel



[ListIcon19]
Meter=String
Text=
Container=ListItem19
MeterStyle=ListIcon | ListDefaultIcon
Y=([#s_ListDefaultTopPadding] + (([ListItem19:H] - [#s_ListDefaultTotalPadding]) / 2) - ([#CURRENTSECTION#:H] / 2))
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory 19 "[#s_CurrentFile]"][#s_SaveLeftScroll][!Refresh]

[ListTitle19]
Meter=String
Text=Toggle
MeterStyle=ListItem | ListDefaultItem 
ClipStringW=([#s_LeftPanelW] - [ListIcon19:W] - [#s_ListRightPadding] - [#s_ListDefaultGap])
Y=([#s_ListDefaultTopPadding] + (([ListItem19:H] - [#s_ListDefaultTotalPadding]) / 2) - ([#CURRENTSECTION#:H] / 2))
X=R

FontWeight=([#s_CurrentCategory] = 19) ? [#s_SelectedFontWeight] : [#s_FontWeight]
Container=ListItem19
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory 19 "[#s_CurrentFile]"][#s_SaveLeftScroll][!Refresh]

[ListSelectedIndicator19]
Meter=Shape
Shape=Rectangle 0,[#s_SelectorPadding],([#s_SelectorWidth] * 2),((([ListIcon19:H] > [ListTitle19:H]) ? [ListIcon19:H] : [ListTitle19:H]) - ([#s_SelectorPadding] * 2)),[#s_SelectorRounding] | Extend Line, Square
Line=StrokeWidth 0
Square=Fill Color [#s_SelectedColor]
X=(-[#s_SelectorWidth])
Y=([#s_ListDefaultTopPadding])
DynamicVariables=1
Container=ListItem19
Hidden=([#s_CurrentCategory] = 19) ? 0 : 1




[ListItem20]
Meter=Image
W=[#s_LeftPanelW]
H=([ListIcon20:H] > [ListTitle20:H]) ? [ListIcon20:H] : [ListTitle20:H]
Padding=0,[#s_ListDefaultTopPadding],0,[#s_ListDefaultBottomPadding]
SolidColor=255,255,255
MeterStyle=LeftPanel



[ListIcon20]
Meter=String
Text=
Container=ListItem20
MeterStyle=ListIcon | ListDefaultIcon
Y=([#s_ListDefaultTopPadding] + (([ListItem20:H] - [#s_ListDefaultTotalPadding]) / 2) - ([#CURRENTSECTION#:H] / 2))
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory 20 "[#s_CurrentFile]"][#s_SaveLeftScroll][!Refresh]

[ListTitle20]
Meter=String
Text=Slider
MeterStyle=ListItem | ListDefaultItem 
ClipStringW=([#s_LeftPanelW] - [ListIcon20:W] - [#s_ListRightPadding] - [#s_ListDefaultGap])
Y=([#s_ListDefaultTopPadding] + (([ListItem20:H] - [#s_ListDefaultTotalPadding]) / 2) - ([#CURRENTSECTION#:H] / 2))
X=R

FontWeight=([#s_CurrentCategory] = 20) ? [#s_SelectedFontWeight] : [#s_FontWeight]
Container=ListItem20
LeftMouseUpAction=[!WriteKeyValue Variables s_CurrentCategory 20 "[#s_CurrentFile]"][#s_SaveLeftScroll][!Refresh]

[ListSelectedIndicator20]
Meter=Shape
Shape=Rectangle 0,[#s_SelectorPadding],([#s_SelectorWidth] * 2),((([ListIcon20:H] > [ListTitle20:H]) ? [ListIcon20:H] : [ListTitle20:H]) - ([#s_SelectorPadding] * 2)),[#s_SelectorRounding] | Extend Line, Square
Line=StrokeWidth 0
Square=Fill Color [#s_SelectedColor]
X=(-[#s_SelectorWidth])
Y=([#s_ListDefaultTopPadding])
DynamicVariables=1
Container=ListItem20
Hidden=([#s_CurrentCategory] = 20) ? 0 : 1




[LastLeft]
Meter=String
Text=Last
FontColor=255,0,0,0
MeterStyle=LastItem | LeftPanel

[ScrollDownLeft]
Measure=Calc
Formula=[#s_ScrollLeft] - [#s_ScrollSpeed]
IfCondition=([LastLeft:Y] > [#s_PanelH])
IfTrueAction=[!SetVariable "s_ScrollLeft" "[&ScrollDownLeft]"][!DisableMeasure "ScrollDownLeft"][!Update][#s_SaveScroll]
IfFalseAction=[!DisableMeasure "ScrollDownLeft"]
IfConditionMode=1
Disabled=1
DynamicVariables=1

[ScrollUpLeft]
Measure=Calc
Formula=[#s_ScrollLeft] + [#s_ScrollSpeed]
IfCondition=([FirstLeft:Y] < [#s_TopHeight])
IfTrueAction=[!SetVariable "s_ScrollLeft" "[&ScrollUpLeft]"][!DisableMeasure "ScrollUpLeft"][!Update][#s_SaveScroll]
IfFalseAction=[!DisableMeasure "ScrollUpLeft"]
IfConditionMode=1
Disabled=1
DynamicVariables=1

; [CreditIcon]
; FontSize=[#s_CreditIconSize]
; AntiAlias=1
; Meter=String
; Text=[\xF259]
; FontWeight=400
; Padding=0,0,0,0
; DynamicVariables=1
; SolidColor=0,0,0,1
; MeterStyle=LeftPanel
; FontColor=[#s_FontColor]
; X=[#s_CreditIconPadding]
; FontWeight=[#s_FontWeight]
; FontFace=Segoe MDL2 Assets
; ToolTipTitle=Generated by Settings
; ToolTipText=https://github.com/sceleri/settings
; LeftMouseUpAction=["https://github.com/sceleri/settings"]
; Y=([#s_PanelH] - [CreditIcon:H] - [#s_CreditIconPadding])


