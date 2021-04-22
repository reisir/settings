[Variables]

;@About | Name Internal settings | Description Changing internal variables requires generating to apply changes.
;?Integer | Description This controls the default category.
s_CurrentCategory=0
;?Integer |
s_ScrollSpeed=30
;?Integer | | Description Current scroll amount of the right panel
s_ScrollRightPanel=0
;?Integer | Description Current scroll amount of the left panel
s_ScrollLeftPanel=0
;?Integer |
s_LeftPanelW=200
;?Integer |
s_RightPanelW=600
;?Integer |
s_PanelH=700
s_ScrollTreshold=[#s_PanelH]

;@Topic | Name Customization

;@ | Name Background 
;?Color | 
s_RightPanelBackgroundColor=255,255,255,255
;?Color | 
s_LeftPanelBackgroundColor=200,200,200,255
;?Integer |
s_BackgroundRounding=5

;@ | Name Font
;? | 
s_FontFace=Segoe UI
;? | 
s_IconFontFace=Segoe MDL2 Assets
;?Color | 
s_FontColor=0,0,0
;?Integer |
s_FontSize1=20
;?Integer |
s_FontSize2=16
;?Integer |
s_FontSize3=12
;?Integer |
s_FontSize4=10
;?Integer |
s_FontSize5=8
;?Integer |
s_FontWeight=400
;?Integer |
s_SelectedFontWeight=500

;@ | Name Scroll indicator
;?Integer | Description uses s_ValueYPadding
s_scrollIndicatorYPadding=[#s_ValueYPadding]
s_ScrollIndicatorMaxHeight=([#s_PanelH] - ([#s_scrollIndicatorYPadding] * 2))
;?Integer |
s_ScrollIndicatorWidth=5
;?Integer |
s_scrollIndicatorXPadding=5
;?Color | 
s_ScrollIndicatorBackgroundColor=0,0,0,100
;?Color | 
s_ScrollIndicatorColor=200,200,200
;?Integer |
s_ScrollIndicatorRounding=5
;?Info | Name Filler variable 0 | Description This is here to show the scroll indicator
 = 
;?Info | Name Filler variable 1 | Description This is here to show the scroll indicator
 = 
;?Info | Name Filler variable 2 | Description This is here to show the scroll indicator
 = 
;?Info | Name Filler variable 3 | Description This is here to show the scroll indicator
 = 
;?Info | Name Filler variable 4 | Description This is here to show the scroll indicator
 = 
;?Info | Name Filler variable 5 | Description This is here to show the scroll indicator
 = 

;@Topic | Name Categories
;@ | Name Category
;? | Description Visually center the category icon. Uses s_CategoryTitleTopPadding
s_CategoryIconTopPadding=([#s_CategoryTitleTopPadding] + 5)
;? | Description Fix the literal 1px offset caused by the title and description using different font sizes
s_VarTitleNudge=-1
;?Integer |
s_CategoryTitleTopPadding=35
;?Integer |
s_CategoryTitleBottomPadding=20
;?Integer |
s_CategoryTitleXPadding=20
;?Integer |
s_CategoryTitleFontWeight=500
;?Integer |
s_CategoryDescriptionFontWeight=500
;@ | Name Category list
;?Integer |
s_ListAboutTopPadding=35
;?Integer |
s_ListAboutLeftPadding=8
;?Integer |
s_ListDefaultLeftPadding=20
;?Integer |
s_ListTopicLeftPadding=10
;?Integer |
s_ListYPadding=7
;? | Description Used for width calculations & ClipString=2
s_ListRightPadding=10
;?Info | Name s_SettingsIconPadding | Description The padding of the Settings icon in the bottom left. Set to -100 to move the icon outside of the skin.
5=https://www.youtube.com/watch?v=dQw4w9WgXcQ
s_CreditIconPadding=5


;@Topic | Name Variables
;@ | Name Variable
;?Integer |
s_VariableTitleFontWeight=400
;?Integer |
s_ValueYPadding=10
;?Integer |
s_VariableXPadding=20
;? | Description Uses s_FontSize3
s_InputTextFontSize=[#s_FontSize3]

;@ | Name Color
;?Integer |
s_ColorSize=15
;?Integer |
s_ColorStrokeWidth=1
;?Integer |
s_ColorStrokeWidthSelected=2
;?Color | 
s_ColorStrokeColor=200,200,200
;?Integer |
s_ColorStringLeftPadding=10

;@ | Name Toggle
;?Color | Description Uses s_SelectedColor
s_ToggleActiveColor=[#s_SelectedColor]
;?Color | Description Uses s_RightPanelBackgroundColor
s_ToggleInactiveColor=[#s_RightPanelBackgroundColor]
;?Integer |
s_ToggleSize=20
;?Integer |
s_TogglePadding=2.5
;?Integer |
s_ToggleLength=25

;@ | Name Selector
;?Integer |
s_SelectorPadding=8
;?Integer |
s_SelectorWidth=3
;?Integer | Description Uses s_SelectorWidth
s_SelectorRounding=[#s_SelectorWidth]
;?Integer |
s_SelectedColor=007acc

;@Topic | Name Developer
;@ | Name Generator
;? | 
s_GeneratorRightPanelWidth=350
;? | 
s_GeneratorLeftPanelWidth=50
;? | 
s_GeneratorPanelHeight=300

; Apparently the script doesn't break when there's more than one variable under one declaration
;@ | Name Debug colors
;?Toggle | 
s_DebugColors=0
;?Color | 
s_DebugCategoryTitleColor1=255,0,195,100
s_DebugCategoryTitleColor0=0,0,0,0
;?Color | 
s_DebugValueColor1=170,0,255,100
s_DebugValueColor0=0,0,0,0
;?Color | 
s_DebugDescriptionColor1=0,238,255,100
s_DebugDescriptionColor0=0,0,0,0
;?Color | 
s_DebugListColor1=0,255,51,100
s_DebugListColor0=0,0,0,0
;?Color | 
s_DebugListIconColor1=255,255,0,100
s_DebugListIconColor0=0,0,0,0
;?Color | 
s_DebugSeparatorColor1=51,46,46,100
s_DebugSeparatorColor0=0,0,0,0
;?Color | 
s_DebugVariableTitleColor1=255,0,0,100
s_DebugVariableTitleColor0=0,0,0,0
;?Color | 
s_DebugCategoryIconColor1=229,255,0,100
s_DebugCategoryIconColor0=0,0,0,0
;?Color | 
s_DebugToggleColor1=255,0,0,100
s_DebugToggleColor0=0,0,0,0
;?Color | 
s_DebugColorColor1=255,0,0,100
s_DebugColorColor0=0,0,0,0
