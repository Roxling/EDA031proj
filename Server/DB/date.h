#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
using namespace std;

class Date {
public:
	Date();                    // today's date
	Date(int y, int m, int d); // yyyy-mm-dd
	bool operator<(Date& rhs);
	time_t getSeconds();
	string print();
	
private:
	int year;  // the year (four digits)
	int month; // the month (1-12)
	int day;   // the day (1-..)
	int hour;
	int min;
	int sec;
	time_t total;
	static int daysPerMonth[12]; // number of days in each month
};



#endif
