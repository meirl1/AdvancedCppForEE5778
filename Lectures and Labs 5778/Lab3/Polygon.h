#pragma once
#include "Point.h"
class Polygon
{
//private:
	Point * points;	// KISHMO KEN HU
	int n;			// number of points in polygon
public:
	Polygon(int n = 0);
	Polygon(const Polygon& other);
	void addPoint(int index, const Point& pt);
	Polygon& operator=(const Polygon& other);
	//operators
	bool operator== (const Polygon& other) const;
	bool operator> (const Polygon& other) const;
	//view and modify
	Point& operator[](int index);
	double perimeter()const;
	~Polygon();
};

