[genSelectedIndicator]
Meter=Shape
Shape=Rectangle 0,[#s_SelectorPadding],([#s_SelectorWidth] * 2),(([GeneratorIcon0:H] + ([#s_GeneratorLeftPanelWidth] - [GeneratorIcon0:W])) - [#s_SelectorPadding] * 2),[#s_SelectorRounding] | Extend Line, Square
Line=StrokeWidth 0
Square=Fill Color [#s_SelectedColor]
X=(-[#s_SelectorWidth])
Y=((([#s_GeneratorLeftPanelWidth] - [GeneratorIcon0:W]) / 2) + (([GeneratorIcon0:H] + ([#s_GeneratorLeftPanelWidth] - [GeneratorIcon0:W])) * [#s_GenCurrentCategory]))
DynamicVariables=1
MeterStyle=LeftPanel

[GeneratorIcon0]
Meter=String
Text=[\xE897]
MeterStyle=CategoryIcon | LeftPanel | Center
Padding=0,0,0,0
X=([#s_GeneratorLeftPanelWidth] / 2)
Y=(([#s_GeneratorLeftPanelWidth] - [GeneratorIcon0:W]))
DynamicVariables=1
LeftMouseUpAction=[!WriteKeyValue Variables "s_GenCurrentCategory" 0][!Refresh]
ToolTipText=Instructions

[GeneratorIcon1]
Meter=String
Text=[\xF259]
MeterStyle=CategoryIcon | LeftPanel | Center
Padding=0,0,0,0
X=([#s_GeneratorLeftPanelWidth] / 2)
Y=(([#s_GeneratorLeftPanelWidth] - [GeneratorIcon0:W]))R
DynamicVariables=1
LeftMouseUpAction=[!WriteKeyValue Variables "s_GenCurrentCategory" 1][!Refresh]
ToolTipText=Generate

