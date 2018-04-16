#include "Set.h"
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;

Set::Set(const vector<int>& otherdata)
{
	if(otherdata.size())
	{
		data.assign(otherdata.begin(), otherdata.end());
	}
}

Set::Set(const Set & source)
{
	data.assign(source.data.begin(), source.data.end());
}

Set & Set::operator=(const Set & source)
{
	data.resize(0);
	data.assign(source.data.begin(), source.data.end());
	return *this;
}

void Set::operator+=(const int & value)
{
	vector<int>::iterator it;

	it = find(data.begin(), data.end(), value);
	if (it == data.end())
	{
		data.push_back(value);
	}
}

Set Set::operator+(const Set & other)const
{
	vector<int> newvec;
	/************************* using unorderd_set **********************
	// from https://stackoverflow.com/questions/1041620/whats-the-most-efficient-way-to-erase-duplicates-and-sort-a-vector
	// and  https://stackoverflow.com/questions/17294629/merging-flattening-sub-vectors-into-a-single-vector-c-converting-2d-to-1d

	// unordered_set: this is a set with unique values but unordered
	unordered_set<int> s;
	for (auto it = data.begin(); it != data.end(); ++it)
	{
		s.insert(*it);
	}
	for (auto it = other.data.begin(); it != other.data.end(); ++it)
	{
		s.insert(*it);
	}
	//for (int i : other.data)
	//{
	//	s.insert(i);
	//}
	newvec.assign(s.begin(), s.end());
	sort(newvec.begin(), newvec.end());

	**********************************************************/
	// we can also use set_union
	// http://www.cplusplus.com/reference/algorithm/set_union/
	// from https://github.com/lemire/Code-used-on-Daniel-Lemire-s-blog/blob/master/2017/01/27/setunionintersection.cpp
	//  set_union(v1.begin(), v1.end(), v2.begin(), v2.end(),	std::back_inserter(v));

	/*************** only with vectors ***********************/
	//classic merge
	vector<int> temp1(data);
	vector<int> temp2(other.data);
	sort(temp1.begin(), temp1.end());
	sort(temp2.begin(), temp2.end());
	auto it1 = temp1.begin();
	auto it2 = temp2.begin();
	while (it1 != temp1.end() && it2 != temp2.end())
	{
		if (*it1 < *it2)
		{
			newvec.push_back(*it1);
			++it1;
		}
		else if (*it2 < *it1)
		{
			newvec.push_back(*it2);
			++it2;
		}
		else
		{
			newvec.push_back(*it1);
			++it1;
			++it2;
		}
	}
	while (it1 != temp1.end())
	{
		newvec.push_back(*it1);
		++it1;
	}
	while (it2 != temp2.end())
	{
		newvec.push_back(*it2);
		++it2;
	}

	return Set(newvec);
}

Set Set::operator-(const Set & other)const
{
	if (data.empty())
	{
		throw ("empty data");
	}
	//from https://github.com/lemire/Code-used-on-Daniel-Lemire-s-blog/blob/master/2017/01/27/setunionintersection.cpp

	vector<int> result;
	vector<int> v1(data);
	vector<int> v2(other.data);
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	/****************** using set_intersection **************
	set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(result));
	**********************************************************/
	// not using set_intersection but binary_search:
	if (v1.size() < v2.size())
	{
		swap(v1, v2);
	}
	for (auto i = v1.begin(); i != v1.end(); i++)
	{
		if ( binary_search(v2.begin(), v2.end(), *i))
		{
			result.push_back(*i);
		}
	}

	return Set(result);
}

Set::Set()
{
	//nothing to do
}


Set::~Set()
{
	//nothing to do
}

ostream & operator<<(ostream & out, const Set & set)
{
	for(auto it = set.data.begin();it != set.data.end();++it)
	{
		out << *it;
		if (next(it, 1) != set.data.end())
		{
			out << ',';
		}		
	}
	return out;
}
