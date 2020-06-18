/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>
#include <EEPROM.h>         // EEPROM Library.
#include <JC_Button.h>      // https://github.com/JChristensen/JC_Button

Servo myservo;  // create servo object to control a servo

// Button setup
#define BUTTON 2            // Button for mode changes. Has to be either 2 or 3 on most arduinos for the code to work properly.
Button myBtn(BUTTON, 25, true);   // define the button using button library.

byte selectedEffect = 0;    // Keeps track of servo mode.

int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

void setup() {
  myBtn.begin();                                                                            // initialize the button object using button library.
  myservo.attach(6);  // attaches the servo on pin 6 to the servo object
  attachInterrupt (digitalPinToInterrupt (BUTTON), changeEffect, CHANGE);                   // Button works on interup. Runs changEffect when pressed. Uncertain.
  Serial.begin(9600);                                                                       // open the serial port at 9600 bps:
}

void loop() {
  EEPROM.get(0, selectedEffect);                                                            // Read mode from EEPROM (for some reason).

   if (selectedEffect > 1) {                                                                // Change number here when adding effects. Loops back to 0.
    selectedEffect = 0;
    EEPROM.put(0, 0);                                                                       // Store the LED pattern number in EEPROM.
  }

   // *********************************************************************
  // ** List / Order of Effects. Add new ones here. Add functions below.**
  // *********************************************************************

  switch (selectedEffect) {

    case 0  : {
      myservo.write(90); 
      //Serial.print(" 0: Servo Mid Point ");     //Print out current pattern mode name and number.
      delay(10);
      break;
    }

      

    case 1  : {
      val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
      val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
      myservo.write(val);                  // sets the servo position according to the scaled value
      //Serial.print(" 0: Servo Pot control ");     //Print out current pattern mode name and number.
      break;
    }
}
}

void PotControl() {
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(val);                  // sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there
}



  // Change modes / effects. When button is pressed selected effect is incrimented and stored to EEPROM for save on reset.
void changeEffect() {
  myBtn.read();               // read the button
  if (myBtn.wasPressed())
  {
    selectedEffect++;
    EEPROM.put(0, selectedEffect);
    asm volatile ("  jmp 0");
  }
}
