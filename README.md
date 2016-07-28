# ARC-Sensor-Board

Sensor Board Arduino Sketch

Collaborators:<br>
lionspaws<br>
tomosfearn<br>

## Board Map

| Input | Output | State |
|:-----:|:------:|:-----:|
|Temperature and Humidity|No Output||
|Light Blocking|Buzzer A Arpeggio|Working|
|Reed Switch|RGB LED 1|Working|
|White Button|7 Colour Flash|Working|
|Ultrasound|SMD RGB LED|Working|
|IR Blocking|2 Colour LED 1|Working|
|Microphone|Tap for Buzzer B tone|Working|
|Rotary Encoder|Green LED: turn 0-255, press to turn on/off|Working|
|IR Tx and Rx|||
|Touch| RGB LED 2|NOT WORKING!|
|Radio Rx|2 Colour LED (heled)|Working|Working|
|LDR|modify the pulse rate of the green LED|TODO|
|Ball Switch|2 Colour LED 1 and RGB LED 2|Working|
|Mini Reed|Dragon Pulse|Working|
|Joystick|||
|Button|All the LEDs!|Working|

## Pin Map

Sensors are listed left to right, and split into row groups.

| Sensor | Variable | Pin |
|:------:|:--------:|:---:|
| Temp & Humidity | int temphumidity | 22|
| Light Blocking  | int lightBlockingPin | 29 |
| Passive Buzzer  | int buzzerAPin | 2 |
| RGB LED Red | int rgbLedRedPin | 49 |
| RGB LED Green | int rgbLedBluePin | 51 |
| RGB LED Blue | int rgbLedGreenPin | 53 |
| Reed Switch | int reedPin | 47 |
| 7 Colour Flash | int sevenColFlashPin | 39 |
|---|---|
| SMD LED Red | int smdRedPin | 5 |
| SMD LED Green | int smdGreenPin | 4 |
| SMD LED Blue | int smdBluePin | 3 |
| WhiteButton | int whiteButtonPin | 37 |
|---|---|
| Ultrasonic Trig | int ultrasonicTriggerPin | 34 |
| Ultrasonic Echo | int ultrasonicEchoPin | 36 |
| IR Blocking| int blockingPin | 27 |
| 2 Colour LED 1, Red | int rgLedRedPin | 28 |
| 2 Colour LED 1, Green | int rgLedGreenPin | 26 |
| Microphone Digital | int micPin | 31 |
| Microphone Analog | int analogMicPin | A4 |
| Active Buzzer | int buzzerBPin | 45 |
| Rotary Encoder, Switch | int rotaryEncoderSwitch | 38 |
| Rotary Encoder, Data | int rotaryEncoderData | 40 |
| Rotary Encoder, Clock | int rotaryEncoderCLK | 42 |
|---|---|
| IR Emitter | int infraRedTx | 30 |
| Touch | int touchPin | 25 |
| RGB LED 2 Green | int rgb2LedGreen | A5 |
| RGB LED 2 Red | int rgb2LedRed | 50 |
| RGB LED 2 Blue | int rgb2LedBlue | 48 |
| Radio B Button | int radio1Pin | 46 |
| Radio A Button | int radio0Pin | 44 |
| LDR | int ldrPin | A0 |
| Green LED | int greenLed | 6 |
|---|---|
| IR Receiver | int infraRedRx | 32 |
| Ball Switch | int tiltPin | 23 |
| Mini Reed | int miniReedPin | 24 |
| RC LED Cyan |int heledCyan | 43 |
| RC LED Red | int heledRed | 41 |
| Joystick, Button | int joyStickButtonPin | 33 |
| Joystick, Y | int joyStickY | A2 |
| Joystick, X | int joyStickX | A3 |
| Button | int buttonPin | 35 |

## Board Text

###Bwrdd Synhwyrydd / Sensor Board

