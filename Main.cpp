#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

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

int date::days_in_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

istream& operator>>(istream& stream, date& d) {
	stream >> d.day >> d.month >> d.year;

	return stream;
}

ostream& operator<<(ostream& stream, const date& d) {
	stream << d.month << "/" << d.day << "/" << d.year;

	return stream;
}

bool date::operator==(const date& rhs) {
	return this->day == rhs.day && this->month == rhs.month && this->year == rhs.year;
}

int date::get_days_in_month() {
	return this->get_days_in_month(this->month);
}

int date::get_days_in_month(int month) {
	if (month == 2 && (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)))
		return 29;

	return date::days_in_month[month - 1];
}

void date::add_day(int count) {
	this->day += count;

	auto days = this->get_days_in_month();
	if (this->day > days) {
		this->day -= days;

		if (++this->month > 12) {
			this->month = 1;
			this->year++;
		}
	}
}

void date::add_month(int count) {
	this->month += count;

	if (this->month > 12) {
		this->month = 1;
		this->year++;
	}
}

void date::add_year(int count) {
	this->year += count;
}


class entry {
	public:
		date occurs;
		double amount;

		int advance_amount;
		char advance_type;

		void advance();
};

istream& operator>>(istream& stream, entry& e) {
	stream >> e.amount >> e.occurs >> e.advance_amount >> e.advance_type;

	return stream;
}

void entry::advance() {
	switch (this->advance_type) {
		case 'd': this->occurs.add_day(this->advance_amount); break;
		case 'w': this->occurs.add_day(this->advance_amount * 7); break;
		case 'm': this->occurs.add_month(this->advance_amount); break;
		case 'y': this->occurs.add_year(this->advance_amount); break;
	}
}

vector<entry> entries;

int main(int argc, char** argv) {
	double days, balance, last_balance;
	date today;

	ifstream input("Input.txt");

	input >> days >> balance >> today;

	last_balance = balance;

	entry e;
	while (input >> e)
		entries.push_back(e);

	ofstream output("Output.csv");
	output << today << "," << balance << endl;

	for (int i = 0; i < days; i++) {
		for (auto& j : entries) {
			if (j.occurs == today) {
				balance += j.amount;

				j.advance();
			}
		}

		if (last_balance != balance) {
			output << today << "," << balance << endl;

			last_balance = balance;
		}

		today.add_day(1);
	}

	return 1;
}