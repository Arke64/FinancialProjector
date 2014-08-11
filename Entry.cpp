#include "Entry.h"

#include <iostream>

using namespace std;

istream& operator>>(istream& stream, entry& e) {
	stream >> e.amount >> e.occurs >> e.advance_amount >> e.advance_type;

	return stream;
}

void entry::advance() {
	switch (this->advance_type) {
		case 'd': this->occurs.add_days(this->advance_amount); break;
		case 'w': this->occurs.add_days(this->advance_amount * 7); break;
		case 'm': this->occurs.add_months(this->advance_amount); break;
		case 'y': this->occurs.add_years(this->advance_amount); break;
	}
}