Mae robotiaid yn defnyddio synhwyrydd i ddeall y byd o'u cwmpas. Mae'r bwrdd yma yn dangos gwahanol fathau o fewnbynnau ac allbynnau gallwch weld ar robotiaid.<br>
Robots use sensors to understand the world around them. This board shows some of the different kinds of input and output sensors you might find on robots.

Ceisiwch ddarganfod beth maent yn gwneud!<br>
Can you work out what they all do?

Mae synwyryddion mewnbynno (e.e. botymau, GADau) yn casglu gwahanol gyfryngau o ddata, o'r amgylchedd neu o ddefnyddwyr dynol.<br>
Input sensors (e.g. buttons, LDRs) take different kinds of data in, from the environment or from a human user.

Mae synwyryddion allbynno (e.e. DAGau, Swnyn) yn ffordd o dangos bod rhywbeth yn digwydd.<br>
Output sensors (e.g. LEDs, buzzers) are a way of showing that something is happening.

#####Temperature and Humidity / Tymheredd a Lleithder
Mae'r synhwyrydd yma yn mesur y tymheredd a lleithder yr aer o'i chwmpas.<br>
This is measuring the temperature and humidity of the air around it.

#####Atal Golau / Light Blocking
Mae golau is-goch (IG) yn teithio rhwng y bwlch, bydd y synhwyrydd yn canfod os ydych yn rhoi rhywbeth yn y bwlch i rwystro'r golau.<br>
Infrared (IR) light is travelling between the gap, the sensor will activate if you put something into the gap and block the light.

#####Swnyn Goddefol / Passive Buzzer
Mae'r swnyn yn creu sŵn gan y cerrynt a derbynnir, felly mae'n hawdd newid y tôn i ganu.<br>
This buzzer makes sound based on the current it receives, so we can change the tone easily to sing a song.

#####DAG CGG / RGB LED (x3)
Gall y Deuod Allyrru Golau (DAG) yma allyrru golau coch, gwyrdd, neu glas, a hyd yn oed cymysgiad o'r tri!<br>
This Light Emitting Diode (LED) can emit red, green, and blue light, or even a mix of all three!

#####Switsh Brwynen / Reed Switch
Pan fyddwch yn dal magnet yn agos i'r switsh brwynen, bydd y ddwy frwynen metal yn symud i gyffwrdd ac yn cau'r cylched.<br>
When you wave a magnet over the reed switch, the two metal reeds inside the glass tube will move to touch each other and close the circuit.

#####Fflach 7 Liw / 7 Colour Flash
Mae'r Deuod Allyrru Golau (DAG) yma dangos 7 liw gwahanol mewn trefn sefydlog.<br>
This Light Emitting Diode (LED) cycles through 7 different colours in a fixed order.

#####Cyffyrddiad Cynhwysaidd / Capacitive Touch
Achos mae croen yn dargludo trydan, os ydych yn cyffwrdd y cylch gyda'ch bys, byddech yn cyflawni'r cylched a chau'r switsh - dyma sut mae nifer o sgriniau cyffwrdd ar ffonau clyfar yn gweithio!<br>
Because our skin can conduct electricity, touching your finger on the circle will complete the circuit and close the switch - this is how many smartphone touchscreens work!

#####Uwchsain / Ultrasound
Mae un llygad yn danfon 'ping', tra mae'r un arall yn gwrando am yr atsain. Gallwn gyfrifo pellter y gwrthrych adlewyrchol trwy fesur yr amser cymerwyd i'r sŵn teithio allan ac yn ôl.<br>
One eye sends out a 'ping', while the other listens for the echo coming back. We can calculate the distance of the reflecting object by measuring the time taken for the sound to travel out and back.

#####Ataliad IG / IR Blocking
Mae gan y synhwyrydd ataliad is-goch (IG) allyrwyr a derbynnydd yn wynebu i fyny; os ydych yn atal y golau gyda'ch llaw, bydd y synhwyrydd yn canfod.<br>
This infrared (IR) blocking sensor has an IR emitter and receiver pointing upwards; if you block the light with your hand, it will activate the sensor.

