[Variables]

;! | SkinName Internal Settings | SkinDirectory Internal | Title Internal Settings
s_OnChangeAction=[!Log "Internal Variables Changed"][!CommandMeasure Paths """Paths "#s_CurrentFile#" 1""" #ROOTCONFIG#]

;@About | Name Internal settings | Description Changing internal variables requires generating to apply changes. | Icon [\xF259]
;?Integer | Name Scroll speed | Description | Font Impact
s_ScrollSpeed=30
;? | Name Theme 2 name | Font Alibi
s_Theme1Name=Dark

;@Topic | Name Internal | 
;? | Name hidden | Hidden 1
s_ScrollTreshold=[#s_PanelH]
s_SettingsTheme=1
s_SaveScroll=[!WriteKeyValue Variables s_ScrollLeft [#*s_ScrollLeft*] "[#s_CurrentFile]"][!WriteKeyValue Variables s_ScrollRight [#*s_ScrollRight*] "[#s_CurrentFile]"]
s_SaveLeftScroll=[!WriteKeyValue Variables s_ScrollLeft [#*s_ScrollLeft*] "[#s_CurrentFile]"][!WriteKeyValue Variables s_ScrollRight 0 "[#s_CurrentFile]"]

;@ | Name Test | Icon [\xE9F5] | Description Test variables for theme editing
;? | Name Long Description | Description My description is so long that it should hopefully force this string meter to clipstring=2 and break to multiple lines thanks.
longdesc=value
;? | Name Long Value
longvalue=This value is so long that it should hopefully force this string meter to clipstring=2 and break to multiple lines thanks.
;? | Name akjkja
asjbdkjasbd=92892892

;@ | Name Generator
;? | 
s_GeneratorRightPanelWidth=350
;? | 
s_GeneratorLeftPanelWidth=50
;? | 
s_GeneratorPanelHeight=300
s_GenTopHeight=20

;@ | Name Debug colors | Icon [\xE783]
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
;?Toggle | Name Debug colors | Description Toggle debug colors on/off
s_DebugColors=0
;?Color | 
s_DebugListIconColor1=255,255,0,100
s_DebugListIconColor0=0,0,0,0
;?Color | 
s_DebugSeparatorColor1=51,255,46,100
s_DebugSeparatorColor0=0,0,0,0
;?Color | 
s_DebugVariableTitleColor1=255,0,0,100
s_DebugVariableTitleColor0=0,0,0,0
;?Color | 
s_DebugCategoryIconColor1=229,255,0,100
s_DebugCategoryIconColor0=0,0,0,0
;?Color | 
s_DebugVarIconColor1=229,255,0,100
s_DebugVarIconColor0=0,0,0,0
;?Color | 
s_DebugToggleColor1=255,0,0,100
s_DebugToggleColor0=0,0,0,1
;?Color | 
s_DebugColorColor1=255,0,0,100
s_DebugColorColor0=0,0,0,0
s_CurrentCategory=4
s_ScrollLeft=0
s_ScrollRight=0
