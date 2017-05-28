#pragma once

#include <iostream>

class date {
	static unsigned int month_day_counts[12];

	public:
		date();
		date(unsigned int day, unsigned int month, unsigned int year);

		unsigned int day;
		unsigned int month;
		unsigned int year;

		static unsigned int days_in_month(unsigned int month);
		static unsigned int days_in_month(unsigned int month, unsigned int year);

		static bool is_leap_year(unsigned int year);
		static unsigned int days_in_year(unsigned int year);

		unsigned int days_in_month();

		bool is_leap_year();
		unsigned int days_in_year();

		void add_days(int count);
		void add_months(int count);
		void add_years(int count);

		bool operator==(const date& rhs);
		bool operator!=(const date& rhs);
		bool operator<(const date& rhs);
		bool operator>(const date& rhs);
		bool operator<=(const date& rhs);
		bool operator>=(const date& rhs);

		int operator-(const date& rhs);
};

std::istream& operator>>(std::istream& stream, date& d);
std::ostream& operator<<(std::ostream& stream, const date& d);