#pragma once

#include "Date.h"

#include <Utilities/Common.h>

#include <iostream>

class entry {
	public:
		date occurs;
		float64 amount;

		sword advance_amount;
		int8 advance_type;

		void advance();
};

std::istream& operator>>(std::istream& stream, entry& e);