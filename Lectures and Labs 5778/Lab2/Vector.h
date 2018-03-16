#pragma once
class Vector
{
private:
	int *numbers;
	int size;
public:
	Vector(int sizeVec = 10);
	Vector(int val, int sizeVec);
	Vector(int* vec, int sizeVec = 10);
	Vector(const Vector&);
	~Vector();
	void print() const;
};

