#pragma once
#include "Joystick.h"
#include <Arduino.h>
#include <Servo.h>

class RobotArm2d
{
private:
	Joystick myJoystick;
	Servo servo0;
	Servo servo1;
	static constexpr int MAX_ANGLE = 180;
public:
	// Servos should be alrady attached
	void attach(Joystick joystick, Servo servo0, Servo servo1);
	void updatePos();

	// Fun stuff
	void punch();
};

