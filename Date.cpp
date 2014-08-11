#include "Date.h"

#include <iostream>

using namespace std;

int date::days_in_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

istream& operator>>(istream& stream, date& d) {
	stream >> d.day >> d.month >> d.year;

	return stream;
}

ostream& operator<<(ostream& stream, const date& d) {
	stream << d.month << "/" << d.day << "/" << d.year;

	return stream;
}

bool date::operator==(const date& rhs) {
	return this->day == rhs.day && this->month == rhs.month && this->year == rhs.year;
}

int date::get_days_in_month() {
	return this->get_days_in_month(this->month);
}

int date::get_days_in_month(int month) {
	if (month == 2 && (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)))
		return 29;

	return date::days_in_month[month - 1];
}

void date::add_day(int count) {
	this->day += count;

	auto days = this->get_days_in_month();
	if (this->day > days) {
		this->day -= days;

		if (++this->month > 12) {
			this->month = 1;
			this->year++;
		}
	}
}

void date::add_month(int count) {
	this->month += count;

	if (this->month > 12) {
		this->month = 1;
		this->year++;
	}
}

void date::add_year(int count) {
	this->year += count;
}