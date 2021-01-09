#include "Joystick.h"

void Joystick::attach(unsigned int xAxisPin, unsigned int yAxisPin, unsigned int buttonPin)
{
	xPin = xAxisPin;
	yPin = yAxisPin;
	swPin = buttonPin;
	pinMode(xPin, INPUT);
	pinMode(yPin, INPUT);
	pinMode(swPin, INPUT);
}

int Joystick::readXAxis()
{
	return analogRead(xPin);
}

int Joystick::readYAxis()
{
	return MAX_VAL - analogRead(yPin);
}

int Joystick::readButton()
{
	return digitalRead(swPin);
}

