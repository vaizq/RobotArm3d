#include "Point2d.h"
#include "Arduino.h"

Point2d::Point2d()
{
	x = 0;
	y = 0;
}

Point2d::Point2d(float x, float y) :
	x(x), y(y)
{}

double Point2d::length()
{
	return sqrt(x*x + y*y);
}

Point2d Point2d::asUnit()
{
	float length = this->length();
	return Point2d(this->x / length, this->y / length);
}
float Point2d::dotProduct(Point2d a, Point2d b)
{
	return a.x * b.x + a.y * b.y;
}
// Calculates angle between two points. Returns smaller angle
float Point2d::angleBetween(Point2d a, Point2d b, bool degrees)
{
	float angle = acos(Point2d::dotProduct(a, b) / (a.length() * b.length()));
	if (degrees)
		return angle * (180 / PI);
	return angle;
}

// Returns angle in radians
float Point2d::angleBetween(Point2d a, Point2d b)
{
	float angle = acos( Point2d::dotProduct(a, b) / (a.length() * b.length()) );
	return angle;
}
