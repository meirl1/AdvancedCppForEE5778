#include "MyDate.h"
#include <iostream>
using namespace std;

bool MyDate::CheckConstrait(int num, int max)
{
	if (num <= max && num >= 1)
		return true;
	return false;
}

MyDate::MyDate(int d,int m,int y)
{
	SetDay(d);
	SetMonth(m);
	SetYear(y);
}

MyDate::MyDate(MyDate & da)
{
	day = da.day;
	month = da.month;
	year = da.year;
}


MyDate::~MyDate()
{
}

void MyDate::SetDay(int d)
{
	if(CheckConstrait(d,31)) day = d;
}

void MyDate::SetMonth(int m)
{
	if(CheckConstrait(m,12)) month = m;
}

void MyDate::SetYear(int y)
{
	if(CheckConstrait(y,9999)) year = y;
}

int MyDate::GetDay()
{
	return day;
}

int MyDate::GetMonth()
{
	return month;
}

int MyDate::GetYear()
{
	return year;
}

bool MyDate::CheckDate(MyDate da)
{
	return (CheckConstrait(da.day,31) && CheckConstrait(da.month,12) && CheckConstrait(da.year,9999));
}

bool MyDate::operator>(const MyDate & da) const
{
	if (year > da.year)
		return true;
	else if (year == da.year && month > da.month)
		return true;
	else if (month == da.month && day > da.day)
		return true;
	return false;
}

bool MyDate::operator<(const MyDate & da) const
{
	if ((*this)>da || (*this)==da)
		return false;
	return true;
}

bool MyDate::operator==(const MyDate & da) const
{
	if (year == da.year && month == da.month && day == da.day)
		return true;
	return false;
}

MyDate & MyDate::operator++()
{
	if (day < 31)
		day++;
	else if (month < 12) {
		day = 1;
		month++;
	}
	else {
		SetYear(++year);
		day = 1;
		month = 1;
	}
	return *this;
}

MyDate MyDate::operator++(int)
{
	MyDate da(*this);
	++(*this);
	return da;
}

int MyDate::operator+=(const int num)
{
	for (int i = 0; i < num; i++)
		++(*this);
	return num;
}

void MyDate::PrintDate()
{
	cout.width(2);
	cout.fill('0');
	cout << day << '/' << month << '/' << year << endl;
}
