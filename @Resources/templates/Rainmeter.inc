[Rainmeter]
Update=-1
DefaultUpdateDivider=-1

[Variables]
s_FontFace=Segoe UI
s_IconFontFace=Segoe UI
s_FontColor=0,0,0

s_FontSize5 = 8
s_FontSize4 = 10
s_FontSize3 = 12
s_FontSize2 = 16
s_FontSize1 = 20

s_LeftPanelW = 200
s_RightPanelW = 600
s_PanelH = 700

s_SideBarItemPadding = 10
s_VariableItemPadding = 10
s_CategoryTopPadding = 40

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

[CategoryListItem]
Y=0R
FontSize=#s_FontSize3#
FontFace=#s_FontFace#
AccurateText=1
AntiAlias=1

[CategoryListSuperItem]
Y=0R
FontSize=#s_FontSize4#
FontFace=#s_FontFace#
AccurateText=1
AntiAlias=1

[CategoryTitle]
FontFace=#s_FontFace#
AccurateText=1
AntiAlias=1
FontWeight=#s_TitleFontWeight#
FontSize=#s_FontSize1#
Padding=[#s_VariableItemPadding],[#s_CategoryTopPadding],[#s_VariableItemPadding],[#s_VariableItemPadding]
Y=0R

[VarTitle]
FontFace=#s_FontFace#
AccurateText=1
AntiAlias=1
FontSize=#s_FontSize2#
FontWeight=#s_TitleFontWeight#
Padding=[#s_VariableItemPadding],[#s_VariableItemPadding],[#s_VariableItemPadding],[#s_VariableItemPadding]
Y=0R

[VarDescription]
FontFace=#s_FontFace#
AccurateText=1
AntiAlias=1
FontSize=#s_FontSize4#
Padding=[#s_VariableItemPadding],0,[#s_VariableItemPadding],0
Y=(-[#s_VariableItemPadding])R

[VarStringValue]
FontFace=#s_FontFace#
AccurateText=1
AntiAlias=1
FontSize=#s_FontSize3#
Padding=[#s_VariableItemPadding],[#s_VariableItemPadding],[#s_VariableItemPadding],[#s_VariableItemPadding]
Y=0R

[VarColorValue]
Padding=[#s_VariableItemPadding],[#s_VariableItemPadding],[#s_VariableItemPadding],[#s_VariableItemPadding]
Y=0R

[IncludeCategoryList]
@IncludeCategoryList=#ROOTCONFIGPATH#settings\categories\CategoryList.inc

[IncludeCurrentCategory]
@IncludeCategory=#ROOTCONFIGPATH#settings\categories\[#s_CurrentCategory].inc
