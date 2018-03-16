#include "Vector.h"
#include <iostream>
#include <ctime>
using namespace std;

Vector::Vector(int sizeVec)
{
	size = sizeVec;
	if (size)
	{
		numbers = new int[size];
		srand((unsigned)time(nullptr)); // move it to main is preferable
		for (int i = 0; i < size; i++)
		{
			numbers[i] = rand() % 100;
		}
	}
	else
	{
		numbers = nullptr; // do not stay with garbage
	}
}

Vector::Vector(int val, int sizeVec)
{
	size = sizeVec;
	numbers = new int[size];
	for (int i = 0; i < size; i++)
	{
		numbers[i] = val;
	}
}

Vector::Vector(int * vec, int sizeVec)
{
	size = sizeVec;
	numbers = new int[size];
	for (int i = 0; i < size; i++)
	{
		numbers[i] = vec[i];
	}
}

Vector::Vector(const Vector & source)
{
	size = source.size;
	numbers = new int[size];
	for (int i = 0; i < size; i++)
	{
		numbers[i] = source.numbers[i];
	}
}

Vector::~Vector()
{
	if (size)
	{
		delete[] numbers;
	}
}

void Vector::print() const
{
	for (int i = 0; i < size; i++)
	{
		cout << numbers[i] << ' ';
	}
	cout << endl;
}
