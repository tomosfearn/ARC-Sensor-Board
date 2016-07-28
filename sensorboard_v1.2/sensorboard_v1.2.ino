#define DEBUG false
#define RAW false
#define DEMO true

#include "variables.h";
#include "pitches.h";

void setup() {
  Serial.begin(9600);

  //Input Sensors
  pinMode(lightBlockingPin, INPUT); //light blocking module
  pinMode(reedPin, INPUT); //reed switch
  //pinMode(tapSensorPin, INPUT_PULLUP); //tap module
  pinMode(ultrasonicEchoPin, INPUT); //Ultrasonic echo
  pinMode(blockingPin, INPUT); //blocking module
  pinMode(micPin, INPUT); //microphone input
  pinMode(analogMicPin, INPUT); //analog microphone pin
  pinMode(rotaryEncoderSwitch, INPUT_PULLUP); //rotary encoder switch
  pinMode(rotaryEncoderData, INPUT); //rotary encoder input data
  pinMode(rotaryEncoderCLK, INPUT); //rotary encoder interrupt data
  pinMode(touchPin, INPUT_PULLUP); //touch sensor
  //pinMode(radio_rxPin, INPUT); //radio receiver pin
  pinMode(ldrPin, INPUT); //light sensor
  pinMode(infraRedRx, INPUT_PULLUP); //infra red receiver
  pinMode(tiltPin, INPUT_PULLUP); //tilt module
  pinMode(miniReedPin, INPUT); //mini reed module
  pinMode(joyStickButtonPin, INPUT_PULLUP);
  pinMode(joyStickX, INPUT); //Joy Stick X axis
  pinMode(joyStickY, INPUT); //Joy stick Y axis
  pinMode(buttonPin, INPUT_PULLUP); //button module
  pinMode(radio0Pin, INPUT); //radio 0
  pinMode(radio1Pin, INPUT); //radio 1

  //Outputs
  pinMode(buzzerAPin, OUTPUT); //buzzer A
  pinMode(smdRedPin, OUTPUT); // SMD red led
  pinMode(smdGreenPin, OUTPUT); //SMD green led
  pinMode(smdBluePin, OUTPUT); //SMD blue led
  pinMode(sevenColFlashPin, OUTPUT); //7-col flash
  pinMode(rgbLedRedPin, OUTPUT); //RGB red led
  pinMode(rgbLedGreenPin, OUTPUT); //RGB green led
  pinMode(rgbLedBluePin, OUTPUT); //RGB blue led
  pinMode(ultrasonicTriggerPin, OUTPUT); //Ultrasonic trigger
  pinMode(rgLedRedPin, OUTPUT); //two colour led red
  pinMode(rgLedGreenPin, OUTPUT); //two colour led green
  pinMode(buzzerBPin, OUTPUT); //buzzer B
  pinMode(infraRedTx, OUTPUT); //infrared transmitter
  pinMode(heledCyan, OUTPUT); //two colour led 2 red pin
  pinMode(heledRed, OUTPUT); //two colour led 2 green pin
  pinMode(rgb2LedRed, OUTPUT);
  pinMode(rgb2LedGreen, OUTPUT);
  pinMode(rgb2LedBlue, OUTPUT);
  pinMode(greenLed, OUTPUT); //green LED
}

void loop() {
  if (Serial.available()) {
#ifdef DEBUG
    if (DEBUG) {
      myChoise = Serial.readString();
      if (myChoise == "light blocking") {
        lightBlocking();
      }

      if (myChoise == "reed sensor") {
        reedSensor();
      }

      if (myChoise == "button") {
        button();
      }

      if (myChoise == "buzzerA") {
        buzzerA(1);
      }
    }
#endif
  }
#ifdef RAW
  mainProgram();
#endif
#ifdef DEMO
  mainProgram();
#endif
}


