#pragma once
class Student
{
private:
	char name[15];
	double * grades =nullptr;
	int kama =0;
public:
	// constructors
	Student();
	Student(const char*, const double*, int = 7);

	// copy construcor
	Student(const Student&);

	// copy assignment operator
	Student& operator =(const Student&);

	// destructor
	~Student();

	// public methods
	void print();
};
