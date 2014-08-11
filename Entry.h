#pragma once

#include "Date.h"

#include <iostream>

class entry {
	public:
		date occurs;
		double amount;

		int advance_amount;
		char advance_type;

		void advance();
};

std::istream& operator>>(std::istream& stream, entry& e);