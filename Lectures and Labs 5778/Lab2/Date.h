#pragma once
class Date
{
	//private: by default , so we comment it
	//private:
	int day;
	int month;
	int year;

	// private utility functions

	int countDigits(int) const;

public:

	//constructors and destructors

	Date();
	Date(int, int, int);
	~Date();

	// getters and setters

	int getDay() const;
	int getMonth() const;
	int getYear() const;

	void setDay(int);
	void setMonth(int);
	void setYear(int);

	// public methods

	bool checkDate(const Date&) const;	// validate Date
};