void mainProgram() {
  //  spacer();

  //input
//  lightBlocking();
//  reedSensor();
  ultrasonic();
//  irBlocking();
//  microphone();
//  rotaryEncoder();
  //itTxRxSensors();
//  touchSensor();
//  radio();
  //ldr();
  //heartbeat();
  //ballSwitch();
  miniReedSensor();
  //joystick();
  //button();
  //temperatureAndHumidity();
  //tapSensor();
  //  heled();
  //output
  //buzzerA(1);
  //  rgb2LED();
}

// temp and humidity - need to work out how to represent data

void lightBlocking() {
  int lightBlocked = digitalRead(lightBlockingPin);
#ifdef DEBUG
  if (DEBUG) {
    Serial.println("Debug: Light Blocking Module...");
    for (int i = 10; i > 0; i--) {
      if (lightBlocked) {
        Serial.print("Light has been blocked on ");
        Serial.print(i);
        Serial.println(" turn");
        debugDelay();
        success();
        continue;
      }
      else {
        if (i == 0) {
          fail();
        }
        else {
          Serial.print(i);
          Serial.println(" turns left");
          debugDelay();
        }
      }
    }
  }
#endif
#ifdef RAW
  if (RAW) {
    Serial.println("RAW data from light blocking module is ");
    Serial.println(lightBlocked);
    debugDelay();
  }
#endif
#ifdef DEMO
  if (DEMO) {
    if (lightBlocked) {
      buzzerA(2);
    }
    if (!lightBlocked) {
      //do nothing
    }
  }
#endif
}

void buzzerA(int song) {
#ifdef DEBUG
  if (DEBUG) {
    if (song == 1) {
      for (int currentNote = 0; currentNote < sizeof(MARY_HAD_A_LITTLE_LAMB_NOTES); currentNote++) {
        Serial.println(MARY_HAD_A_LITTLE_LAMB_NOTES[currentNote]);
        int noteDuration = 1000 / MARY_HAD_A_LITTLE_LAMB_DURATION[currentNote];
        tone(buzzerAPin, MARY_HAD_A_LITTLE_LAMB_NOTES[currentNote], noteDuration);
        delay(noteDuration * 1.30);
        noTone(8);
      }
    }
  }
#endif
#ifdef DEMO
  if (DEMO) {
    if (song == 1) {
      for (int currentNote = 0; currentNote < sizeof(MARY_HAD_A_LITTLE_LAMB_NOTES); currentNote++) {
        int noteDuration = 1000 / MARY_HAD_A_LITTLE_LAMB_DURATION[currentNote];
        tone(buzzerAPin, MARY_HAD_A_LITTLE_LAMB_NOTES[currentNote], noteDuration);
        delay(noteDuration * 1.30);
        noTone(8);
      }
    }
    else if (song == 2) {
      for (int currentNote = 0; currentNote < sizeof(C_ARPEGGIO_NOTES); currentNote++) {
        int noteDuration = 1000 / C_ARPEGGIO_DURATION[currentNote];
        tone(buzzerAPin, C_ARPEGGIO_NOTES[currentNote], noteDuration);
        delay(noteDuration * 1.30);
        noTone(8);
      }
    }
#endif
  }
}

void reedSensor() {
  int reedActivated = digitalRead(reedPin);
#ifdef DEBUG
  if (DEBUG) {
    Serial.println("Debug: Reed Module...");
    for (int i = 10; i > 0; i--) {
      if (reedActivated) {
        Serial.print("Reed has been activated on ");
        Serial.print(i);
        Serial.println(" turn");
        debugDelay();
        success();
      }
      else {
        if (i == 0) {
          fail();
        }
        else {
          Serial.print(i);
          Serial.println(" turns left");
          debugDelay();
        }
      }
    }
  }
#endif
#ifdef RAW
  if (RAW) {
    Serial.println("RAW data from the reed module is ");
    Serial.println(reedActivated);
    debugDelay();
  }
#endif
#ifdef DEMO
  if (DEMO) {
    if (reedActivated) {
      rgbLed();
    }
    if (!reedActivated) {
      //do nothing
    }
  }
#endif
}

