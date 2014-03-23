#include <ctime>  // time and localtime
#include "date.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>

using namespace std;

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() {
	time_t timer = time(0); // time in seconds since 1970-01-01
	tm* locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
	hour = locTime->tm_hour;
	min = locTime->tm_min;
	sec = locTime->tm_sec;
}

Date::Date(int y, int m, int d) : year(y), month(m), day(d) {}

bool Date::operator<(Date& rhs){
	return false; //sort on timer in constructor
}

string Date::print(){
	return to_string(year) + "-"+to_string(month)+"-"+to_string(day)+", "+
					to_string(hour)+":"+to_string(min)+":"+to_string(sec);
}



