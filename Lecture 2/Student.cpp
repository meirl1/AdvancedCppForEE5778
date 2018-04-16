#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Student.h"
using namespace std;


Student::Student() // : kama(0), grades(nullptr)
{
	strcpy(name, "lo yadua");
	cout << "Student nolad" << endl;
}

Student::Student(const char * shem, const double * v, int n) :Student()
{
	//size_t === unsigned int
	size_t godel = (strlen(shem) > 14) ? 14 : strlen(shem);
	strncpy(name, shem, godel);
	name[godel] = '\0';

	// make new memory allocation
	grades = new double[n];
	kama = n;
	for (int i = 0; i < n; ++i)
	{
		grades[i] = v[i];
	}
}

Student::Student(const Student& other)
{
	cout << "copy ctor " << other.name << endl;
	kama = other.kama;

	strcpy(name, other.name);

	// make new memory allocation
	grades = new double[kama];

	for (int i = 0; i < kama; ++i)
	{
		grades[i] = other.grades[i];
	}

}

Student& Student::operator=(const Student & source)
{
	cout << "assignment operator for: =  " << source.name << endl;
	
	kama = source.kama;

	strcpy(name, source.name);

	// make new memory allocation
	grades = new double[kama];

	for (int i = 0; i < kama; ++i)
	{
		grades[i] = source.grades[i];
	}
	cout << "gam nolad " << endl;

	return *this;

}

Student::~Student()
{
	cout << "tzavaat shchiv mera of: " << name << " DEAD DEAD DE..." << endl;
	if (kama)
	{
		delete[] grades;
		cout << "shuchrar: " << this->name << endl;
	}
}

void Student::print()
{
	cout << "Name is: "<< name << endl;
	for (int i = 0; i < this->kama; ++i)
	{
		cout << grades[i] << " , ";
	}
	cout << endl;
}