void ultrasonic() {
  // trigger ping
  digitalWrite(ultrasonicTriggerPin, HIGH);
  delay(10);
  digitalWrite(ultrasonicTriggerPin, LOW);
  // read echo
  long ultrasonicRead = pulseIn(ultrasonicEchoPin, HIGH);
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  distance = (ultrasonicRead / 29) / 2;
#ifdef DEBUG
  if (DEBUG) {
    Serial.println("Debug: Ultrasonic Module...");
    for (int i = 10; i > 0; i--) {
      if (ultrasonicRead) {
        Serial.print("Ultrasonic Sensor is receiving data on ");
        Serial.print(i);
        Serial.println(" turn");
        debugDelay();
        success();
        continue;
      }
      else {
        if (i == 0) {
          fail();
        }
        else {
          Serial.print(i);
          Serial.println(" turns left");
          debugDelay();
        }
      }
    }
  }
#endif
#ifdef RAW
  if (RAW) {
    Serial.println("RAW data from ultrasonic module is ");
    Serial.println(ultrasonicRead);
    debugDelay();
  }
#endif
#ifdef DEMO
  if (DEMO) {
    distance = (ultrasonicRead / 29) / 2;
    if (distance < 60) {
      valRGB = 768 - (15 * distance);
      // update the colour values
      if(valRGB <= 255) {
        valR = valRGB;
      }
      else {
        valR = 0;
      }
      if(valRGB > 255 && valRGB <= 512) {
        valG = valRGB - 255;
      }
      else {
        valG = 0;
      }
      if(valRGB > 512 && valRGB <= 768) {
        valB = valRGB - (255 * 2);
      }
      else {
        valB = 0;
      }
      analogWrite(smdRedPin, valR);
      analogWrite(smdGreenPin, valG);
      analogWrite(smdBluePin, valB);
    }
    if (distance > 60) {
      //do nothing
      analogWrite(smdRedPin, 0);
      analogWrite(smdGreenPin, 0);
      analogWrite(smdBluePin, 0);
    }
  }
#endif
}

void irBlocking() {
  int irBlocked = digitalRead(blockingPin);
#ifdef DEBUG
  if (DEBUG) {
    Serial.println("Debug: IR Blocking Module...");
    for (int i = 10; i > 0; i--) {
      if (irBlocked) {
        Serial.print("IR has been blocked on ");
        Serial.print(i);
        Serial.println(" turn");
        debugDelay();
        success();
        continue;
      }
      else {
        if (i == 0) {
          fail();
        }
        else {
          Serial.print(i);
          Serial.println(" turns left");
          debugDelay();
        }
      }
    }
  }
#endif
#ifdef RAW
  if (RAW) {
    Serial.println("RAW data from IR blocking module is ");
    Serial.println(irBlocked);
    debugDelay();
  }
#endif
#ifdef DEMO
  if (DEMO) {
    if (!irBlocked) {
      rgLed1();
    }
    if (irBlocked) {
      //do nothing
    }
  }
#endif
}

void microphone() {
  int micTapped = digitalRead(micPin);
#ifdef DEBUG
  if (DEBUG) {
    Serial.println("Debug: Microphone Module...");
    for (int i = 10; i > 0; i--) {
      if (micTapped) {
        Serial.print("Microphone has been tapped on ");
        Serial.print(i);
        Serial.println(" turn");
        debugDelay();
        success();
        continue;
      }
      else {
        if (i == 0) {
          fail();
        }
        else {
          Serial.print(i);
          Serial.println(" turns left");
          debugDelay();
        }
      }
    }
  }
#endif
#ifdef RAW
  if (RAW) {
    Serial.println("RAW data from microphone module is ");
    Serial.println(micTapped);
    debugDelay();
  }
#endif
#ifdef DEMO
  if (DEMO) {
    if (micTapped) {
      buzzerB();
    }
    if (!micTapped) {
      //do nothing
    }
  }
#endif
}

