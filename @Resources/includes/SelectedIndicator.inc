[CategoryListSelectedIndicator]
Meter=Shape
Shape=Rectangle 0,[#s_SelectorPadding],([#s_SelectorWidth] * 2),([ListItem[#s_CurrentCategory]:H] - ([#s_SelectorPadding] * 2)),[#s_SelectorRounding] | Extend Line, Square
Line=StrokeWidth 0
Square=Fill Color [#s_SelectedColor]
X=(-[#s_SelectorWidth])
Y=([ListItem[#s_CurrentCategory]:Y])
DynamicVariables=1

