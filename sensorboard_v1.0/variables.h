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




// variables
bool debugOn = false;
// top row:




//int temphumidity = 22; // temp & humidity
int lightblocking = 29; // light blocking
int buzzerpin_a = 2; // passive buzzer;
int rgbled_r = 49; int rgbled_b = 51; int rgbled_g = 53; // RGB LED;
int reedpin = 47; // reed switch
int sevencolflashpin = 39; // 7-col flash




// 2nd row:
int smdredpin = 5; 
int smdbluepin = 3; 
int smdgreenpin = 4; // SMD LED
int tappin = 37; // tap




// 3rd row:
int ultrasoundtrig = 34; 
int ultrasoundecho = 36;  // ultrasound
int blockingpin = 27; // blocking
int twocola_r = 28; 
int twocola_g = 26; // 2-col LED;
int micpin = 31; 
int micpinAnalog = A4; // microphone
int buzzerpin_b = 45; // active buzzer
int rotaryenc_sw = 38; 
int rotaryenc_dt = 40; 
int rotaryenc_clk = 42; // rotary encoder




// 4th row:
int irTx = 30; // IR Tx
int touchpin = 25; // touch
//int radio_rx = A5; // radio Rx; A5
//int radio_tx = 44; // radio Tx 44
int ldrpin = A0; // LDR
int heartbeatpin = A1; 
double alpha = 0.75; 
int period = 100; 
double change = 0.0; 
double minval = 0.0; // heartbeat




// bottom row:
int irRx = 32; // IR Rx
int tiltpin = 23; // tilt switch
int minireedpin = 24; // mini reed;
int twocolb_r = 43; 
int twocolb_g = 41; // 2-col LED
int joystickbuttonpin = 33; 
int joystickY = A2; 
int joystickX = A3; // joystick
int buttonpin = 35; // button




int val1 = 0, val2 = 0, val3 = 0, val4 = 0;
int testDelay = 500, testDuration = 500, testSeparation = 500;
bool activateUltrasoundThing = false;
