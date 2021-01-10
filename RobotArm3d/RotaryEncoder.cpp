#include "RotaryEncoder.h"
#include <Arduino.h>

void RotaryEncoder::attach(unsigned int clkPin, unsigned int dtPin, unsigned int swPin)
{
	CLK_PIN = clkPin;
	DT_PIN = dtPin;
	SW_PIN = swPin;
	pinMode(CLK_PIN, INPUT);
	pinMode(DT_PIN, INPUT);
	pinMode(SW_PIN, INPUT);

	position = 0;
	clkLastState = digitalRead(CLK_PIN);
}

void RotaryEncoder::updatePosition()
{
	clkState = digitalRead(CLK_PIN);

	if (clkState != clkLastState)
	{
		if (clkState != digitalRead(DT_PIN))
		{
			// CCW rotation
			--position;
		}
		else
		{
			// CW rotation
			++position;
		}
	}
	clkLastState = clkState;
}

int RotaryEncoder::getPosition()
{
	updatePosition();
	return position;
}
// Returns angle as radians
int RotaryEncoder::getAngle()
{
	updatePosition();
	return position * (2 * PI / TICKS_PER_ROUND);
}