void buzzerB() {
  analogWrite(buzzerBPin, 255);
  delay(200);
  analogWrite(buzzerBPin, 0);
}

void rotaryEncoder() {
  int rotaryEncoderDataRead = digitalRead(rotaryEncoderData);
  int rotaryEncoderCLKRead = digitalRead(rotaryEncoderCLK);
  int rotaryEncoderSwitchRead = digitalRead(rotaryEncoderSwitch);
#ifdef DEBUG
  if (DEBUG) {
    Serial.println("Debug: Rotary Encoder Module...");
    for (int i = 10; i > 0; i--) {
      if (rotaryEncoderData) {
        Serial.print("Rotary Encoder is receiving data on ");
        Serial.print(i);
        Serial.println(" turn");
        debugDelay();
        success();
        continue;
      }
      else {
        if (i == 0) {
          fail();
        }
        else {
          Serial.print(i);
          Serial.println(" turns left");
          debugDelay();
        }
      }
    }
  }
#endif
#ifdef RAW
  if (RAW) {
    Serial.println("RAW data from rotary encoder is ");
    Serial.print("Data: ");
    Serial.print(rotaryEncoderDataRead);
    Serial.print(", CLK: ");
    Serial.print(rotaryEncoderCLKRead);
    Serial.print(", button: ");
    Serial.println(rotaryEncoderSwitchRead);
    debugDelay();
  }
#endif
#ifdef DEMO
  if (DEMO) {
    if (rotaryEncoderSwitchRead != lastButtonState) {
      lastDebounceTime = millis();
    }
    if ((millis() - lastDebounceTime) > debounceDelay) {
      if (rotaryEncoderSwitchRead != buttonState) {
        buttonState = rotaryEncoderSwitchRead;
        if (buttonState == HIGH) {
          switchPressed = !switchPressed;
          analogWrite(greenLed, 0);
        }
      }
    }
    lastButtonState = rotaryEncoderSwitchRead;
    if (switchPressed) {
      rotaryEncoderCLKRead = digitalRead(rotaryEncoderCLK);
      if (rotaryEncoderCLKRead > rotaryEncoderCLKReadLast) {
        if (rotaryEncoderCLKRead != rotaryEncoderDataRead) {
          //          Serial.println ("clockwise");
          if (val <= 250) {
            val += 5;
          }
          else {
            val = 0;
          }
        }
        else {
          //          Serial.println ("counterclockwise");
          if (val >= 5) {
            val -= 5;
          }
          else {
            val = 0;
          }
        }
        analogWrite(greenLed, val);
      }
      rotaryEncoderCLKReadLast = rotaryEncoderCLKRead;
    }
  }
#endif
}

void itTxRxSensors() {
  digitalWrite(infraRedTx, HIGH); // turn on the transmitter

  int irReceiver = digitalRead(infraRedRx);
#ifdef DEBUG
  if (DEBUG) {
    Serial.println("Debug: IR Receiver Module...");
    for (int i = 10; i > 0; i--) {
      if (irReceiver) {
        Serial.print("IR has been blocked on ");
        Serial.print(i);
        Serial.println(" turn");
        debugDelay();
        success();
        continue;
      }
      else {
        if (i == 0) {
          fail();
        }
        else {
          Serial.print(i);
          Serial.println(" turns left");
          debugDelay();
        }
      }
    }
  }
#endif
#ifdef RAW
  if (RAW) {
    Serial.println("RAW data from IR receiver module is ");
    Serial.println(irReceiver);
    debugDelay();
  }
#endif
#ifdef DEMO
  if (DEMO) {
    if (irReceiver) {
      heled();
    }
    if (!irReceiver) {
      //do nothing
    }
  }
#endif
}

