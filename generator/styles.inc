[Center]
StringAlign=Center
X=([#s_GeneratorRightPanelWidth] / 2)
DynamicVariables=1

[Left]
StringAlign=Left
X=[#s_VariableYPadding]
DynamicVariables=1

[FirstRightPanel]
X=[#s_GeneratorLeftPanelWidth]

[FirstLeftPanel]
X=0

[LeftPanel]
X=[FirstLeft:X]
DynamicVariables=1
Y=0R

[RightPanel]
X=[FirstRight:X]
DynamicVariables=1
Y=0R

[Right]
StringAlign=Left
X=([#s_GeneratorRightPanelWidth] - [#s_VariableYPadding] - [[#CURRENTSECTION]:W])
DynamicVariables=1
Y=0r

[TextOptions]
AntiAlias=1
FontFace=[#s_FontFace]
FontSize=[#s_FontSize3]
Y=0R


