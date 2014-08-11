#pragma once

#include <iostream>

class date {
	static int days_in_month[12];

	public:
		int day;
		int month;
		int year;

		int get_days_in_month();
		int get_days_in_month(int month);

		void add_day(int count);
		void add_month(int count);
		void add_year(int count);

		bool operator==(const date& rhs);
};

std::istream& operator>>(std::istream& stream, date& d);
std::ostream& operator<<(std::ostream& stream, const date& d);