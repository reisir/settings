[VarTitle]
AccurateText=1
AntiAlias=1
Y=0r
X=0R
ClipString=2
FontFace=[#s_FontFace]
FontSize=[#s_FontSize2]
FontWeight=[#s_VariableTitleFontWeight]
InlineSetting=CharacterSpacing | [#s_TitleIconNudge] | *
InlinePattern=^.
SolidColor=[#s_DebugVariableTitleColor[#s_DebugColors]] 
FontColor=[#s_FontColor]
Padding=[#s_VariableXPadding],[#s_VariableYPadding],[#s_VariableXPadding],[#s_VariableYPadding]
W=([#s_RightPanelW] - [#s_VariableXPadding] * 2)

[VarDescription]
AccurateText=1
AntiAlias=1
ClipString=2
FontFace=[#s_FontFace]
FontSize=[#s_FontSize4]
SolidColor=[#s_DebugDescriptionColor[#s_DebugColors]] 
FontColor=[#s_FontColor]
;TODO: change this to variable description padding
Padding=[#s_VariableXPadding],0,[#s_VariableXPadding],0
W=([#s_RightPanelW] - [#s_VariableXPadding] * 2)

