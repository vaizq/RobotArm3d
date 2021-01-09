#pragma once
#include <Arduino.h>

class Joystick
{
private:
	unsigned int xPin;
	unsigned int yPin;
	unsigned int swPin;
	static constexpr int MAX_VAL = 1023;
public:
	void attach(unsigned int xAxisPin, unsigned int yAxisPin, unsigned int buttonPin);
	int readXAxis();
	int readYAxis();
	int readButton();
};

