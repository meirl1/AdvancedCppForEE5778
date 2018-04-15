#include "MyDate.h"



bool MyDate::CheckConstrait(int num, int max)
{
	if (num <= max)
		return true;
	return false;
}

MyDate::MyDate(int d,int m,int y)
{
	day = d;
	month = m;
	year = y;
}


MyDate::~MyDate()
{
}

void MyDate::SetDay(int d)
{
	day = d;
}

void MyDate::SetMonth(int m)
{
	month = m;
}

void MyDate::SetYear(int y)
{
	year = y;
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
