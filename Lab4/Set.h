#pragma once
#include<vector>
#include <iostream>
#include <algorithm>
using namespace std;
//Set using vector for data container
class Set
{
	vector<int> data;
public:
	Set();
	Set(const vector<int>& otherdata);
	Set(const Set& source);
	Set& operator=(const Set& source);
	void operator+=(const int& value);
	Set operator+(const Set& other)const;
	Set operator-(const Set& other)const;
	friend  ostream& operator<<(ostream& out, const Set& set);
	~Set();
};

