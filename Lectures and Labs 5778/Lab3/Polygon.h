#pragma once
#include "Point.h"
class Polygon
{
//private:
	Point * points;
	int n;
public:
	Polygon(int n = 0);
	Polygon(const Polygon& other);
	void addPoint(int index, const Point& pt);
	Polygon operator=(const Polygon& other);
	//view and modify
	Point& operator[](int index);
	double perimeter();
	~Polygon();
};

