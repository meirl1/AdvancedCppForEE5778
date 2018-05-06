#include "Employee.h"
#include "Seller.h"
#include "Technician.h"
#include "EmployeeList.h"
#include <list>
#include <iostream>

using namespace std;

void printAllEmployees(list<Employee*> );

int main()
{
	Employee * emp = new Technician("temporary", 2, 5);
	emp->print();
	cout << "calling destructor after manually delete of employee *" << endl;
	delete emp;

	system("pause");

	cout << "using list<Employee*> employees " << endl;
	cout << "must delete each employee * in end of  main function" << endl << endl;

	list<Employee*> employees;
	employees.push_back(new Seller("david", 34, 3));
	employees.push_back(new Seller("shlomo", 120, 13));
	employees.push_back(new Technician("igor", 25, 25));
	employees.push_back(new Technician("grisha", 2, 5));

	printAllEmployees(employees);
	cout << "-----------------------------" << endl;

	cout << "employees.popfront() " << endl;
	Employee* ptr = employees.front();
	employees.pop_front();
	cout << "calling dtor after manually delete of employee *" << endl;
	delete ptr;

	cout << "-----------------------------" << endl;

	printAllEmployees(employees);

	cout << "calling destructor after manually delete of employee * from list" << endl;
	for (auto elem :employees)
	{
		delete elem;
	}
	cout << endl;

	cout << "using EmployeeList employeeslist " << endl;
	cout << "EmployeeList pop_front() will also delete employee* " << endl;
	cout << "dtor of EmployeeList will delete each employee* automatically" << endl;
	cout << "at end of main function" << endl << endl;


	EmployeeList employeeslist;
	employeeslist.push_back(new Seller("sara", 34, 3));
	employeeslist.push_back(new Seller("rivka", 120, 13));
	employeeslist.push_back(new Technician("rachel", 25, 25));
	employeeslist.push_back(new Technician("leah", 20, 20));
	printAllEmployees(employeeslist);
	
	cout << "employeeslist.popfront() " << endl;
	employeeslist.pop_front();

	cout << "--------------------" << endl;
	printAllEmployees(employeeslist);

	system("pause");
	return 0;
}

void printAllEmployees(list<Employee*> employees)
{
	for (Employee* emp : employees)
	{
		emp->print();
		cout << "--------------" << endl;
	}
}