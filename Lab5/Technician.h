#pragma once
#include "Employee.h"
#include <iostream>
using namespace std;

class Technician :	public Employee
{
	static constexpr int DAY_RATE = 100;
	static constexpr int NIGHT_RATE = 150;

public:
	Technician(const char* name, int days, int nights);
	Technician(const Technician& tech);
	~Technician();

	void printDetails() const;
	double calcSalary() const override;
};

inline Technician::Technician(const char * name, int days, int nights):Employee(name,days,nights)
{
}

Technician::Technician(const Technician & tech):Employee(tech)
{
}


Technician::~Technician()
{
}

inline void Technician::printDetails()const
{
	cout << "Techician" << endl;
	cout << "Salary is: " << calcSalary() << endl;;
}

inline double Technician::calcSalary() const
{
	double salary = getDays() * DAY_RATE + getNights() * NIGHT_RATE;
	int totalHours = (getDays() + getNights()) / 24;
	if (totalHours > 50)
	{
		salary *= 1.20;
	}
	return salary;
}
