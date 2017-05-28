#pragma once

#include "Date.h"

#include <iostream>

class entry {
	public:
		enum class types {
			income,
			bill,
			loan
		};

		enum class recurs_types {
			day,
			week,
			month,
			year
		};

		date occurs;
		date expires;
		double amount;

		int recurs_count;
		recurs_types recurs_type;

		double balance;
		double apr;

		types type;

		void advance();
};

std::istream& operator>>(std::istream& stream, entry& e);