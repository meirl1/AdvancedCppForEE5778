#include "Employee.h"
#include "Seller.h"
#include "Technician.h"
#include <list>
#include <iostream>

using namespace std;
void printAllEmployees(list<Employee*> );
int main()
{
	list<Employee*> employees;
	employees.push_back(new Seller("david", 34, 3));
	employees.push_back(new Seller("shlomo", 120, 13));
	employees.push_back(new Technician("igor", 25, 25));
	employees.push_back(new Technician("grisha", 2, 5));

	printAllEmployees(employees);
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