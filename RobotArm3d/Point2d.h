#pragma once

class Point2d
{
private:
	float x;
	float y;
public:
	Point2d();
	Point2d(float x, float y);

	void add(Point2d p);
	void mul(float scalar);
	double length();
	Point2d asUnit();

	static float dotProduct(Point2d a, Point2d b);
	static float angleBetween(Point2d a, Point2d b, bool degrees);
	static float angleBetween(Point2d a, Point2d b);
};

