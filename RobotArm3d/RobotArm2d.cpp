#include "RobotArm2d.h"


RobotArm2d::RobotArm2d(uint8_t stepperSteps, uint8_t stepperIn1, uint8_t stepperIn2, uint8_t stepperIn3, uint8_t stepperIn4):
	stepper(stepperSteps, stepperIn1, stepperIn2, stepperIn3, stepperIn4)
{}

void RobotArm2d::attach(Joystick joystick, Servo servo0, Servo servo1, RotaryEncoder rEncoder)
{
	myJoystick = joystick;
	this->servo0 = servo0;
	this->servo1 = servo1;
	this->rEncoder = rEncoder;
}


void RobotArm2d::updatePos()
{
	int joyValX = myJoystick.readXAxis();
	int joyValY = myJoystick.readYAxis();
	int stepperSteps = rEncoder.getPosition();

	int servo0Angle = map(joyValX, 0, Joystick::MAX_VAL, 0, 180);
	int servo1Angle = map(joyValY, 0, Joystick::MAX_VAL, 0, 180);

	servo0.write(servo0Angle);
	servo1.write(servo1Angle);

	stepper.setSpeed(100);
	stepper.step(stepperSteps);
}
