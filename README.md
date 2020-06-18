# Servo-Tester
Servo testing program that runs on an arduino. I used the servo library, the eeprom library and the JC Button library.

This is based on the simpler Servo 'knob' example code by Scott Fitzgerald with some alterations by myself for different modes. 

The servo tester includes 3 basic functions swapped between using the button.

Modes;

i.) Servo moves to 90 degree mod point and holds.
ii.) Servo is directly controllable via the potentiometer.
iii.) Servo slowly sweeps from side to side. 

The mode is written to Eeprom and remembered between power cycles. 

Button attaches to digital pin 2 for interupt. Don't change this.
Potentiometer attaches to analogue pin 0. This can be changed in the code.
Servo attaches to digital pin 6. This can be changed in the code.

You can buy a servo tester for a couple of quid that will do all the same things as this more expensive DIY option. I built this thing when I broke my servo tester, needed to test some servos, and didn't want to wait for shipping. 

Hardware isn't much more than an arduino, a potentiometer, a DC to DC voltage step down converter to power everything, and some pins etc. I 3D printed a box to put everything in and it looks quite neat. 
