#include <ctime>  // time and localtime
#include "date.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <sys/time.h>

using namespace std;

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() {
	total = time(0); // time in seconds since 1970-01-01
	tm* locTime = localtime(&total); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
	hour = locTime->tm_hour;
	min = locTime->tm_min;
	sec = locTime->tm_sec;

	struct timeval tp;
	gettimeofday(&tp,NULL);
	millis = tp.tv_sec * 1000 + tp.tv_usec / 1000;
}

Date::Date(int y, int m, int d) : year(y), month(m), day(d) {}

bool Date::operator<(const Date& rhs) const{
	return millis<rhs.millis; //sort on timer in constructor
}

long int Date::getMillis(){
	return millis;
}

time_t Date::getSeconds(){
	return total;
}

string Date::print(){
	return to_string(year) + "-"+to_string(month)+"-"+to_string(day)+", "+
					to_string(hour)+":"+to_string(min)+":"+to_string(sec);
}



