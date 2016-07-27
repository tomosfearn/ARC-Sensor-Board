# ARC-Sensor-Board

Sensor Board Arduino Sketch

Collaborators:<br>
lionspaws<br>
tomosfearn<br>

## Board Map

| Input | Output |
|:-----:|:------:|
|Temperature and Humidity||
|Light Blocking|Buzzer A Arpeggio|
|Reed Switch|TODO RGB LED 1|
|Capacitive|TODO 7 Colour Flash|
|Ultrasound|TODO SMD RGB LED|
|IR Blocking|TODO 2 Colour LED 1|
|Microphone|Tap for Buzzer B tone|
|Rotary Encoder|Green LED: turn 0-255, press to turn on/off|
|IR Tx and Rx||
|Touch|RGB LED 2|
|Radio Rx|TODO 2 Colour LED (heled)|
|LDR|TODO modify the pulse rate of the green LED|
|Ball Switch||
|Mini Reed|TODO 2 Colour LED 1 and RGB LED 2|
|Joystick||
|Button|TODO All the LEDs!|

## Board Text

###Bwrdd Synhwyrydd / Sensor Board

Mae robotiaid yn defnyddio synhwyrydd i deall y byd o'u cwmpas. Mae'r bwrdd yma yn dangos gwahanol mathau o mewnbynnau ac allbynnau gallwch gweld ar robotiaid.<br>
Robots use sensors to understand the world around them. This board shows some of the different kinds of input and output sensors you might find on robots.

Mae synwyryddion mewnbynnol (e.e. botwmau, GGDau) yn casglu gwahanol cyfryngau o data, o'r amgylchedd neu o defnyddwyr dynol.<br>
Input sensors (e.g. buttons, LDRs) take different kinds of data in, from the environment or from a human user.

Mae synwyryddion allbynnol (e.e. DAGau, Swnyn) yn ffordd o dangos bod rhywbeth yn digwydd.<br>
Output sensors (e.g. LEDs, buzzers) are a way of showing that something is happening.

#####(Temperature & Humidity)

#####Atal Golau / Light Blocking
Mae golau is-goch (IG) yn teithio rhwng y bwlch, bydd y synhwyrydd yn canfod os ydych yn rhoi rhywbeth yn y bwlch i rhwystro'r golau.<br>
Infrared (IR) light is travelling between the gap, the sensor will activate if you put something into the gap and block the light.

#####Swnyn Goddefol / Passive Buzzer
Mae'r swnyn yn creu sŵn gan y cerrynt a derbynnir, felly mae'n hawdd newid y tôn i canu.<br>
This buzzer makes sound based on the current it receives, so we can change the tone easily to sing a song.

#####DAG CGG / RGB LED (x3)
Gall y Deuod Allyrru Golau (DAG) yma allyrru golau coch, gwyrdd, neu glas, a hyd yn oed cymysgiad o'r tri!<br>
This Light Emitting Diode (LED) can emit red, green, and blue light, or even a mix of all three!

#####Switsh Brwynen / Reed Switch
Pan fyddwch yn dal magnet yn agos i'r switsh brwynen, bydd y dau brwynen metal yn symud i cyffwrdd ac yn cau'r cylched.<br>
When you wave a magnet over the reed switch, the two metal reeds inside the glass tube will move to touch each other and close the circuit.

#####Fflach 7 Liw / 7 Colour Flash
Mae'r Deuod Allyrru Golau (DAG) yma yn cylchredu trwy 7 liw gwahanol mewn trefn sefydlog.<br>
This Light Emitting Diode (LED) cycles through 7 different colours in a fixed order.

#####Cyffyrddiad Cynhwysaidd / Capacitive Touch
Achos mae croen yn dargludo trydan, os ydych yn cyffwrdd y cylch gyda'ch bys, byddech yn cyflawni'r cylched a cau'r switsh - dyma sut mae nifer o sgriniau cyffwrdd ar ffonau clyfar yn gweithio!<br>
Because our skin can conduct electricity, touching your finger on the circle will complete the circuit and close the switch - this is how many smartphone touchscreens work!

#####Uwchsain / Ultrasound
Mae un llygad yn danfon 'ping', tra mae'r un arall yn gwrando am yr atsain. Gallwn cyfrifo pellder y gwrthrych adlewyrchol trwy mesur yr amser cymerwyd i'r swn teithio allan ac yn ôl.<br>
One eye sends out a 'ping', while the other listens for the echo coming back. We can calculate the distance of the reflecting object by measuring the time taken for the sound to travel out and back.

