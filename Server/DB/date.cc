#include <ctime>  // time and localtime
#include "date.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() {
	time_t timer = time(0); // time in seconds since 1970-01-01
	tm* locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
}

Date::Date(int y, int m, int d) : year(y), month(m), day(d) {}

int Date::getYear() const {
	return year;
}

int Date::getMonth() const {
	return month;
}

int Date::getDay() const {
	return day;
}

void Date::next() {
	day++;
	day%=daysPerMonth[month-1]+1;
	if(!day){
		day++;
		month++;
		month%=12+1;
		if(!month){
			month++;
			year++;
		}
	}
}

ostream& operator<<(ostream& lhs, const Date& rhs){
	lhs << setw(4) << setfill('0') << rhs.year << '-';
	lhs << setw(2) << setfill('0') << rhs.month << '-';
	lhs << setw(2) << setfill('0') << rhs.day;
	return lhs; 
}

istream& operator>>(istream& lhs, Date& rhs){
	string s;
	lhs >> s;
	int year = 0;
	int month = 0;
	int day = 0;
	try{
		year = stoi(s.substr(0,s.find_first_of("-")));
		month = stoi(s.substr(s.find_first_of("-")+1,s.find_last_of("-")-1-s.find_first_of("-")));
		day = stoi(s.substr(s.find_last_of("-")+1,s.length()-1));
	}catch(std::invalid_argument e){
		lhs.setstate(ios::failbit);
		return lhs;
	}
	
	if(month < 0 || month > 12){
		lhs.setstate(ios::failbit);
		
	}
	if(day < 0 || day > Date::daysPerMonth[month-1]){
		lhs.setstate(ios::failbit);
		
	}
	Date d(year,month,day);
	rhs = d;
	return lhs;
}



