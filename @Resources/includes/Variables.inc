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
s_CategoryTitleXPadding=20
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
s_ColorStrokeWidth=1
s_ColorStrokeColor=200,200,200
s_ColorStringLeftPadding=10

; Category list
s_ListAboutTopPadding=35
s_ListAboutLeftPadding=8
s_ListDefaultLeftPadding=20
s_ListTopicLeftPadding=10

s_ListYPadding=7
; Used for width calculations ClipString=2
s_ListRightPadding=10


; Background 
s_RightPanelBackgroundColor=255,255,255,255
s_LeftPanelBackgroundColor=200,200,200,255
s_BackgroundRounding=5
s_LeftPanelW=200
s_RightPanelW=600
s_PanelH=700

; Scroll indicator
s_ScrollIndicatorWidth=5
s_scrollIndicatorYPadding=[#s_ValueYPadding]
s_scrollIndicatorXPadding=5
s_ScrollIndicatorMaxHeight=([#s_PanelH] - ([#s_scrollIndicatorYPadding] * 2))
s_ScrollIndicatorBackgroundColor=0,0,0,100
s_ScrollIndicatorColor=200,200,200
s_ScrollIndicatorRounding=5

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
s_ScrollTreshold=([#s_PanelH] - ([#s_PanelH] / 4))
