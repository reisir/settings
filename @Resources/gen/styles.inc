[Center]
StringAlign=Center
X=([#s_GeneratorRightPanelWidth] / 2)
DynamicVariables=1

[Left]
StringAlign=Left
X=[#s_ValueYPadding]
DynamicVariables=1

[GenLeft]
Container=genLeftContainer
[GenRight]
Container=genRightContainer

[Right]
StringAlign=Left
X=([#s_GeneratorRightPanelWidth] - [#s_ValueYPadding] - [[#CURRENTSECTION]:W])
DynamicVariables=1
Y=0r

[TextOptions]
AntiAlias=1
AccurateText=1
FontFace=[#s_FontFace]
FontSize=[#s_FontSize3]
Y=0R


