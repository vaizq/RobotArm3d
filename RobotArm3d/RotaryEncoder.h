#pragma once
class RotaryEncoder
{
private:
	static constexpr int TICKS_PER_ROUND = 30;
	unsigned int CLK_PIN;
	unsigned int DT_PIN;
	unsigned int SW_PIN;
	int position;
	int clkState;
	int clkLastState;
public:
	void attach(unsigned int clkPin, unsigned int dtPin, unsigned int swPin);
	void updatePosition();
	int getPosition();
	int getAngle();
};