void touchSensor() {
  int touchRead = digitalRead(touchPin);
#ifdef DEBUG
  if (DEBUG) {
    Serial.println("Debug: Touch Module...");
    for (int i = 10; i > 0; i--) {
      if (touchRead) {
        Serial.print("Touch Sensor has been touched on ");
        Serial.print(i);
        Serial.println(" turn");
        debugDelay();
        success();
        continue;
      }
      else {
        if (i == 0) {
          fail();
        }
        else {
          Serial.print(i);
          Serial.println(" turns left");
          debugDelay();
        }
      }
    }
  }
#endif
#ifdef RAW
  if (RAW) {
    Serial.println("RAW data from touch module is ");
    Serial.println(touchRead);
    debugDelay();
  }
#endif
#ifdef DEMO
  if (DEMO) {
    if (touchRead) {
      rgb2LED();
    }
    if (!touchRead) {
      //do nothing
    }
  }
#endif
}


void radio() {
  bool radio0 = digitalRead(radio0Pin);
  bool radio1 = digitalRead(radio1Pin);


//  Serial.println(radio0);

  if (radio0) {
    digitalWrite(heledCyan, HIGH);
    delay(500);
    digitalWrite(heledCyan, LOW);
  }

  if (radio1) {
    digitalWrite(heledRed, HIGH);
    delay(500);
    digitalWrite(heledRed, LOW);
  }

  if ((!radio0) && (!radio1)) {
    //do nothing
  }

}

void ldr() {
  int ldrRead = analogRead(ldrPin);
#ifdef DEBUG
  if (DEBUG) {
    Serial.println("Debug: LDR Module...");
    for (int i = 10; i > 0; i--) {
      if (ldrRead) {
        Serial.print("LDR Sensor is receiving data on ");
        Serial.print(i);
        Serial.println(" turn");
        debugDelay();
        success();
        continue;
      }
      else {
        if (i == 0) {
          fail();
        }
        else {
          Serial.print(i);
          Serial.println(" turns left");
          debugDelay();
        }
      }
    }
  }
#endif
#ifdef RAW
  if (RAW) {
    Serial.println("RAW data from ldr module is ");
    Serial.println(ldrRead);
    debugDelay();
  }
#endif
#ifdef DEMO
  if (DEMO) {
    Serial.println(ldrRead);
  }
#endif
}

void heartbeat() {
  int heartbeatRead = analogRead(greenLed);
#ifdef DEBUG
  if (DEBUG) {
    Serial.println("Debug: Heartbeat Module...");
    for (int i = 10; i > 0; i--) {
      if (heartbeatRead) {
        Serial.print("Heartbeat Sensor is receiving data on ");
        Serial.print(i);
        Serial.println(" turn");
        debugDelay();
        success();
        continue;
      }
      else {
        if (i == 0) {
          fail();
        }
        else {
          Serial.print(i);
          Serial.println(" turns left");
          debugDelay();
        }
      }
    }
  }
#endif
#ifdef RAW
  if (RAW) {
    Serial.println("RAW data from heartbeat module is ");
    Serial.println(heartbeatRead);
    debugDelay();
  }
#endif
#ifdef DEMO
  if (DEMO) {
    static double oldValue = 0;
    static double oldChange = 0;

    double value = alpha * oldValue + (1 - alpha) * heartbeatRead;

    Serial.print (heartbeatRead);
    Serial.print (",");
    Serial.println (value);
    oldValue = value;

    delay (period);
  }
#endif
}

