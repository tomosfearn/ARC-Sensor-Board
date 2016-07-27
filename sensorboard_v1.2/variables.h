/*
   left-right; top-bottom
   top row:
   temp & humidity (https://tkkrlab.nl/wiki/Arduino_KY-015_Temperature_and_humidity_sensor_module)
   light blocking (https://tkkrlab.nl/wiki/Arduino_KY-010_Optical_broken_module)
   PASSIVE buzzer; (https://tkkrlab.nl/wiki/Arduino_KY-006_Small_passive_buzzer_module)
   RGB LED; (https://tkkrlab.nl/wiki/Arduino_KY-016_3-color_LED_module)
   reed switch (https://tkkrlab.nl/wiki/Arduino_KY-025_Reed_module)
   7-col flash (https://tkkrlab.nl/wiki/Arduino_KY-034_Automatic_flashing_colorful_LED_module)

   2nd row:
   SMD LED - CHECK THE RESISTORS?? (https://tkkrlab.nl/wiki/Arduino_KY-009_3-color_full-color_LED_SMD_modules)
   tap CHECK 5V (https://tkkrlab.nl/wiki/Arduino_KY-031_Knock_Sensor_module)

   3rd row:
   ultrasound
   blocking (https://tkkrlab.nl/wiki/Arduino_KY-032_Obstacle_avoidance_sensor_module)
   2-col LED;
   microphone (https://tkkrlab.nl/wiki/Arduino_KY-038_Microphone_sound_sensor_module)
   ACTIVE buzzer (https://tkkrlab.nl/wiki/Arduino_KY-012_Active_buzzer_module)
   rotary encoder (https://tkkrlab.nl/wiki/Arduino_KY-040_Rotary_encoder_module)

   4th row:
   IR Tx (https://tkkrlab.nl/wiki/Arduino_KY-005_Infrared_emission_sensor_module)
   touch (https://tkkrlab.nl/wiki/Arduino_KY-036_Metal_touch_sensor_module)
   radio Rx;
   radio Tx
   LDR (https://tkkrlab.nl/wiki/Arduino_KY-018_Photo_resistor_module)
   heartbeat (https://tkkrlab.nl/wiki/Arduino_KY-039_Detect_the_heartbeat_module)

   bottom row:
   IR Rx (https://tkkrlab.nl/wiki/Arduino_KY-022_Infrared_sensor_receiver_module)
   tilt switch (https://tkkrlab.nl/wiki/Arduino_KY-020_Tilt_switch_module)
   mini reed; (https://tkkrlab.nl/wiki/Arduino_KY-021_Mini_magnetic_reed_modules)
   2-col LED - CHECK THE RESISTORS?? (https://tkkrlab.nl/wiki/Arduino_KY-011_2-color_LED_module)
   joystick (https://tkkrlab.nl/wiki/Arduino_KY-023_XY-axis_joystick_module)
   button (https://tkkrlab.nl/wiki/Arduino_KY-004_Key_switch_module)
*/




int temphumidity = 22; // temp & humidity
int lightBlockingPin = 29; // light blocking
int buzzerAPin = 2; // passive buzzer;
int rgbLedRedPin = 49; //RGB led Red
int rgbLedBluePin = 51; //RGB led Blue
int rgbLedGreenPin = 53; //RGB led Green
int reedPin = 47; // reed switch
int sevenColFlashPin = 39; // 7-col flash

int smdRedPin = 5; //SMD red led
int smdGreenPin = 4; //SMD green led
int smdBluePin = 3; //SMD blue led
int tapSensorPin = 37; //tap sensor

int ultrasonicTriggerPin = 34; //ultrasonic trigger
int ultrasonicEchoPin = 36;  //ultrasonic echo
int blockingPin = 27; // blocking
int rgLedRedPin = 28; //2 colour red led
int rgLedGreenPin = 26; //2 colour green led
int micPin = 31; //microphone input
int analogMicPin = A4; // microphone
int buzzerBPin = 45; // active buzzer

int rotaryEncoderSwitch = 38;
int rotaryEncoderData = 40;
int rotaryEncoderCLK = 42; //for generating interrupts using CLK signal
long rotaryEncoderCLKReadLast = digitalRead(rotaryEncoderCLK);
double val = 0;
boolean switchPressed = false;
const int ledCycle[] = {0, smdRedPin, smdGreenPin, smdBluePin};
int whichLed = 0;
int buttonState;
int lastButtonState = LOW;
long lastDebounceTime = 0;
long debounceDelay = 50;

int infraRedTx = 30; // IR Tx
int touchPin = 25; // touch
int radio1Pin = 46; // radio Rx; A5
int radio0Pin = 44; // radio Tx 44
int ldrPin = A0; // LDR

// heartbeat
int heartBeatPin = A1;
double alpha = 0.75;
int period = 100;
double change = 0.0;
double minval = 0.0; // heartbeat

int infraRedRx = 32; // IR Rx
int tiltPin = 23; // tilt switch
int miniReedPin = 24; // mini reed;
int heledCyan = 43;
int heledRed = 41; // 2-col LED
int rgb2LedGreen = A5;
int rgb2LedRed = 50;
int rgb2LedBlue = 48;
int joyStickButtonPin = 33;
int joyStickY = A2;
int joyStickX = A3; // joystick
int buttonPin = 35; // button

String myChoise;
int val1 = 0;
int val2 = 0;
int val3 = 0;
int val4 = 0;
int testDuration = 500;
int testSeparation = 500;
bool activateUltrasoundThing = false;
const int flash = 100;


