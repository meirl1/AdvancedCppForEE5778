#include "Set2.h"
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;


int * Set2::sortedarray() const
{
	int * sorted = new int[size];
	memcpy(sorted, data, size * sizeof(int));
	sort(sorted, sorted + size);
	return sorted;
}

Set2::Set2():data(nullptr),size(0)
{
}

Set2::Set2(int * data,int size):size(size)
{
	if (size)
	{
		data = new int[size];
		memcpy(this->data, data, size * sizeof(int));
	}
	else
	{
		throw "size must more than 0 ";
	}
}

Set2::Set2(const Set2 & other):size(other.size)
{
	if (size)
	{
		data = new int[size];
		memcpy(this->data, other.data, size * sizeof(int));
	}
}

Set2 & Set2::operator=(const Set2 & other)
{
	if (size)
	{
		delete[] data;
	}
	size = other.size;
	if (size)
	{
		data = new int[size];
		memcpy(this->data, other.data, size * sizeof(int));
	}
}

void Set2::operator+=(const int & value)
{
	it = find(data.begin(), data.end(), value);
	if (it == data.end())
	{
		int* temp = new int[size + 1];
		temp[size] = value;
		delete[] data;
		data = temp;
		++size;
	}
}

Set2 Set2::operator+(const Set2 & other) const
{
	int* buffer = new int[size + other.size]; // maximum size that can be for operation
	/*************** only with dynamic int* ***********************/
	//classic merge
	int * temp1 = sortedarray();
	int* temp2 = other.sortedarray();

	int *it1 = temp1,
		*it2 = temp2,
		*end1 = temp1 + size,
		*end2 = temp2 + othe.size;

	while (it1 < end1 && j < end2)
	{
		if (*it1 < *it2)
		{
			buffer[newsize++] = *it1;
			++it1;
		}
		else if (*it2 < *it1)
		{
			buffer[newsize++] = *it2;
			++it2;
		}
		else
		{
			buffer[newsize++] = *it1;
			++it1;
			++it2;
		}
	}
	while (it1 != end1)
	{
		buffer[newsize++] = *it1;
		++it1;
	}
	while (it2 != end2)
	{
		buffer[newsize++] = *it1;
		++it2;
	}

	int * newvec = new int[newsize];
	memcpy(newvec, buffer, newsize * sizeof(int));
	delete[] buffer;

	return Set2(newvec,newsize);

}

Set2 Set2::operator-(const Set2 & other) const
{
	int* buffer = new int[size]; // maximum size that can be for operation
	
	/*************** only with dynamic int* ***********************/
	//classic merge
	
	int * temp1 = sortedarray();
	int * temp2 = other.sortedarray();

	int size1 = size, 
		size2 = other.size,
		newsize = 0;

	if (size1 < size2)
	{
		int * swap = temp1;
		int temp = size1;

		temp1 = temp2;
		size1 = size2;

		temp2 = swap;
		size2 = temp;
	}

	int *end1 = temp1 + size1,
		*end2 = temp2 + size2;


	/****************** using set_intersection **************
	set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(result));
	**********************************************************/
	// not using set_intersection but binary_search:
	for(auto i = temp1; i != end1; i++)
	{
		if (binary_search(temp2, end2, *i))
		{
			buffer[newsize++] = *i;
		}
	}

	int * newvec = new int[newsize];
	memcpy(newvec, buffer, newsize * sizeof(int));
	delete[] buffer;

	return Set2(newvec,newsize);
}


Set2::~Set2()
{
	if (size)
	{
		delete[] data;
	}
}

ostream & operator<<(ostream & out, const Set2 & set)
{
	int * it = set.data,
		*end = set.data + size -1;

	while(it != end)
	{
		out << *it << ',';
		++it;
	}
	out << *it; //last element

	return out;

}
