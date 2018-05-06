#pragma once
#include <iostream>
#include <cstring> //alias <string.h>
using namespace std;

class Employee
{
	char * name;
	int daysMonthly;
	int nightMonthly;

public:
	Employee(const char* name,int days,int nights);
	Employee(const Employee& other);
	const Employee & operator = (const Employee& other);

	int getDays()const;
	int getNights()const;
	const char* getName() const;
	void print()const
	{
		cout << "Employee Name: " << getName() << endl;
		this->printDetails();
	}

	virtual void printDetails() const = 0;
	virtual double calcSalary() const = 0;

	virtual ~Employee();
};

inline Employee::Employee(const char * _name,int days,int nights):name(_strdup(_name)),daysMonthly(days),nightMonthly(nights)
{
	 //this_name = new char[strlen(_name)+1];
	 //this->name = strcpy(_name);

	 //this->daysMonthlyHours = days;
	 //this->nightMonthlyHours = nights;
}

 Employee::Employee(const Employee & other):name(nullptr)
 {
	 *this = other;
 }

 const Employee & Employee::operator=(const Employee & other)
 {
	 if (this != &other)
	 {
		 //if name == nullptr then delete[]name will do nothing
		 delete[] name;
		 name = _strdup(other.name);
		 daysMonthly = other.daysMonthly;
		 nightMonthly = other.nightMonthly;
	 }
	 return *this;
 }

 
 inline int Employee::getDays()const
 {
	 return daysMonthly;
 }

 inline int Employee::getNights()const
 {
	 return nightMonthly;
 }

 inline const char * Employee::getName() const
 {
	 return name;
 }

Employee::~Employee()
{
	if (name)
	{
		cout << "employee: " << name << " destroyed." << endl;
		delete[]name;
	}
	else
	{
		cout << "destroying zombie " << endl;
	}
}
