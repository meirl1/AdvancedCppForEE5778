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
		for (int i = 0; i < n; i++)
		{
			points[i] = other.points[i];
		}
	}
	else
	{
		points = nullptr;
	}
}

void Polygon::addPoint(int index, const Point & pt)
{
	if (index >= 0 && index < n)
	{
		points[index] = pt;
	}
}
bool Polygon::operator> (const Polygon& other) const
{
	return (this->perimeter() > other.perimeter());
}

bool Polygon::operator== (const Polygon& other) const
{
	//hakol taluy
	for (size_t i = 0; i < n; i++)
	{
		if (points[i] != other.points[i])
		{
			return false;
		}
	}
	return true;
}

Polygon& Polygon::operator=(const Polygon & other)
{
	n = other.n;

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
		for (int i = 0; i < n; i++)
		{
			points[i] = other.points[i];
		}
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
	
	cout << "index out of range " << endl;
	//dummy
	return (*new Point());
}

double Polygon::perimeter() const
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
