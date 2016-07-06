#include "variables.h";
#include "pitches.h";

void setup() {
  // top row:
  // temp & humidity
  pinMode(lightblocking, INPUT); // light blocking
  pinMode(buzzerpin_a, OUTPUT); // buzzer;
  pinMode(smdredpin, OUTPUT); 
  pinMode(smdbluepin, OUTPUT); 
  pinMode(smdgreenpin, OUTPUT); // SMD LED
  pinMode(reedpin, INPUT); // reed switch
  pinMode(sevencolflashpin, OUTPUT); // 7-col flash

  // 2nd row:
  pinMode(rgbled_r, OUTPUT); 
  pinMode(rgbled_g, OUTPUT); 
  pinMode(rgbled_b, OUTPUT); // RGB LED;
  pinMode(tappin, INPUT_PULLUP); // tap

  // 3rd row:
  pinMode(ultrasoundtrig, OUTPUT); 
  pinMode(ultrasoundecho, INPUT); // ultrasound
  pinMode(blockingpin, INPUT); // blocking
  pinMode(twocola_r, OUTPUT); 
  pinMode (twocola_g, OUTPUT); // 2-col LED;
  pinMode(micpin, INPUT); // microphone
  pinMode(buzzerpin_b, OUTPUT); // buzzer
  pinMode(rotaryenc_sw, INPUT); 
  pinMode(rotaryenc_dt, INPUT); 
  pinMode(rotaryenc_clk, INPUT_PULLUP); // rotary encoder

  // 4th row:
  pinMode(irTx, OUTPUT); // IR Tx
  pinMode(touchpin, INPUT_PULLUP); // touch
  // radio Rx;
  // radio Tx
  // analog, requires serial only // LDR
  // analog, requires serial only // heartbeat

  // bottom row:
  pinMode(irRx, INPUT); // IR Rx
  pinMode(tiltpin, INPUT_PULLUP); // tilt switch
  pinMode(minireedpin, INPUT); // mini reed;
  pinMode(twocolb_r, OUTPUT); 
  pinMode(twocolb_g, OUTPUT); // 2-col LED
  pinMode(joystickbuttonpin, INPUT_PULLUP); 
  pinMode(joystickX, INPUT); 
  pinMode(joystickY, INPUT); // joystick
  pinMode(buttonpin, INPUT_PULLUP); // button

  Serial.begin(9600);
}

void loop() {
  // test sensors
  if (debugOn) {
    // start testing
    delay(testSeparation);
    Serial.println("Testing sensor board");
    Serial.println("--------------------");
    delay(testSeparation);

    // top row:
    Serial.println("Row 1");
    Serial.println("-----");
    delay(testSeparation);
    //    temp_humidity(); // temp & humidity TO DO
    //    light_blocking(); // light blocking
    //    buzzer_a(true); // buzzer; value from 0-255
    //    rgb_led(); // RGB LED;
    //    reed_switch(); // reed switch
    //    seven_colour_flash(); // 7-col flash

    // 2nd row:
    Serial.println("Row 2");
    Serial.println("-----");
    delay(testSeparation);
    //    smd_led(0); // SMD LED
    tap_sensor(); // tap

    // 3rd row:
    Serial.println("Row 3");
    Serial.println("-----");
    delay(testSeparation);
    //    ultrasound_sensor(); // ultrasound
    //    blocking(); // blocking
    //    two_col_led_a(); // 2-col LED;
    //    microphone(); // microphone
    //    buzzer_b(); // active buzzer
    //    rotary_enc(); // rotary encoder

    // 4th row:
    Serial.println("Row 4");
    Serial.println("-----");
    delay(testSeparation);
    //    ir_tx(); // IR Tx
    //    touch(); // touch
    //    radio_rx(); // radio Rx;
    //    radio_tx(); // radio Tx
    //    ldr(); // LDR
    //    heartbeat(); // heartbeat

    // bottom row:
    Serial.println("Row 5");
    Serial.println("-----");
    delay(testSeparation);
    //    ir_rx(); // IR Rx
    //    tilt_switch(); // tilt switch
    //    mini_reed(); // mini reed;
    //    two_col_led_b(); // 2-col LED
    //    joystick(); // joystick
    //    button(); // button

    // finish testing
    Serial.println("--------------------");
    Serial.println("Testing complete");
    Serial.println("--------------------\n\n");
  }
  // otherwise run the demo



  
  else {
    // check all the inputs for stuff to happen
    light_blocking(); // light blocking
    reed_switch(); // reed switch
    ultrasound_sensor(); // ultrasound
    blocking(); // blocking
    microphone(); // microphone
    ir_tx(); // IR Tx
    ir_rx(); // IR Rx
    touch(); // touch
    ldr(); // LDR
    tilt_switch(); // tilt switch
    mini_reed(); // mini reed;
    joystick(); // joystick
    button(); // button
  }
}

