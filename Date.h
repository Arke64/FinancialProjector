#pragma once

#include <Utilities/Common.h>

#include <iostream>

class date {
	static word days_in_month[12];

	public:
		word day;
		word month;
		word year;

		word get_days_in_month();
		word get_days_in_month(word month);

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
};

std::istream& operator>>(std::istream& stream, date& d);
std::ostream& operator<<(std::ostream& stream, const date& d);
