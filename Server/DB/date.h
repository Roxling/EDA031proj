#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date {
friend ostream& operator<<(ostream& lhs, const Date& rhs);
friend istream& operator>>(istream& lhs, Date& rhs);
public:
	Date();                    // today's date
	Date(int y, int m, int d); // yyyy-mm-dd
	int getYear() const;       // get the year
	int getMonth() const;      // get the month
	int getDay() const;        // get the day
	void next();               // advance to next day
private:
	int year;  // the year (four digits)
	int month; // the month (1-12)
	int day;   // the day (1-..)
	static int daysPerMonth[12]; // number of days in each month
};

ostream& operator<<(ostream& lhs, const Date& rhs);
istream& operator>>(istream& lhs, Date& rhs);

#endif
