//	 ID:  1234						
//   Name: Eliezer Gensburger       
//   Lecture 2:                        
/************************************
*   DESCRIPTION:                    *
*   ------------                    *
* Student                           *
*       Constructor                 *
*       Destructor                  *
*       Copy Constructor            *
*       Assignment operator         *
*                                   *
*************************************/
#include <iostream>
#include "Student.h"
using namespace std;

void function_with_local_object();
void donothing(Student);

int main()
{
	cout << "*** constructor ***" << endl;
	function_with_local_object();
	cout << "*** destructor ***" << endl;

	double* tziyunim = new double[4]{ 45.5, 98 , 87.5, 54.49 };

	cout << "*** constructor ***" << endl;
	Student CC("gaon katan", tziyunim, 4);
	delete[] tziyunim;	// it will NOT influences the Student created above
	cout << "******" << endl;
	
	cout << "*** print ***" << endl;
	CC.print();
	cout << "******" << endl;
	
	cout << "*** copy ctor ***" << endl;
	donothing(CC);
	cout << "*** destructor ***" << endl;

	cout << "*** print ***" << endl;
	CC.print();
	cout << "******" << endl;

	cout << "*** constructor ***" << endl;
	Student *pil = new Student("lo gaon hador", new double[4]{ 100, 30, 20, 100 }, 4);
	cout << "******" << endl;

	cout << "*** print ***" << endl;
	pil->print();
	cout << "******" << endl;

	cout << "*** ctor ***" << endl;
	Student kfil;
	cout << "******" << endl;

	cout << "*** copy assignment operator ***" << endl;
	kfil = *pil;
	cout << "******" << endl;

	cout << "*** destructor *pil ***" << endl;
	delete pil;
	cout << "******" << endl;

	cout << "*** print ***" << endl;
	kfil.print();
	cout << "******" << endl;

	cout << "*** destructor CC ***" << endl;
	cout << "*** destructor kfil ***" << endl;
	cout << "******" << endl;

	//system("PauSe");
	return 0;
}

void function_with_local_object()
{
	// constructor
	Student echad;	//local object exist only in this scope
	// destructor when exiting from function
}

void donothing(Student anonimi)	//call to copy constructor
{
		//DO NOT DO ANYTHING
}	//call to destructor of the copied element

