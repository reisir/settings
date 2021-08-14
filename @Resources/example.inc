[Variables]
;@About | Name About | Description an example settings skin generated from example.inc | Icon [\xE897]
;?Action | Name Disclaimer | Link 0
These variables don't actually control anything=https://google.com
;?Action | Name Generate your own Settings skin: | Link 1
Settings wiki=https://github.com/sceleri/settings/wiki
;?Action | Name Open the example file | Link 2
example.inc=#@#example.inc

; death.crafter tests

;?Slider | Name SliderTest | Width 400 | MinValue -20 | MaxValue 50 | Precision 1 | Scroll 1,1,0 | Precision 1
sliderVar=32

;?List | Name List Test | Options Use bold, boldBool; Use Italic, italicBool ; Underline
boldBool=1
italicBool=1
Underline=0

;?Radio | Name RadioTest | Options Managing Director, LevelO; Manager, LevelA ; Supervisor, LevelB ; Employee, LevelC
DesignationLevel=LevelB


;@Topic | Name Personalization | Icon [\xE771]
;@ | Name Font | Icon [\xE986]
;?String | Name Font face | Description The font used throughout the skin
FontFace=Segoe UI
;?Color | Name Font color | Description Colour of all text elements
FontColor=43,43,43
;?String | Name Font size | Description The size of all text elements
FontSize=12

;@Topic | Name Skin settings
;@ | Name Sizing | Icon [\xE740]
;?Integer | Name Height
SkinHeight=300
;?Integer | Name Width
SkinWidth=400
;@ | Name Miscellanious | Icon [\xE736]
;?Toggle | Name Enable automatic sizing
autosize=1

s_CurrentCategory=0
s_ScrollLeft=-90
s_ScrollRight=0
