#pragma once
#include "Employee.h"
#include <iostream>
using namespace std;

class Seller :	public Employee
{
	static constexpr int DAY_RATE = 25;
	static constexpr int NIGHT_RATE = 35;

public:
	Seller(const char* name, int days, int nights);
	Seller(const Seller& seller);
	~Seller();
	
	void printDetails() const ;
	double calcSalary()const override;
};

inline Seller::Seller(const char * name, int days, int nights):Employee(name,days,nights)
{
}

Seller::Seller(const Seller & seller):Employee(seller)
{
}


Seller::~Seller()
{
}

inline void Seller::printDetails() const
{
	cout << "Seller" << endl;
	cout << "Salary is: " << calcSalary() << endl;;

}

inline double Seller::calcSalary() const
{
	double salary = getDays() * DAY_RATE + getNights() * NIGHT_RATE;
	if (getDays() + getNights() > 60)
	{
		salary *= 1.10;
	}
	return salary;
}
