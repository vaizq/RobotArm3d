/*
* Eliakses and Väinös arduino software for 3axis desktop robotic arm
*/
// Libraries
#include "Point2d.h"
#include "Joystick.h"
#include <Servo.h>

// Definitions
#define SERVO_0 3
#define JOYSTICK_VRX A0
#define JOYSTICK_VRY A1
#define JOYSTICK_SW 2

// Variables
Servo servo1;
Joystick myJoystick;

void setup() 
{
	Serial.begin(9600);

	servo1.attach(SERVO_0);
	myJoystick.attach(JOYSTICK_VRX, JOYSTICK_VRY, JOYSTICK_SW);
}

// the loop function runs over and over again until power down or reset
void loop() 
{
	/*Serial.print("X_axis: ");
	Serial.print(myJoystick.readXAxis());
	Serial.print("	Y_axis: ");
	Serial.println(myJoystick.readYAxis());*/
	
	Serial.println(myJoystick.readButton());

	delay(100);
}
