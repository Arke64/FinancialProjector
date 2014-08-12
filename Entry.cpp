#include "Entry.h"

#include <iostream>

using namespace std;

istream& operator>>(istream& stream, entry& e) {
	int8 type, recurs_type;

	stream >> type >> e.amount >> e.occurs >> e.recurs_count >> recurs_type;

	switch (type) {
		case 'i': e.type = entry::types::income; break;
		case 'b': e.type = entry::types::bill; break;
		case 'l': 
			e.type = entry::types::loan; 

			stream >> e.balance >> e.apr;
		
			break;
	}

	switch (recurs_type) {
		case 'd': e.recurs_type = entry::recurs_types::day; break;
		case 'w': e.recurs_type = entry::recurs_types::week; break;
		case 'm': e.recurs_type = entry::recurs_types::month; break;
		case 'y': e.recurs_type = entry::recurs_types::year; break;
	}

	//this->expired = false;

	return stream;
}

void entry::advance() {
	switch (this->recurs_type) {
		case recurs_types::day: this->occurs.add_days(this->recurs_count); break;
		case recurs_types::week: this->occurs.add_days(this->recurs_count * 7); break;
		case recurs_types::month: this->occurs.add_months(this->recurs_count); break;
		case recurs_types::year: this->occurs.add_years(this->recurs_count); break;
	}
}