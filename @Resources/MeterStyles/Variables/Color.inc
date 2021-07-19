[VarColor]
X=[#s_VariableXPadding]
Y=1R
SolidColor=[#s_DebugColorColor[#s_DebugColors]] 
MouseOverAction=[!SetOption #CURRENTSECTION# "Outline" "Stroke Color [#s_SelectedColor]"][!SetVariable s_ColorStrokeWidth [#s_ColorStrokeWidthSelected]][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# "Outline" "Stroke Color [#s_ColorStrokeColor]"][!SetVariable s_ColorStrokeWidth [#s_ColorStrokeWidthDefault]][!UpdateMeter #CURRENTSECTION#][!Redraw]

[VarColorString]
Y=0r
X=[#s_VariableXPadding]R
FontColor=[#s_FontColor]
Padding=0,([#s_ColorSize] - [#s_VarTextSize]),0,(([#s_ColorSize] - [#s_VarTextSize]) + [#s_VariableYPadding])
SolidColor=[#s_DebugColorColor[#s_DebugColors]] 