////// top row:
// temp & humidity
void temp_humidity() {
  if (debugOn) {
    Serial.println("Test: temperature and humidity ");
    Serial.print("... sensor not active... skipping");
    delay(testDelay);
  }
}
// light blocking
void light_blocking() {
  if (debugOn) {
    Serial.println("Test: light blocking ");
    for (int a = 0; a < 100; a++) {
      Serial.print(digitalRead(lightblocking));
      delay(100);
    }
    Serial.println("complete");
    delay(testDelay);
  }
  else {
    if (digitalRead(lightblocking) == HIGH) {
      two_col_led_b(); // 2-col LED
    }
  }
}
// PASSIVE buzzer;
void buzzer_a(int tune) {
  if (debugOn) {
    Serial.println("Test: passive buzzer");
    //    digitalWrite(buzzerpin_a, HIGH);
    //    delay(testDuration);
    //    digitalWrite(buzzerpin_a, LOW);

    // EDCDEEE DDDEEE EDCDEEE EDDEDC
    // NOTE_C3  131
    // NOTE_D3  147
    // NOTE_E3  165
    int melody[] = {
      NOTE_E3, NOTE_D3, NOTE_C3, NOTE_D3, NOTE_E3, NOTE_E3, NOTE_E3,
      NOTE_D3, NOTE_D3, NOTE_D3, NOTE_E3, NOTE_E3, NOTE_E3,
      NOTE_E3, NOTE_D3, NOTE_C3, NOTE_D3, NOTE_E3, NOTE_E3, NOTE_E3,
      NOTE_E3, NOTE_D3, NOTE_D3, NOTE_E3, NOTE_D3, NOTE_C3
    };
    int noteDurations[] = {
      4, 4, 4, 4, 4, 4, 2,
      4, 4, 2, 4, 4, 2,
      4, 4, 4, 4, 4, 4, 4,
      4, 4, 4, 4, 4, 2
    };
    for (int thisNote = 0; thisNote < 26; thisNote++) {
      int noteDuration = 1000 / noteDurations[thisNote];
      tone(buzzerpin_a, melody[thisNote], noteDuration);
      delay(noteDuration * 1.30);
      noTone(8); // stop the tone playing
    }

    Serial.print("complete");
    delay(10000);//testDelay);
  }
  else {
    if (tune == 1) {
      // EDCDEEE DDDEEE EDCDEEE EDDEDC
      // NOTE_C3  131
      // NOTE_D3  147
      // NOTE_E3  165
      int melody[] = {
        NOTE_E3, NOTE_D3, NOTE_C3, NOTE_D3, NOTE_E3, NOTE_E3, NOTE_E3,
        NOTE_D3, NOTE_D3, NOTE_D3, NOTE_E3, NOTE_E3, NOTE_E3,
        NOTE_E3, NOTE_D3, NOTE_C3, NOTE_D3, NOTE_E3, NOTE_E3, NOTE_E3,
        NOTE_E3, NOTE_D3, NOTE_D3, NOTE_E3, NOTE_D3, NOTE_C3
      };
      int noteDurations[] = {
        4, 4, 4, 4, 4, 4, 2,
        4, 4, 2, 4, 4, 2,
        4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 2
      };
      int noteCount = 26;
      for (int thisNote = 0; thisNote < noteCount; thisNote++) {
        int noteDuration = 1000 / noteDurations[thisNote];
        tone(buzzerpin_a, melody[thisNote], noteDuration);
        delay(noteDuration * 1.30);
        noTone(8); // stop the tone playing
      }
    }
  }
}
// 3-col LED;
void rgb_led() {
  if (debugOn) {
    Serial.println("Test: RGB LED");
    digitalWrite(rgbled_r, HIGH);
    delay(500);
    digitalWrite(rgbled_r, LOW);
    digitalWrite(rgbled_g, HIGH);
    delay(500);
    digitalWrite(rgbled_g, LOW);
    digitalWrite(rgbled_b, HIGH);
    delay(500);
    digitalWrite(rgbled_b, LOW);
    Serial.print("complete");
    delay(testDelay);
  }
  else {
    for (int a = 0; a < 5; a++) {
      digitalWrite(rgbled_r, HIGH);
      delay(100);
      digitalWrite(rgbled_r, LOW);
      digitalWrite(rgbled_g, HIGH);
      delay(100);
      digitalWrite(rgbled_g, LOW);
      digitalWrite(rgbled_b, HIGH);
      delay(100);
      digitalWrite(rgbled_b, LOW);
    }
  }
}
// reed switch
void reed_switch() {
  if (debugOn) {
    Serial.println("Test: reed switch");
    Serial.println("waiting for input");
    for (int a = 0; a < 100; a++) {
      Serial.print(digitalRead(reedpin));
      delay(500);
    }
    Serial.println("complete");
    delay(testDelay);
  }
  else {
    if (digitalRead(reedpin) == HIGH) {
      smd_led(1);
    }
  }
}
// 7-col flash
void seven_colour_flash() {
  if (debugOn) {
    Serial.println("Test: 7-colour flash");
    digitalWrite (sevencolflashpin, HIGH); // set the LED on
    delay(5000);
    digitalWrite (sevencolflashpin, LOW); // set the LED off
    Serial.print("complete");
    delay(testDelay);
  }
  else {
    digitalWrite (sevencolflashpin, HIGH); // set the LED on
    delay(5000);
    digitalWrite (sevencolflashpin, LOW); // set the LED off
  }
}

