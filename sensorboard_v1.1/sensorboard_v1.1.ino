
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
  if (DEBUG) {
    doDebug();
  }
  else {
    doDemo();
  }
}

void doDemo() {

}


void doDebug() {
  Serial.println("Starting debug program...");
  spacer();
  lightBlocking();
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
        break;
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
    while (lightBlocked) {
      rgLed2();
    }
    if (!lightBlocked) {
      //do nothing
    }
  }
#endif
}






//shortcut hardware
void rgLed2() {
  digitalWrite(rgLedGreenPin2, HIGH);
  delay(flash);
  digitalWrite(rgLedGreenPin2, LOW);
  digitalWrite(rgLedRedPin2, HIGH);
  delay(flash);
  digitalWrite(rgLedRedPin2, LOW);
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

