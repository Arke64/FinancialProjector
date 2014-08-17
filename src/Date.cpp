#include "Date.h"

#include <iostream>

using namespace std;

word date::month_day_counts[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

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

bool date::operator!=(const date& rhs) {
	return !(*this == rhs);
}

bool date::operator<(const date& rhs) {
	if (this->year < rhs.year)
		return true;
	else if (this->year > rhs.year)
		return false;
	else if (this->month < rhs.month)
		return true;
	else if (this->month > rhs.month)
		return false;
	else if (this->day < rhs.day)
		return true;
	else if (this->day > rhs.day)
		return false;
	else
		return false;
}

bool date::operator>(const date& rhs) {
	if (this->year > rhs.year)
		return true;
	else if (this->year < rhs.year)
		return false;
	else if (this->month > rhs.month)
		return true;
	else if (this->month < rhs.month)
		return false;
	else if (this->day > rhs.day)
		return true;
	else if (this->day < rhs.day)
		return false;
	else
		return false;
}

bool date::operator<=(const date& rhs) {
	return !(*this > rhs);
}

bool date::operator>=(const date& rhs) {
	return !(*this < rhs);
}

sword date::operator-(const date& rhs) {
	sword days = 0;
	auto right = rhs;

	while (*this < right) {
		days--;

		this->add_days(1);
	}

	while (*this > right) {
		days++;

		right.add_days(1);
	}

	return days;
}

date::date() : date(0, 0, 0) {

}

date::date(word day, word month, word year) {
	this->day = day;
	this->month = month;
	this->year = year;
}

word date::days_in_month(word month) {
	return date::month_day_counts[month - 1];
}

word date::days_in_month(word month, word year) {
	if (month == 2 && date::is_leap_year(year))
		return 29;

	return date::month_day_counts[month - 1];
}

bool date::is_leap_year(word year) {
	return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

word date::days_in_year(word year) {
	return 365 + (date::is_leap_year(year) ? 1 : 0);
}

word date::days_in_month() {
	return date::days_in_month(this->month, this->year);
}

bool date::is_leap_year() {
	return date::is_leap_year(this->year);
}

word date::days_in_year() {
	return date::days_in_year(year);
}

void date::add_days(sword count) {
	this->day += count;

	word days;
	if (this->day > (days = this->days_in_month())) {
		this->day -= days;

		if (++this->month > 12) {
			this->month = 1;
			this->year++;
		}
	}
}

void date::add_months(sword count) {
	this->month += count;

	while (this->month > 12) {
		this->month -= 12;
		this->year++;
	}
}

void date::add_years(sword count) {
	this->year += count;
}