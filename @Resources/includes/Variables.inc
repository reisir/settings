[Variables]
; Font
s_FontFace=Segoe UI
s_IconFontFace=Segoe MDL2 Assets
s_FontColor=0,0,0
s_FontSize5=8
s_FontSize4=10
s_FontSize3=12
s_FontSize2=16
s_FontSize1=20
s_TitleFontWeight=400
s_SelectedFontWeight=500
s_FontWeight=400

; Items
s_ValueYPadding=10
s_VariableXPadding=20

; Titles
s_CategoryTitleTopPadding=35
s_CategoryTitleBottomPadding=20
s_CategoryTitleLeftPadding=20
; Visually center the Icon 
s_CategoryIconTopPadding=([#s_CategoryTitleTopPadding] + 5)
; Fix the literal 1px offset caused by the title and description using different font sizes
s_VarTitleNudge=-1

; Toggle
s_ToggleActiveColor=[#s_SelectedColor]
s_ToggleInactiveColor=[#s_RightPanelBackgroundColor]
s_ToggleSize=20
s_TogglePadding=2.5
s_ToggleLength=25

; Selector
s_SelectorPadding=8
s_SelectorWidth=3
s_SelectorRounding=[#s_SelectorWidth]
s_SelectedColor=007acc

; Color variables
s_ColorSize=15
s_ColorStrokeWidth=0
s_ColorStrokeColor=[#s_FontColor]
s_ColorStringLeftPadding=10

; Category list
s_ListIconLeftPadding=20
s_ListItemPadding=5
s_ListItemLeftPadding=10
s_ListItemTopPadding=7
s_ListIconTopPadding=10

; Background 
s_RightPanelBackgroundColor=255,255,255,255
s_LeftPanelBackgroundColor=200,200,200,255
s_BackgroundRounding=5
s_LeftPanelW=200
s_RightPanelW=600
s_PanelH=700

; Generator
s_GeneratorRightPanelWidth=350
s_GeneratorLeftPanelWidth=50
s_GeneratorPanelHeight=300

; Internal
s_CurrentCategory=0
s_ScrollSpeed=10
s_ScrollRightPanel=0
s_ScrollLeftPanel=0
s_InputTextFontSize=[#s_FontSize3]