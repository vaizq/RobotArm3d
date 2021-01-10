/*
* Eliakses and Väinös arduino software for 3axis desktop robotic arm
*/
// Libraries
#include <Stepper.h>
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
#define STEPPER_STEPS 32
#define STEPPER_IN1 11
#define STEPPER_IN2 10
#define STEPPER_IN3 9
#define STEPPER_IN4 8


// Variables
Servo servo1;
Servo servo2;
Joystick myJoystick;
RotaryEncoder rEncoder;
// Stepper cant be just attached...
RobotArm2d robotArm(STEPPER_STEPS, STEPPER_IN1, STEPPER_IN2, STEPPER_IN3, STEPPER_IN4);

void setup() 
{
	Serial.begin(9600);
	
	servo1.attach(SERVO_1);
	servo2.attach(SERVO_2);
	myJoystick.attach(JOYSTICK_VRX, JOYSTICK_VRY, JOYSTICK_SW);
	rEncoder.attach(ROTARYENCODER_CLK_PIN, ROTARYENCODER_DT_PIN, ROTARYENCODER_SW_PIN);
	robotArm.attach(myJoystick, servo1, servo2, rEncoder);
}

// the loop function runs over and over again until power down or reset
void loop() 
{

	robotArm.updatePos();
	delay(1);
}
