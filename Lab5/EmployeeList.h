#pragma once
#include "Employee.h"
#include "Seller.h"
#include "Technician.h"
#include <list>
#include <iostream>

using namespace std;

class EmployeeList :public list<Employee*>
{
public:
	EmployeeList();
	void pop_front();
	~EmployeeList();
};



EmployeeList::EmployeeList() :list<Employee*>()
{
}

inline void EmployeeList::pop_front()
{
	Employee* ptr = this->front();
	list<Employee*>::pop_front();
	delete ptr;
}


EmployeeList::~EmployeeList()
{
	for (auto elem : *this)
	{
		delete elem;
	}
	this->clear();
	//for (list<Employee*>::iterator itr = this->begin(); itr != this->end(); itr++)
	//{
	//	delete *itr;
	//}
}
