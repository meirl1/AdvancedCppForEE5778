#include <iostream>
#include <list>  // STL
# include "Date.h"
#include "Vector.h"

using namespace std;

int testVector();
int testDate();

int main()
{
	testDate();
	testVector();

	return 0;
}

int testVector()
{
	int nums[10];
	for (int i = 0; i < 10; i++)
	{
		nums[i] = i;
	}
	Vector  vec1, 
			vec2(6), 
			vec3(4, 8), 
			vec4(nums), 
			vec5(vec3);

	cout << "vec1: ";	  
	vec1.print();

	cout << "\nvec2: ";   
	vec2.print();

	cout << "\nvec3: ";   
	vec3.print();

	cout << "\nvec4: ";   
	vec4.print();

	cout << "\nvec5: ";	 
	vec5.print();

	return 0;
}

int testDate()
{
	list<Date> mylist;		// STL container
							//
	mylist.push_back(Date(11, 3, 2018));
	Date myarray[17];

	// TO DO

	return 0;
}