////// 2nd row:
// SMD LED
void smd_led(int routine) {
  if (debugOn) {
    Serial.println("Test: SMD LED");
    digitalWrite(smdredpin, HIGH);
    delay(300);
    digitalWrite(smdredpin, LOW);
    digitalWrite(smdgreenpin, HIGH);
    delay(300);
    digitalWrite(smdgreenpin, LOW);
    digitalWrite(smdbluepin, HIGH);
    delay(300);
    digitalWrite(smdbluepin, LOW);
    //
    analogWrite(smdredpin, 255);
    analogWrite(smdgreenpin, 0);
    analogWrite(smdbluepin, 255);
    delay(300);
    analogWrite(smdredpin, 0);
    analogWrite(smdgreenpin, 0);
    analogWrite(smdbluepin, 0);
    Serial.print("complete");
    delay(testDelay);
  }
  else {
    if (routine == 1) {
      for (int a = 0; a < 5; a++) {
        digitalWrite(smdredpin, HIGH);
        delay(100);
        digitalWrite(smdredpin, LOW);
        digitalWrite(smdgreenpin, HIGH);
        delay(100);
        digitalWrite(smdgreenpin, LOW);
        digitalWrite(smdbluepin, HIGH);
        delay(100);
        digitalWrite(smdbluepin, LOW);
      }
    }
  }
}
// tap
void tap_sensor() {
  if (debugOn) {
    Serial.println("Test: tap");
    Serial.println("waiting for input");
    for (int a = 0; a < 100; a++) {
      Serial.print(digitalRead(tappin));
      delay(50);
    }
    Serial.println("complete");
    delay(testDelay);
  }
}

