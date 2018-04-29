#pragma once
class MyDate
{
	int day, month, year;
	bool CheckConstrait(int num, int max);
public:
	MyDate(int d=1,int m=1,int y=1970);
	MyDate(MyDate & da);
	~MyDate();
	void SetDay(int);
	void SetMonth(int);
	void SetYear(int);
	int GetDay();
	int GetMonth();
	int GetYear();
	bool CheckDate(MyDate);
	bool operator==(const MyDate &) const;
	bool operator>(const MyDate &) const;
	bool operator<(const MyDate &) const;
	MyDate& operator++(); //prefix
	MyDate operator++(int); //postfix
	int operator+=(const int);
	void PrintDate();
};

