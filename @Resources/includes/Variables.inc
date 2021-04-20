[Variables]
; Scroll indicator very internal variables
s_ScrollIndicatorMaxHeight=([#s_PanelH] - ([#s_scrollIndicatorYPadding] * 2))
s_scrollIndicatorYPadding=[#s_ValueYPadding]
; Generator
s_GeneratorRightPanelWidth=350
s_GeneratorLeftPanelWidth=50
s_GeneratorPanelHeight=300

;@About | Name Internal settings | Description You better know what you're doing.
;?Info | Name Disclaimer | Description The RainDoc syntax will not change but this internal variables file is bound to change, frequently.

;@Default | Name Font
;? | 
s_FontFace=Segoe UI
;? | 
s_IconFontFace=Segoe MDL2 Assets
;? | 
s_FontColor=0,0,0
;? | 
s_FontSize5=8
;? | 
s_FontSize4=10
;? | 
s_FontSize3=12
;? | 
s_FontSize2=16
;? | 
s_FontSize1=20
;? | 
s_SelectedFontWeight=500
;? | 
s_FontWeight=400

;@ | Name Items
;? | 
s_ValueYPadding=10
;? | 
s_VariableXPadding=20

;@ | Name Category
;? |
s_CategoryTitleTopPadding=35
;? |
s_CategoryTitleBottomPadding=20
;? |
s_CategoryTitleXPadding=20
;? | Description Visually center the category icon
s_CategoryIconTopPadding=([#s_CategoryTitleTopPadding] + 5)
;? | Description Fix the literal 1px offset caused by the title and description using different font sizes
s_VarTitleNudge=-1
;? |
s_CategoryTitleFontWeight=500
;? |
s_CategoryDescriptionFontWeight=500
;? | 
s_VariableTitleFontWeight=[#s_FontWeight]

;@ | Name Toggle
;? |
s_ToggleActiveColor=[#s_SelectedColor]
;? |
s_ToggleInactiveColor=[#s_RightPanelBackgroundColor]
;? |
s_ToggleSize=20
;? |
s_TogglePadding=2.5
;? |
s_ToggleLength=25

;@ | Name Selector
;? |
s_SelectorPadding=8
;? |
s_SelectorWidth=3
;? |
s_SelectorRounding=[#s_SelectorWidth]
;? |
s_SelectedColor=007acc

;@ | Name Color
;? |
s_ColorSize=15
;? |
s_ColorStrokeWidth=1
;? |
s_ColorStrokeWidthSelected=2
;? |
s_ColorStrokeColor=200,200,200
;? |
s_ColorStringLeftPadding=10

;@ | Name Category list
;? |
s_ListAboutTopPadding=35
;? |
s_ListAboutLeftPadding=8
;? |
s_ListDefaultLeftPadding=20
;? |
s_ListTopicLeftPadding=10
;? |
s_ListYPadding=7
;? | Description Used for width calculations ClipString=2
s_ListRightPadding=10


;@ | Name Background 
;? |
s_RightPanelBackgroundColor=255,255,255,255
;? |
s_LeftPanelBackgroundColor=200,200,200,255
;? |
s_BackgroundRounding=5
;? |
s_LeftPanelW=200
;? |
s_RightPanelW=600
;? |
s_PanelH=700

;@ | Name Scroll indicator
;? |
s_ScrollIndicatorWidth=5
;? |
s_scrollIndicatorXPadding=5
;? |
s_ScrollIndicatorBackgroundColor=0,0,0,100
;? |
s_ScrollIndicatorColor=200,200,200
;? |
s_ScrollIndicatorRounding=5


; Internal
;? |
s_CurrentCategory=0
;? |
s_ScrollSpeed=10
;? |
s_ScrollRightPanel=0
;? |
s_ScrollLeftPanel=0
;? |
s_InputTextFontSize=[#s_FontSize3]
;? |
s_ScrollTreshold=([#s_PanelH] - ([#s_PanelH] / 4))

;@ | Name Debug colors
s_DebugColors=0
;? |
s_DebugTitleColor1=255,0,0,100
;? |
s_DebugValueColor1=,0,0,100
;? |
s_DebugDescriptionColor1=255,0,0,100
;? |
s_DebugListColor1=255,0,0,100
;? |
s_DebugIconColor1=255,0,0,100

