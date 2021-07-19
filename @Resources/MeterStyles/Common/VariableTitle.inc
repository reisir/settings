[VarIcon]
AntiAlias=1
Y=0R
X=0R
FontSize=[#s_VarTitleSize]
FontWeight=[#s_VariableTitleFontWeight]
SolidColor=[#s_DebugVarIconColor[#s_DebugColors]] 
FontColor=[#s_FontColor]

[VarTitle]
AntiAlias=1
Y=0r
X=0R
ClipString=2
FontFace=[#s_FontFace]
FontSize=[#s_VarTitleSize]
FontWeight=[#s_VariableTitleFontWeight]
SolidColor=[#s_DebugVariableTitleColor[#s_DebugColors]] 
FontColor=[#s_FontColor]

[VarDescription]
AntiAlias=1
ClipString=2
FontFace=[#s_FontFace]
FontSize=[#s_VarDescriptionSize]
SolidColor=[#s_DebugDescriptionColor[#s_DebugColors]] 
FontColor=[#s_FontColor]
;TODO: change this to variable description padding
Padding=[#s_VariableXPadding],0,[#s_VariableXPadding],0
W=([#s_RightPanelW] - [#s_VariableXPadding] * 2)

