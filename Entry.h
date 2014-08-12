#pragma once

#include "Date.h"

#include <Utilities/Common.h>

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
		float64 amount;

		sword recurs_count;
		recurs_types recurs_type;

		float64 balance;
		float64 apr;

		types type;

		void advance();
};

std::istream& operator>>(std::istream& stream, entry& e);