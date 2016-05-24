#pragma once

#include <ArkeIndustries.CPPUtilities/Common.h>

#include <iostream>

class date {
	static word month_day_counts[12];

	public:
		date();
		date(word day, word month, word year);

		word day;
		word month;
		word year;

		static word days_in_month(word month);
		static word days_in_month(word month, word year);

		static bool is_leap_year(word year);
		static word days_in_year(word year);

		word days_in_month();

		bool is_leap_year();
		word days_in_year();

		void add_days(sword count);
		void add_months(sword count);
		void add_years(sword count);

		bool operator==(const date& rhs);
		bool operator!=(const date& rhs);
		bool operator<(const date& rhs);
		bool operator>(const date& rhs);
		bool operator<=(const date& rhs);
		bool operator>=(const date& rhs);

		sword operator-(const date& rhs);
};

std::istream& operator>>(std::istream& stream, date& d);
std::ostream& operator<<(std::ostream& stream, const date& d);