void ballSwitch() {
  int ballRead = digitalRead(tiltPin);
#ifdef DEBUG
  if (DEBUG) {
    Serial.println("Debug: Ball Switch Module...");
    for (int i = 10; i > 0; i--) {
      if (ballRead) {
        Serial.print("Ball Switch has been tilted on ");
        Serial.print(i);
        Serial.println(" turn");
        debugDelay();
        success();
        continue;
      }
      else {
        if (i == 0) {
          fail();
        }
        else {
          Serial.print(i);
          Serial.println(" turns left");
          debugDelay();
        }
      }
    }
  }
#endif
#ifdef RAW
  if (RAW) {
    Serial.println("RAW data from ball switch module is ");
    Serial.println(ballRead);
    debugDelay();
  }
#endif
#ifdef DEMO
  if (DEMO) {
    if (ballRead) {
      rgLed1();
      rgb2LED();
    }
    if (!ballRead) {
      //do nothing
    }
  }
#endif
}

void miniReedSensor() {
  int reedActivated = digitalRead(miniReedPin);
#ifdef DEBUG
  if (DEBUG) {
    Serial.println("Debug: Mini Reed Module...");
    for (int i = 10; i > 0; i--) {
      if (reedActivated) {
        Serial.print("Mini Reed has been activated on ");
        Serial.print(i);
        Serial.println(" turn");
        debugDelay();
        success();
      }
      else {
        if (i == 0) {
          fail();
        }
        else {
          Serial.print(i);
          Serial.println(" turns left");
          debugDelay();
        }
      }
    }
  }
#endif
#ifdef RAW
  if (RAW) {
    Serial.println("RAW data from the mini reed module is ");
    Serial.println(reedActivated);
    debugDelay();
  }
#endif
#ifdef DEMO
  if (DEMO) {
    if (!reedActivated) {
      for(int i = 0; i < 256; i++) {
        analogWrite(7, i);
        delay(5);
      }
    }
    if (reedActivated) {
      analogWrite(7, 0);
    }
  }
#endif
}

void joystick() {
  long joyStickXRead = analogRead(joyStickX);
  long joyStickYRead = analogRead(joyStickY);
  int joyStickButtonRead = digitalRead(joyStickButtonPin);

#ifdef DEBUG
  if (DEBUG) {
    Serial.println("Debug: Joystick Module...");
    for (int i = 10; i > 0; i--) {
      if (joyStickXRead) {
        Serial.print("Joystick is receiving X data on ");
        Serial.print(i);
        Serial.println(" turn");
        debugDelay();
        success();
        continue;
      }
      if (joyStickYRead) {
        Serial.print("Joystick is receiving Y data on ");
        Serial.print(i);
        Serial.println(" turn");
        debugDelay();
        success();
        continue;
      }
      if (joyStickButtonRead) {
        Serial.print("Joystick button being pressed on ");
        Serial.print(i);
        Serial.println(" turn");
        debugDelay();
        success();
        continue;
      }
      else {
        if (i == 0) {
          fail();
        }
        else {
          Serial.print(i);
          Serial.println(" turns left");
          debugDelay();
        }
      }
    }
  }
#endif
#ifdef RAW
  if (RAW) {
    Serial.println("RAW data from joystick is ");
    Serial.print("X: ");
    Serial.print(joyStickXRead);
    Serial.print(", Y: ");
    Serial.print(joyStickYRead);
    Serial.print(", button: ");
    Serial.println(joyStickButtonRead);
    debugDelay();
  }
#endif
#ifdef DEMO
  if (DEMO) {
    if (joyStickButtonRead) {
      heled();
    }
    if (!joyStickButtonRead) {
      //do nothing
    }
  }
#endif
}

void button() {
  int buttonPressed = digitalRead(buttonPin);
#ifdef DEBUG
  if (DEBUG) {
    Serial.println("Debug: Button Module...");
    for (int i = 10; i > 0; i--) {
      if (buttonPressed) {
        Serial.print("Button has been pressed ");
        Serial.print(i);
        Serial.println(" turn");
        debugDelay();
        success();
      }
      else {
        if (i == 0) {
          fail();
        }
        else {
          Serial.print(i);
          Serial.println(" turns left");
          debugDelay();
        }
      }
    }
  }
#endif
#ifdef RAW
  if (RAW) {
    Serial.println("Not Applicable for Buzzer!");
    Serial.println(buttonPressed);
    debugDelay();
  }
#endif
#ifdef DEMO
  if (DEMO) {
    if (buttonPressed) {
      buzzerA(1);
    }
    if (!buttonPressed) {
      //do nothing
    }
  }
#endif
}