////// 3rd row:
// ultrasound
void ultrasound_sensor() {
  if (debugOn) {
    Serial.println("Test: ultrasound");
    Serial.println("waiting for input");
    for (int a = 0; a < 50; a++) {
      // trigger ping
      digitalWrite(ultrasoundtrig, HIGH);
      delay(10);
      digitalWrite(ultrasoundtrig, LOW);
      // read echo
      long duration = pulseIn(ultrasoundecho, HIGH);
      // The speed of sound is 340 m/s or 29 microseconds per centimeter.
      // The ping travels out and back, so to find the distance of the
      // object we take half of the distance travelled.
      Serial.print((duration / 29) / 2);
      Serial.println("cm");
      delay(500);
    }
    Serial.println("complete");
    delay(testDelay);
  }
  else {
    // trigger ping
    digitalWrite(ultrasoundtrig, HIGH);
    delay(10);
    digitalWrite(ultrasoundtrig, LOW);
    // read echo
    long duration = pulseIn(ultrasoundecho, HIGH);
    // The speed of sound is 340 m/s or 29 microseconds per centimeter.
    // The ping travels out and back, so to find the distance of the
    // object we take half of the distance travelled.
    long distance = (duration / 29) / 2;

    if (activateUltrasoundThing) {
      if (distance < 100) {
        tone(buzzerpin_a, distance * 20, 8);
      }
    }
  }
}
// blocking
void blocking() {
  if (debugOn) {
    Serial.println("Test: blocking");
    Serial.println("waiting for input");
    for (int a = 0; a < 100; a++) {
      Serial.print(digitalRead(blockingpin));
      delay(500);
    }
    Serial.println("complete");
    delay(testDelay);
  }
  else {
    if (digitalRead(blockingpin) == LOW) {
      activateUltrasoundThing = true;
    }
    else {
      activateUltrasoundThing = false;
    }
  }
}
// 2-col LED;
void two_col_led_a() {
  if (debugOn) {
    Serial.println("Test: 2-colour LED");
    digitalWrite(twocola_g, HIGH);
    delay(500);
    digitalWrite(twocola_g, LOW);
    digitalWrite(twocola_r, HIGH);
    delay(500);
    digitalWrite(twocola_r, LOW);
    Serial.println("complete");
    delay(testDelay);
  }
  else {
    for (int a = 0; a < 3; a++) {
      for (int b = 0; b < 3; b++) {
        digitalWrite(twocola_r, HIGH);
        delay(100);
        digitalWrite(twocola_r, LOW);
        delay(50);
      }
      for (int b = 0; b < 3; b++) {
        digitalWrite(twocola_g, HIGH);
        delay(100);
        digitalWrite(twocola_g, LOW);
        delay(50);
      }
    }
  }
}
// microphone
void microphone() {
  if (debugOn) {
    Serial.println("Test: microphone");
    Serial.println("waiting for input");
    for (int a = 0; a < 100; a++) {
      Serial.print(digitalRead(micpin));
      delay(500);
    }
    Serial.println("...complete");
    delay(testDelay);
  }
  else {
    if (digitalRead(micpin) == HIGH) {
      buzzer_b();
    }
  }
}
// ACTIVE buzzer
void buzzer_b() {
  if (debugOn) {
    Serial.println("Test: active buzzer");
    analogWrite(buzzerpin_b, 255);
    delay(testDuration);
    analogWrite(buzzerpin_b, 0);
    Serial.print("complete");
    delay(testDelay);
  }
  else {
    analogWrite(buzzerpin_b, 255);
    delay(200);
    analogWrite(buzzerpin_b, 0);
  }
}
// rotary encoder
void rotary_enc() {
  if (debugOn) {
    Serial.println("Test: rotary encoder");
    //    Serial.print("... sensor not active... skipping");
    Serial.println("button: ");
    for (int a = 0; a < 50; a++) {
      Serial.print(digitalRead(rotaryenc_clk));
      delay(300);
    }
    Serial.println("sw: ");
    for (int a = 0; a < 50; a++) {
      Serial.print(digitalRead(rotaryenc_sw));
      delay(300);
    }
    Serial.println("dt: ");
    for (int a = 0; a < 50; a++) {
      Serial.print(digitalRead(rotaryenc_dt));
      delay(300);
    }
    Serial.println("complete");
    delay(testDelay);
  }
}

////// 4th row:
// IR Tx
void ir_tx() {
  if (debugOn) {
    Serial.println("Test: IR Tx");
    //    Serial.print("... sensor not active... skipping");
    Serial.print("IR emitter ON");
    digitalWrite(irTx, HIGH);
    delay(testDelay);
  }
  else {
    digitalWrite(irTx, HIGH);
  }
}
// touch
void touch() {
  if (debugOn) {
    Serial.println("Test: touch");
    Serial.println("waiting for input");
    for (int a = 0; a < 100; a++) {
      Serial.print(digitalRead(touchpin));
      delay(500);
    }
    Serial.println("complete");
    delay(testDelay);
  }
  else {
    if (digitalRead(touchpin) == HIGH) {
      seven_colour_flash();
    }
  }
}
// radio Rx;
void radio_rx() {
  if (debugOn) {
    Serial.println("Test: radio Rx");
    Serial.print("... sensor not active... skipping");
    delay(testDelay);
  }
}
// radio Tx
void radio_tx() {
  if (debugOn) {
    Serial.println("Test: radio Tx");
    Serial.print("... sensor not active... skipping");
    delay(testDelay);
  }
}
// LDR
void ldr() {
  if (debugOn) {
    Serial.println("Test: LDR");
    Serial.println("waiting for input");
    for (int a = 0; a < 100; a++) {
      Serial.print(analogRead(ldrpin));
      Serial.print(", ");
      delay(500);
    }
    Serial.println("complete");
    delay(testDelay);
  }
  // currently, 400 works as a threshold (under 400 when covered)
}
// heartbeat
void heartbeat() {
  if (debugOn) {
    Serial.println("Test: heartbeat");
    for (int i = 0; i < 100; i++) {
      //      static double oldValue = 0;
      //      static double oldChange = 0;
      int rawValue = analogRead(heartbeatpin);
      //      double value = alpha * oldValue + (1 - alpha) * rawValue;
      //      Serial.print(i + ": ");
      Serial.println(rawValue);
      //      Serial.print(",");
      //      Serial.println(value);
      //      oldValue = value;
      delay(500);
    }
    Serial.println("complete");
    delay(testDelay);
  }
}

