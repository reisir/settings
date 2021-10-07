[VarString]
AntiAlias=1
FontColor=[#s_FontColor]
FontFace=[#s_FontFace]
FontSize=[#s_VarTextSize]
ClipString=2
Padding=[#s_VariableXPadding],[#s_VariableYPadding],[#s_VariableXPadding],[#s_VariableYPadding]
ClipStringW=([#s_RightPanelW] - [#s_VariableXPadding] * 2)
SolidColor=[#s_DebugValueColor[#s_DebugColors]] 
MouseOverAction=[!SetOption #CURRENTSECTION# FontColor [#s_SelectedColor]][!SetOption #CURRENTSECTION# FontWeight [#s_SelectedFontWeight]][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# FontColor [#s_FontColor]][!SetOption #CURRENTSECTION# FontWeight [#s_FontWeight]][!UpdateMeter #CURRENTSECTION#][!Redraw]