#####DAG 2 liw / 2 Colour LED
Mae'r Deuod Allyrru Golau (DAG) yma yn goleuo yn wyrdd ac yn goch.<br>
This Light Emitting Diode (LED) can light up in green and red.

#####Microffon / Microphone
Mae microffon yn synhwyro sain, ceisiwch dapio fo!<br>
The microphone detects sound, try tapping it!

#####Swnyn Actif / Active Buzzer
Mae'r swnyn yma yn cynnwys osgiliadur i greu sŵn, felly gallwn ei droi ymlaen ac i ffwrdd fel switsh.<br>
This buzzer contains an oscillator to make sound, so we can turn it on and off like a switch.

#####Amgodwyr Cylchdro / Rotary Encoder
Gall yr amgodwyr cylchdro deall os yw'n cael ei droi yn glocwedd neu yn wrthglocwedd, a gallwch ei phwyso fel botwm.<br>
The rotary encoder can tell whether it is being turned clockwise or counter-clockwise, and can be pushed like a button.

#####Allyrwyr IG / IR Emitter
Mae'r Deuod Allyrru Golau (DAG) yma yn disgleirio golau is-goch (IG) sydd yn amhosib i'n llygaid weld.<br>
This Light Emitting Diode (LED) is shining infrared (IR) light which our eyes can't see.

#####Cyffyrddiad / Touch
Rhowch eich bys ar y synhwyrydd cyffyrddiad i gau'r cylched a chanfod y switsh.<br>
Placing your finger on the touch sensor will close the circuit and activate the switch.

#####Derbynnydd Radio / Radio Receiver
Mae'r derbynnydd radio yn gwrando am signalau penodol ar amledd o 433 MHz.<br>
The radio receiver is listening for specific signals at a frequency of 433 MHz.

#####GGD / LDR
Mae'r Gwrthydd Goleuni-Ddibynnol (GGD) yn newid ei gwrthiant gan fesur y golau o'i chwmpas - edrychwch beth sydd yn digwydd pan yr ydych yn cysgodi neu ddisgleirio golau arno.<br>
This Light-Dependant Resistor (LDR) can change it's resistance based on how much light it gets - try covering it up or shining a bright light at it.

#####DAG Gwyrdd / Green LED
Mae'r Deuod Allyrru Golau (DAG) yma yn disgleirio golau gwyrdd.<br>
This Light Emitting Diode (LED) shines green light.

#####Derbynnydd IG / IR Receiver
Yma, derbyniwyd y golau is-goch (IG) o'r allyrwyr IG uwch.<br>
Here, we detect the infrared (IR) light from the IR emitter that's above.

#####Switsh Pêl / Ball Switch
Mae pêl fach yn symud o ochr i ochr tu mewn i'r tiwb glas - pan mae'r bêl yn y canol mae'r switsh i ffwrdd, ar y dde neu'r chwith mae'r switsh ymlaen.<br>
A small ball moves from side to side inside the blue tube - when the ball is in the centre the switch is off, when it's at the left or right end it's on.

#####Switsh Brwynen Bach / Mini Reed Switch
Pan fyddwch yn dal magnet yn agos i'r switsh brwynen fach, bydd y ddwy frwynen metal yn symud i gyffwrdd ac yn cau'r cylched.<br>
When you wave a magnet over the mini reed switch, the two metal reeds inside the glass tube will move to touch each other and close the circuit.

#####DAG 2 liw / 2 Colour LED
Mae'r Deuod Allyrru Golau (DAG) yma yn goleuo yn goch ac yn wyrddlas (cymysgiad o wyrdd a glas).<br>
This Light Emitting Diode (LED) can light up in red and cyan (mix of green and blue).

#####Ffon Reoli / Joystick
Gallwch symud y ffon reoli i fyny ac i lawr, rhwng de a chwith, neu ei phwyso i mewn fel botwm.<br>
You can move the joystick up and down, left and right, or click it inwards like a button.

#####Botwm / Button
Pwyswch y botwm!<br>
Press the button!
