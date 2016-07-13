
#define DEBUG true
#define RAW false
#define DEMO false

#include "variables.h";
#include "pitches.h";


void setup() {
  Serial.begin(9600);

  //Input Sensors
  pinMode(lightBlockingPin, INPUT); //light blocking module
  pinMode(reedPin, INPUT); //reed switch
  pinMode(tapSensorPin, INPUT); //tap module
  pinMode(ultrasonicEchoPin, INPUT); //Ultrasonic echo
  pinMode(blockingPin, INPUT); //blocking module
  pinMode(micPin, INPUT); //microphone input
  pinMode(analogMicPin, INPUT); //analog microphone pin
  pinMode(rotaryEncoderSwitch, INPUT); //rotary encoder switch
  pinMode(rotaryEncoderData, INPUT); //rotary encoder input data
  pinMode(rotaryEncoderCLK, INPUT_PULLUP); //rotary encoder interrupt data
  pinMode(touchPin, INPUT_PULLUP); //touch sensor
  pinMode(radio_rxPin, INPUT); //radio receiver pin
  pinMode(ldrPin, INPUT); //light sensor
  pinMode(heartBeatPin, INPUT); //heart beat sensor
  pinMode(infraRedRx, INPUT); //infra red receiver
  pinMode(tiltPin, INPUT_PULLUP); //tilt module
  pinMode(miniReedPin, INPUT); //mini reed module
  pinMode(joyStickButtonPin, INPUT_PULLUP);
  pinMode(joyStickX, INPUT); //Joy Stick X axis
  pinMode(joyStickY, INPUT); //Joy stick Y axis
  pinMode(buttonPin, INPUT_PULLUP); //button module

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
  pinMode(radio_txPin, OUTPUT); //radio transmitter pin
  pinMode(rgLedRedPin, OUTPUT); //two colour led 2 red pin
  pinMode(rgLedGreenPin, OUTPUT); //two colour led 2 green pin
}

void loop() {
  if(Serial.available()) {
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
}


void mainProgram() {
  spacer();
  lightBlocking();
  reedSensor();
  button();
  buzzerA(1);
}

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
      rgLed2();
    }
    if (!lightBlocked) {
      //do nothing
    }
  }
#endif
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
      smdLed(1);
    }
    if (!reedActivated) {
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
#endif
  }
}






//shortcut hardware
void rgLed2() {
  digitalWrite(rgLedGreenPin2, HIGH);
  delay(flash);
  digitalWrite(rgLedGreenPin2, LOW);
  digitalWrite(rgLedRedPin2, HIGH);
  delay(flash);
  digitalWrite(rgLedRedPin2, LOW);
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
      for (int a = 0; a < 5; a++) {
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