////// bottom row:
// IR Rx
void ir_rx() {
  if (debugOn) {
    Serial.println("Test: IR Rx");
    //    Serial.print("... sensor not active... skipping");
    Serial.println("waiting for input");
    for (int a = 0; a < 100; a++) {
      Serial.print(digitalRead(irRx));
      delay(500);
    }
    Serial.println("complete");
    delay(testDelay);

    // turn off the emitter
    digitalWrite(irTx, LOW);
  }
  else {
    if (digitalRead(irRx) == LOW) {
      rgb_led();
    }
  }
}
// tilt switch
void tilt_switch() {
  if (debugOn) {
    Serial.println("Test: tilt switch");
    Serial.println("waiting for input");
    for (int a = 0; a < 100; a++) {
      Serial.print(digitalRead(tiltpin));
      delay(500);
    }
    Serial.println("complete");
    delay(testDelay);
  }
  else {
    if (digitalRead(tiltpin) == LOW) {
      rgb_led();
    }
  }
}
// mini reed;
void mini_reed() {
  if (debugOn) {
    Serial.println("Test: mini reed");
    Serial.println("waiting for input");
    for (int a = 0; a < 100; a++) {
      Serial.print(digitalRead(minireedpin));
      delay(500);
    }
    Serial.println("complete");
    delay(testDelay);
  }
  else {
    if (digitalRead(minireedpin) == LOW) {
      two_col_led_a();
    }
  }
}
// 2-col LED
void two_col_led_b() {
  if (debugOn) {
    Serial.println("Test: 2-colour LED ");
    digitalWrite(twocolb_g, HIGH);
    delay(300);
    digitalWrite(twocolb_g, LOW);
    delay(15);
    digitalWrite(twocolb_r, HIGH);
    delay(300);
    digitalWrite(twocolb_r, LOW);
    Serial.print("complete");
    delay(testDelay);
  }
  else {
    for (int a = 0; a < 5; a++) {
      digitalWrite(twocolb_g, HIGH);
      delay(100);
      digitalWrite(twocolb_g, LOW);
      digitalWrite(twocolb_r, HIGH);
      delay(100);
      digitalWrite(twocolb_r, LOW);
    }
  }
}
// joystick
void joystick() {
  if (debugOn) {
    Serial.println("Test: joystick");
    Serial.println("button: ");
    for (int a = 0; a < 50; a++) {
      Serial.print(digitalRead(joystickbuttonpin));
      delay(300);
    }
    Serial.println("x-axis: ");
    for (int a = 0; a < 50; a++) {
      //      Serial.print(analogRead(joystickX));
      // 0 <- 427 -> 856
      long reading = analogRead(joystickX);
      if (reading < 425) {
        Serial.print("L");
      }
      else if (reading > 430) {
        Serial.print("R");
      }
      else {
        Serial.print("C");
      }
      delay(300);
    }
    Serial.println("y-axis: ");
    for (int a = 0; a < 50; a++) {
      //      Serial.print(analogRead(joystickY));
      // 0 <- 427 -> 856
      long reading = analogRead(joystickY);
      if (reading < 425) {
        Serial.print("D");
      }
      else if (reading > 430) {
        Serial.print("U");
      }
      else {
        Serial.print("C");
      }
      delay(300);
    }
    Serial.println("complete");
    delay(testDelay);
  }
}
// button
void button() {
  if (debugOn) {
    Serial.println("Test: button");
    Serial.println("waiting for input");
    for (int a = 0; a < 100; a++) {
      Serial.print(digitalRead(buttonpin));
      delay(300);
    }
    Serial.println("...complete");
    delay(testDelay);
  }
  else {
    if (digitalRead(buttonpin) == LOW) {
      buzzer_a(1);
    }
  }
}

