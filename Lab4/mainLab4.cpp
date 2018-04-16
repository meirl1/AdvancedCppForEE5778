#include <iostream>
#include <string>
#include "Set.h"
using namespace std;

int main()
{
	cout << "Sets" << endl;
	try
	{
		Set s1, s2, s3;
		for (int i = 1; i <= 10; i++)
			s1 += i;  // s1 = 1,2,3,4,5,6,7,8,9,10
		cout << s1 << endl;
		for (int i = 1; i <= 15; i += 2)
			s2 += i; // s2 = 1,3,5,7,9,11,13,15
		cout << s2 << endl;
		
		s3 = s1 + s2;	  // s3 = 1,2,3,4,5,6,7,8,9,10,11,13,15
		cout << s3 << endl;     //  1,2,3,4,5,6,7,8,9,10,11,13,15 הדפסת   
		s3 = s1 - s2;   // s3 = 1,3,5,7,9
		cout << s3 << endl;     // 1,3,5,7,9הדפסת   
	}
	catch (string errmsg)
	{
		cout << "an error has occurred: " << errmsg << endl;
	}
	system("paUSE");
	return 0;
}
