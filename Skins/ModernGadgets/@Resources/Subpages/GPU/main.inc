; MODERNGADGETS GPU METER MAIN SUBPAGE
; What GPU meter will usually contain
;

; ----- HWiNFO Detection -----

[MeasureHwinfoDetect]
Measure=String
String=[MeasureGpu0Name]
IfMatch=HWI_ERROR_NOT_CONNECTED
IfMatchAction=[!WriteKeyValue Variables page "nohwinfo"][!Refresh]
DynamicVariables=1

; ----- GPU Name, Core Usage, Temperature, Clock Speed -----

[Gpu0NameString]
Meter=String
MeterStyle=StyleString | StyleStringCenterAlign
MeasureName=MeasureGpu0DisplayName
Text="%1"

[Gpu0ClockString]
Meter=String
MeterStyle=StyleString
MeasureName=MeasureGpu0ClockSpeed
Text="Clock: %1MHz"

[Gpu0TempString]
Meter=String
MeterStyle=StyleString | StyleStringRightAlign
MeasureName=MeasureGpu0Temperature
Text="%1�#tempUOM#"

[Gpu0CoreUsageLabelString]
Meter=String
MeterStyle=StyleString
Text="Usage:"

[Gpu0CoreUsageValueString]
Meter=String
MeterStyle=StyleString | StyleStringRightAlign
MeasureName=MeasureGpu0Usage
Text="%1%"

[Gpu0CoreUsageBar]
Meter=Bar
MeterStyle=StyleBar
MeasureName=MeasureGpu0Usage
BarColor=#colorCoreUsage#
DynamicVariables=1

; ----- Memory -----

[Gpu0MemoryClockLabelString]
Meter=String
MeterStyle=StyleString
Text="Memory Clock:"
Group=MemoryClock
Hidden=0
Y=#rowSpacing#R

[Gpu0MemoryClockValueString]
Meter=String
MeterStyle=StyleString | StyleStringRightAlign
MeasureName=MeasureGpu0MemoryClockSpeed
Text="%1MHz"
Group=MemoryClock
Hidden=0

[Gpu0MemoryUsageLabelString]
Meter=String
MeterStyle=StyleString
Text="Usage:"

[Gpu0MemoryUsageFractionString]
Meter=String
MeterStyle=StyleString | StyleStringInfo
Text="#textMemoryUsedGpu0#B / #textMemoryTotalGpu0#B"
DynamicVariables=1

[Gpu0MemoryUsageValueString]
Meter=String
MeterStyle=StyleString | StyleStringRightAlign
MeasureName=MeasureGpu0MemUsedPercent
Text="%1%"

[Gpu0MemoryUsageBar]
Meter=Bar
MeterStyle=StyleBar
MeasureName=MeasureGpu0MemUsedPercent
BarColor=#colorMemoryUsage#
DynamicVariables=1

; ----- Fan -----

[Gpu0FanUsageLabelString]
Meter=String
MeterStyle=StyleString
Text="Fan:"

[Gpu0FanSpeedString]
Meter=String
MeterStyle=StyleString | StyleStringInfo
MeasureName=MeasureGpu0FanSpeed
Text="%1RPM"

[Gpu0FanUsageValueString]
Meter=String
MeterStyle=StyleString | StyleStringRightAlign
MeasureName=MeasureGpu0FanUsage
Text="%1%"

[Gpu0FanUsageBar]
Meter=Bar
MeterStyle=StyleBar
MeasureName=MeasureGpu0FanUsage
BarColor=#colorFanUsage#
DynamicVariables=1

; ----- Memory Controller -----

[Gpu0MemoryControllerLabelString]
Meter=String
MeterStyle=StyleString
Text="Memory Controller:"
Group=MemoryController
Hidden=0
Y=#rowSpacing#R

[Gpu0MemoryControllerValueString]
Meter=String
MeterStyle=StyleString | StyleStringRightAlign
MeasureName=MeasureGpu0MemoryControllerLoad
Text="%1%"
Group=MemoryController
Hidden=0

[Gpu0MemoryControllerBar]
Meter=Bar
MeterStyle=StyleBar
MeasureName=MeasureGpu0MemoryControllerLoad
BarColor=#colorMemoryController#
DynamicVariables=1
Group=MemoryController
Hidden=0

; ----- Video Clock -----

[Gpu0VideoClockLabelString]
Meter=String
MeterStyle=StyleString
Text="Video Clock:"
Group=VideoClock
Hidden=0
Y=#rowSpacing#R

[Gpu0VideoClockValueString]
Meter=String
MeterStyle=StyleString | StyleStringRightAlign
MeasureName=MeasureGpu0VideoClock
Text="%1MHz"
Group=VideoClock
Hidden=0

; ----- Core Voltage -----

[Gpu0CoreVoltageLabelString]
Meter=String
MeterStyle=StyleString
Text="Core Voltage:"
Group=CoreVoltage
Hidden=0
Y=#rowSpacing#R

[Gpu0CoreVoltageValueString]
Meter=String
MeterStyle=StyleString | StyleStringRightAlign
MeasureName=MeasureGpu0CoreVoltage
NumOfDecimals=3
Text="%1V"
Group=CoreVoltage
Hidden=0

; ----- Graph -----

[GraphLines]
Meter=Line
X=(#contentMargin# + 1)
Y=R
W=(#contentWidth# - 3)
H=(#graphHeight# - 1)
LineCount=4
MeasureName=MeasureGpu0MemoryControllerLoad
MeasureName2=MeasureGpu0FanUsage
MeasureName3=MeasureGpu0MemUsedPercent
MeasureName4=MeasureGpu0Usage
LineColor=#colorMemoryController#
LineColor2=#colorFanUsage#
LineColor3=#colorMemoryUsage#
LineColor4=#colorCoreUsage#
DynamicVariables=1
Antialias=#lineGraphAa#
Group=LineGraph
Hidden=0

[GraphBorder]
Meter=Image
ImageName=#imgPath#GraphBorder.png
ScaleMargins=2,2,2,2
ImageTint=#colorGraphBorder#
X=r
Y=r
W=(#contentWidth# - 2)
H=#graphHeight#
Group=LineGraph
Hidden=0