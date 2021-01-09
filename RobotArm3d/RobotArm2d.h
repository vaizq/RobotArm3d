#pragma once
#include <Arduino.h>
#include <Joystick.h>
#include <Servo.h>

class RobotArm2d
{
private:
	Joystick myJoystick;
	Servo servo0;
	Servo servo1;
public:
	// Servos should be alrady attached
	void attach(Joystick joystick, Servo servo1, Servo servo2);
	void updatePos();
};

