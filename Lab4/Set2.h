#pragma once
class Set2
{
	int *data;
	int size;
	int* sortedarray() const;
public:
	Set2();
	Set2(int* data,int size);
	Set2(const Set2& other);
	Set2& operator=(const Set2& other);
	void operator+=(const int& value);
	Set2 operator+(const Set2& other)const;
	Set2 operator-(const Set2& other)const;
	friend  ostream& operator<<(ostream& out, const Set2& set);
	~Set2();
};

