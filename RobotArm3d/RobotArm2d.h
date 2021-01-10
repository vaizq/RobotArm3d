#pragma once
#include "Joystick.h"
#include "RotaryEncoder.h"
#include <Stepper.h>
#include <Arduino.h>
#include <Servo.h>

#define SERVO_1 5
#define SERVO_2 6
#define JOYSTICK_VRX A0
#define JOYSTICK_VRY A1
#define JOYSTICK_SW -1
#define ROTARYENCODER_CLK_PIN 2
#define ROTARYENCODER_DT_PIN 3
#define ROTARYENCODER_SW_PIN 4
#define STEPPER_STEPS 32

class RobotArm2d
{
private:
	Joystick myJoystick;
	Servo servo0;
	Servo servo1;
	RotaryEncoder rEncoder;
	Stepper stepper;
public:
	RobotArm2d(uint8_t stepperSteps, uint8_t stepperIn1, uint8_t stepperIn2, uint8_t stepperIn3, uint8_t stepperIn4);
	void attach(Joystick joystick, Servo servo1, Servo servo2, RotaryEncoder rEncoder);
	void updatePos();
};

