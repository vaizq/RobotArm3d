#include "RobotArm2d.h"

void RobotArm2d::attach(Joystick joystick, Servo servo0, Servo servo1)
{
	this->servo0 = servo0;
	this->servo1 = servo1;
	myJoystick = joystick;
}

void RobotArm2d::updatePos()
{
	int joyValX = myJoystick.readXAxis();
	int joyValY = myJoystick.readYAxis();

	int servo0Angle = map(joyValX, 0, Joystick::MAX_VAL, 0, 180);
	int servo1Angle = map(joyValY, 0, Joystick::MAX_VAL, 0, 180);

	servo0.write(servo0Angle);
	servo1.write(servo1Angle);
}
