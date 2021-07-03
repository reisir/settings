param (
    [Parameter()]
    [String]
    $Side
)

$ini = @"
[First$($Side)]
Meter=String
Text=First
FontColor=0,0,0,0
MeterStyle=FirstItem | First$($Side)Panel
Y=[#s_Scroll$($Side)]


"@

return $ini