#####Ataliad IG / IR Blocking
Mae gan y synhwyrydd ataliad is-goch (IG) allyrwyr a derbynnydd yn gwynebu i fyny; os ydych yn atal y golau gyda'ch llaw, bydd y synhwyrydd yn canfod.<br>
This infrared (IR) blocking sensor has an IR emitter and receiver pointing upwards; if you block the light with your hand, it will activate the sensor.

#####DAG 2 liw / 2 Colour LED
Mae'r Deuod Allyrru Golau (DAG) yma yn goleuo yn gwyrdd ac yn goch.<br>
This Light Emitting Diode (LED) can light up in green and red.

#####Microffon / Microphone
Mae microffon yn synhwyro sain, ceisiwch tapio fo!<br>
The microphone detects sound, try tapping it!

#####Swnyn Actif / Active Buzzer
Mae'r swnyn yma yn cynnwys osgiliadur i greu sŵn, felly gallwn ei droi ymlaen ac i ffwrdd fel switsh.<br>
This buzzer contains an oscillator to make sound, so we can turn it on and off like a switch.

#####Amgodwyr Cylchdro / Rotary Encoder
Gall yr amgodwyr cylchdro deall os yw'n gael ei droi yn glocwedd neu yn gwrthglocwedd, a gallwch ei pwyso fel botwm.<br>
The rotary encoder can tell whether it is being turned clockwise or counter-clockwise, and can be pushed like a button.

#####Allyrwyr IG / IR Emitter
Mae'r Deuod Allyrru Golau (DAG) yma yn disgleirio golau is-goch (IG) sydd yn amhosib i'n llygaid weld.<br>
This Light Emitting Diode (LED) is shining infrared (IR) light which our eyes can't see.

#####Cyffyrddiad / Touch
Rhowch eich bys ar y synhwyrydd cyffyrddiad i cau'r cylched a canfod y switsh.<br>
Placing your finger on the touch sensor will close the circuit and activate the switch.

#####Derbynnydd Radio / Radio Receiver
Mae'r derbynnydd radio yn gwrando am signalau penodol ar amledd o 433 MHz.<br>
The radio receiver is listening for specific signals at a frequency of 433 MHz.

#####GGD / LDR
Mae'r Gwrthydd Goleuni-Ddibynnol (GGD) yn newid ei gwrthiant gan mesur y golau o'i cwmpas - edrychwch beth sydd yn digwydd pan yr ydych yn cysgodi neu disglerio golau arno.<br>
This Light-Dependant Resistor (LDR) can change it's resistance based on how much light it gets - try covering it up or shining a bright light at it.

#####DAG Gwyrdd / Green LED
Mae'r Deuod Allyrru Golau (DAG) yma yn disgleirio golau gwyrdd.<br>
This Light Emitting Diode (LED) shines green light.

#####Derbynnydd IG / IR Receiver
Yma, derbynwyd y golau is-goch (IG) o'r allyrwyr IG uwch.<br>
Here, we detect the infrared (IR) light from the IR emitter that's above.

#####Switsh Pêl / Ball Switch
Mae pêl bach yn symyd o ochr i ochr tu mewn i'r tiwb glas - pan mae'r pel yn y canol mae'r switsh i ffwrdd, ar y dde neu'r chwith mae'r switsh ymlaen.<br>
A small ball moves from side to side inside the blue tube - when the ball is in the centre the switch is off, when it's at the left or right end it's on.

#####Switsh Brwynen Bach / Mini Reed Switch
Pan fyddwch yn dal magnet yn agos i'r switsh brwynen bach, bydd y dau brwynen metal yn symud i cyffwrdd ac yn cau'r cylched.<br>
When you wave a magnet over the mini reed switch, the two metal reeds inside the glass tube will move to touch each other and close the circuit.

#####DAG 2 liw / 2 Colour LED
Mae'r Deuod Allyrru Golau (DAG) yma yn goleuo yn goch ac yn gwyrddlas (cymysgiad o gwyrdd a glas).<br>
This Light Emitting Diode (LED) can light up in red and cyan (mix of green and blue).

#####Ffon Reoli / Joystick
Gallwch symyd y ffon reoli i fyny ac i lawr, rhwng dde a chwith, neu ei pwyso i fewn fel botwm.<br>
You can move the joystick up and down, left and right, or click it inwards like a button.

#####Botwm / Button
Pwyswch y botwm!<br>
Press the button!