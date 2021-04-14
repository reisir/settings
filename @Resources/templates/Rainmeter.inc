[Rainmeter]
Update=-1
DefaultUpdateDivider=-1

[Variables]
s_FontFace=Segoe UI
s_IconFontFace=Segoe MDL2 Assets
s_FontColor=0,0,0


s_FontSize5 = 8
s_FontSize4 = 10
s_FontSize3 = 12
s_FontSize2 = 16
s_FontSize1 = 20
s_InputTextFontSize=#s_FontSize3#

s_LeftPanelW = 200
s_RightPanelW = 600
s_PanelH = 700

s_ListIconLeftPadding=20
s_ListItemPadding=5
s_ListItemLeftPadding=10
s_ListItemTopPadding = 7
s_ListIconTopPadding = 10

s_VariablePadding = 10
s_VariableLeftPadding = 20

s_CategoryTitleTopPadding = 35
s_CategoryIconTopPadding = 40
s_CategoryIconLeftPadding = 20

s_SelectedFontWeight = 500
s_TitleFontWeight = 500

s_RightPanelBackgroundColor=255,255,255,255
s_LeftPanelBackgroundColor=200,200,200,200

s_BackgroundRounding=5

s_CurrentCategory=0

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

[RightPanelContainer]
Meter=Shape
Shape=Rectangle 0,0,(#s_RightPanelW#),(#s_PanelH#) | Extend PanelModifiers
PanelModifiers=Fill Color 255,255,255 | StrokeWidth 0
X=(#s_LeftPanelW#)

[LeftPanel]
Container=LeftPanelContainer

[RightPanel]
Container=RightPanelContainer

[FirstItem]
H=0
W=0
Y=0
X=0
SolidColor=0,0,0,0

;Category list styles

[CategoryListIcon]
X=0
Y=0R
FontSize=#s_FontSize3#
FontFace=#s_IconFontFace#
Padding=[#s_ListIconLeftPadding],[#s_ListIconTopPadding],0,[#s_ListItemPadding]
AccurateText=1
AntiAlias=1

[CategoryListItem]
Y=0r
FontSize=#s_FontSize3#
FontFace=#s_FontFace#
Padding=[#s_ListItemLeftPadding],[#s_ListItemTopPadding],[#s_ListItemPadding],[#s_ListItemPadding]
AccurateText=1
AntiAlias=1
DynamicVariables=1

[CategoryListSuperItem]
Y=0r
FontSize=#s_FontSize4#
FontFace=#s_FontFace#
Padding=[#s_ListItemLeftPadding],[#s_ListItemTopPadding],[#s_ListItemPadding],[#s_ListItemPadding]
AccurateText=1
AntiAlias=1
DynamicVariables=1

[CategoryListAboutItem]
Y=0r
FontSize=#s_FontSize2#
FontFace=#s_FontFace#
Padding=[#s_ListItemLeftPadding],[#s_ListItemTopPadding],[#s_ListItemPadding],[#s_ListItemPadding]
AccurateText=1
AntiAlias=1
DynamicVariables=1

;Category styles

[CategoryIcon]
X=0
Y=0R
FontSize=#s_FontSize1#
FontFace=#s_IconFontFace#
Padding=[#s_CategoryIconLeftPadding],[#s_CategoryIconTopPadding],0,[#s_VariablePadding]
AccurateText=1
AntiAlias=1

[CategoryTitle]
FontFace=#s_FontFace#
AccurateText=1
AntiAlias=1
FontWeight=#s_TitleFontWeight#
FontSize=#s_FontSize1#
Padding=0,[#s_CategoryTitleTopPadding],0,[#s_VariablePadding]
Y=0r
DynamicVariables=1

;Variable styles

[VarTitle]
FontFace=#s_FontFace#
AccurateText=1
AntiAlias=1
FontSize=#s_FontSize2#
FontWeight=#s_TitleFontWeight#
Padding=[#s_VariableLeftPadding],[#s_VariablePadding],[#s_VariablePadding],[#s_VariablePadding]
Y=0R

[VarDescription]
FontFace=#s_FontFace#
AccurateText=1
AntiAlias=1
FontSize=#s_FontSize4#
Padding=[#s_VariableLeftPadding],0,[#s_VariablePadding],0
Y=(-[#s_VariablePadding])R

[VarStringValue]
FontFace=#s_FontFace#
AccurateText=1
AntiAlias=1
FontSize=#s_FontSize3#
Padding=[#s_VariableLeftPadding],[#s_VariablePadding],[#s_VariablePadding],[#s_VariablePadding]
Y=0R

[VarColorValue]
Padding=[#s_VariableLeftPadding],[#s_VariablePadding],[#s_VariablePadding],[#s_VariablePadding]
Y=0R

[IncludeCategoryList]
@IncludeCategoryList=#ROOTCONFIGPATH#settings\categories\CategoryList.inc

[IncludeCurrentCategory]
@IncludeCategory=#ROOTCONFIGPATH#settings\categories\[#s_CurrentCategory].inc