//shortcut hardware
void rgLed1() {
  digitalWrite(rgLedGreenPin, HIGH);
  delay(flash);
  digitalWrite(rgLedGreenPin, LOW);
  digitalWrite(rgLedRedPin, HIGH);
  delay(flash);
  digitalWrite(rgLedRedPin, LOW);
  delay(flash);
}

void heled() {
  digitalWrite(heledCyan, HIGH);
  delay(flash);
  digitalWrite(heledCyan, LOW);
  digitalWrite(heledRed, HIGH);
  delay(flash);
  digitalWrite(heledRed, LOW);
  delay(flash);
}

void smdLed(int sequence) {
#ifdef DEBUG
  if (DEBUG == true) {
    Serial.println("Test: SMD LED");
    digitalWrite(smdRedPin, HIGH);
    delay(300);
    digitalWrite(smdRedPin, LOW);
    digitalWrite(smdGreenPin, HIGH);
    delay(300);
    digitalWrite(smdGreenPin, LOW);
    digitalWrite(smdBluePin, HIGH);
    delay(300);
    digitalWrite(smdBluePin, LOW);
    //
    analogWrite(smdRedPin, 255);
    analogWrite(smdGreenPin, 0);
    analogWrite(smdBluePin, 255);
    delay(300);
    analogWrite(smdRedPin, 0);
    analogWrite(smdGreenPin, 0);
    analogWrite(smdBluePin, 0);
    Serial.print("complete");
  }
#endif
#ifdef DEMO
  if (DEMO == true) {
    if (sequence == 1) {
      for (int a = 0; a < 1; a++) {
        digitalWrite(smdRedPin, HIGH);
        delay(100);
        digitalWrite(smdRedPin, LOW);
        digitalWrite(smdGreenPin, HIGH);
        delay(100);
        digitalWrite(smdGreenPin, LOW);
        digitalWrite(smdBluePin, HIGH);
        delay(100);
        digitalWrite(smdBluePin, LOW);
      }
    }
  }
#endif
}

void rgbLed() {
  digitalWrite(rgbLedRedPin, HIGH);
  delay(flash);
  digitalWrite(rgbLedRedPin, LOW);
  digitalWrite(rgbLedGreenPin, HIGH);
  delay(flash);
  digitalWrite(rgbLedGreenPin, LOW);
  digitalWrite(rgbLedBluePin, HIGH);
  delay(flash);
  digitalWrite(rgbLedBluePin, LOW);
}

void rgb2LED() {
  digitalWrite(rgb2LedRed, HIGH);
  delay(flash);
  digitalWrite(rgb2LedRed, LOW);
  digitalWrite(rgb2LedGreen, HIGH);
  delay(flash);
  digitalWrite(rgb2LedGreen, LOW);
  digitalWrite(rgb2LedBlue, HIGH);
  delay(flash);
  digitalWrite(rgb2LedBlue, LOW);
}

/*
  void temperatureAndHumidity() {
  int temp = analogRead(temphumidity);
  Serial.println(temp);
  }

  void tapSensor() {
  int tapDetected = digitalRead(tapSensorPin);
  Serial.println(tapDetected);
  }
*/


//shortcut methods
void spacer() {
  Serial.println("-----------------------------------------------------");
}

void timedOut() {
  Serial.println("Timed out");
}

void success() {
  Serial.println("Success!!, passed debug program!!");
  spacer();
  debugDelay();
}

void fail() {
  Serial.println("Failure!!, failed the debug program!!");
  Serial.println("Giving up and moving to next sensor!");
  spacer();
  debugDelay();
}

void debugDelay() {
  delay(500);
}

