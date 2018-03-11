#include <iostream>
#include <exception>
#include "Date.h"
using namespace std;

Date::Date()
{
	setDay(1);
	setMonth(1);
	setYear(2000);
}

Date::Date(int d, int m, int y)
{
	setDay(d);
	setMonth(m);
	setYear(y);
}


Date::~Date()
{
	//not explained yet
	cout << "have a beautiful day" << endl;
}

int Date::countDigits(int number) const //counting digits of a number
{
	int digits = 0;
	do
	{
		number /= 10;
		digits++;
	} while (number != 0);
	return digits;
}

int Date::getDay() const
{
	return day;
}

int Date::getMonth() const
{
	return month;
}

int Date::getYear() const
{
	return year;
}


// please explain that we could have validation made
// in getters and throwing an exception if need at this stage

void Date::setDay(int d)
{
	day = d;

	//// validation

	//if (d >= 1 && d <= 31)
	//{
	//	day = d;
	//}
	//else
	//{
	//	throw "day not in valid range";
	//}

}

void Date::setMonth(int m)
{
	month = m;

	//// validation

	//if (m >= 1 && m <= 12)
	//{
	//	day = d;
	//}
	//else
	//{
	//	throw " month not in valid range";
	//}
}

void Date::setYear(int y)
{
	year = y;

	// validation

	//if (countDigits(y) == 4)
	//{
	//	year = y;
	//}
	//else
	//{
	//	throw "year is not 4 digits";
	//}
}

bool Date::checkDate(const Date &other) const
{
	if (other.day < 1 || other.day >31)
	{
		return false;
	}
	if (other.month < 1 || other.month >12)
	{
		return false;
	}
	if (countDigits(other.year) != 4)
	{
		return false;
	}
	return true;
}
