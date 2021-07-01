[genLeftPanel]
Meter=Shape
Shape=Rectangle 0,0,([#s_GeneratorLeftPanelWidth] + [#s_BackgroundRounding]),[#s_GeneratorPanelHeight],[#s_BackgroundRounding] | Fill Color [#s_LeftPanelBackgroundColor] | StrokeWidth 0

[genRightPanel]
Meter=Shape
Shape=Rectangle [#s_GeneratorLeftPanelWidth],0,[#s_GeneratorRightPanelWidth],[#s_GeneratorPanelHeight],[#s_BackgroundRounding] | Fill Color [#s_RightPanelBackgroundColor] | StrokeWidth 0

[genRightPanelFixer]
Meter=Shape
Shape=Rectangle [#s_GeneratorLeftPanelWidth],0,[#s_BackgroundRounding],[#s_GeneratorPanelHeight] | Fill Color [#s_RightPanelBackgroundColor] | StrokeWidth 0
