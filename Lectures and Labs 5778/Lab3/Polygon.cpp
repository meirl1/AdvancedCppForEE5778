#include "Polygon.h"
#include <iostream>
using namespace std;


Polygon::Polygon(int n): n(n),points(nullptr)
{
	if (n)
	{
		points = new Point[n];
	}
}

Polygon::Polygon(const Polygon & other): n(other.n)
{
	if (n)
	{
		points = new Point[n];
	}
	for (int i = 0; i < n; i++)
	{
		points[i] = other.points[i];
	}
}

void Polygon::addPoint(int index, const Point & pt)
{
	if (index >= 0 && index < n)
	{
		points[index] = Point(pt);
	}
}

Polygon Polygon::operator=(const Polygon & other)
{
	// free old memory storage
	if (points != nullptr)
	{
		delete[] points;
		points = nullptr;
	}
	//copy all data from other object
	if (n)
	{
		points = new Point[n];
	}
	for (int i = 0; i < n; i++)
	{
		points[i] = other.points[i];
	}
	//for transitivity
	return *this;
}

Point & Polygon::operator[](int index)
{
	if (index >= 0 && index < n)
	{
		return  points[index];
	}
	else
	{
		cout << "index out of range " << endl;
	}
	//dummy
	return (*new Point());
}

double Polygon::perimeter()
{
	double sum = 0.0;
	for (int i = 0; i < n-1; i++)
	{
		sum += points[i].distance(points[i + 1]);
	}
	sum += points[n - 1].distance(points[0]);
	return sum;
}


Polygon::~Polygon()
{
	if (n)
	{
		delete[] points;
	}
}
