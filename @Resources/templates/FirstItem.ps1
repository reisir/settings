param (
    [Parameter()]
    [String]
    $Side
)

$ini = @"
[First$($Side)]
Meter=Image
MeterStyle=FirstItem | First$($Side)Panel
Y=([#s_Scroll$($Side)] + [#s_TopHeight])
SolidColor=0,0,0,0
W=0
H=0


"@

return $ini