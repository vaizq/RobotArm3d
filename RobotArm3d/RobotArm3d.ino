/*
* Eliakses and Väinös arduino software for 3axis desktop robotic arm
*/
// Libraries
#include "Point2d.h"
#include "Joystick.h"
#include "RobotArm2d.h"
#include <Servo.h>

// TODO: Add stepper and controller for stepper

// Definitions
#define SERVO_1 3
#define SERVO_2 5
#define JOYSTICK_VRX A0
#define JOYSTICK_VRY A1
#define JOYSTICK_SW 2

// Variables
Servo servo1;
Servo servo2;
Joystick myJoystick;
RobotArm2d robotArm;



void setup() 
{
	Serial.begin(9600);

	servo1.attach(SERVO_1);
	servo2.attach(SERVO_2);
	myJoystick.attach(JOYSTICK_VRX, JOYSTICK_VRY, JOYSTICK_SW);
	robotArm.attach(myJoystick, servo1, servo2);
}

// the loop function runs over and over again until power down or reset
void loop() 
{
	robotArm.updatePos();

	delay(10);
}
