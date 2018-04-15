#pragma once
class MyDate
{
	int day, month, year;
	bool CheckConstrait(int num, int max);
public:
	MyDate();
	~MyDate();
	void SetDay(int);
	void SetMonth(int);
	void SetYear(int);
};

