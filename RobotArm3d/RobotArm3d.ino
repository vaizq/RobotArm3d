/*
* Eliakses and Väinös arduino software for 3axis desktop robotic arm
*/
// Libraries
#include "Point2d.h"
#include "Joystick.h"
#include "RobotArm2d.h"
#include "RotaryEncoder.h"
#include <Servo.h>


// TODO: Elias pleas add stepper to this code.

// Definitions ( I changed servo pins! )
#define SERVO_1 5
#define SERVO_2 6
#define JOYSTICK_VRX A0
#define JOYSTICK_VRY A1
#define JOYSTICK_SW -1
#define ROTARYENCODER_CLK_PIN 2
#define ROTARYENCODER_DT_PIN 3
#define ROTARYENCODER_SW_PIN 4

// Variables
Servo servo1;
Servo servo2;
Joystick myJoystick;
RobotArm2d robotArm;
RotaryEncoder rEncoder;



void setup() 
{
	Serial.begin(9600);

	servo1.attach(SERVO_1);
	servo2.attach(SERVO_2);
	myJoystick.attach(JOYSTICK_VRX, JOYSTICK_VRY, JOYSTICK_SW);
	rEncoder.attach(ROTARYENCODER_CLK_PIN, ROTARYENCODER_DT_PIN, ROTARYENCODER_SW_PIN);
	robotArm.attach(myJoystick, servo1, servo2);
}

// the loop function runs over and over again until power down or reset
void loop() 
{
	

	delay(1);
}
