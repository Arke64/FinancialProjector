#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

vector<int> days_in_month { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

class entry {
	public:
		int day;
		int month;
		int year;
		double amount;

		int advance_amount;
		char advance_type;

		void advance() {
			switch (this->advance_type) {
				case 'd': this->day += advance_amount; break;
				case 'w': this->day += advance_amount * 14; break;
				case 'm': this->month += advance_amount; break;
				case 'y': this->year += advance_amount; break;
			}

			if (this->month > 12) {
				this->month -= 12;
				this->year++;
			}
		
			if (this->day > days_in_month[this->month]) {
				this->day -= days_in_month[this->month];
				this->month++;
			}

			if (this->month > 12) {
				this->month -= 12;
				this->year++;
			}
		}
};

vector<entry> entries;

vector<entry> find(int day, int month, int year) {
	vector<entry> today_entries;

	for (auto i : entries)
		if (i.day == day && i.month == month && i.year == year)
			today_entries.push_back(i);

	return today_entries;
}

int main(int argc, char** argv) {
	double balance, last_balance;
	double pay;
	int day, month, year;
	int next_pay_day;
	int days;

	ifstream input("Input.txt");

	input >> days >> balance >> pay >> next_pay_day >> day >> month >> year;

	entry e;
	e.amount = pay;
	e.day = next_pay_day;
	e.month = month;
	e.year = year;
	e.advance_amount = 2;
	e.advance_type = 'w';
	entries.push_back(e);

	while (input >> e.amount >> e.day >> e.month >> e.year >> e.advance_amount >> e.advance_type) {
		e.amount *= -1;

		entries.push_back(e);
	}

	last_balance = balance;

	ofstream output("Output.csv");
	output << month << "/" << day << "/" << year << "," << balance << endl;

	for (int i = 0; i < days; i++) {
		for (auto& j : entries) {
			if (j.day == day && j.month == month && j.year == year) {
				balance -= j.amount;

				j.advance();
			}
		}

		if (last_balance != balance) {
			output << month << "/" << day << "/" << year << "," << balance << endl;

			last_balance = balance;
		}

		if (++day > days_in_month[month]) {
			day = 1;
			
			if (++month > 12) {
				month = 1;
				year++;

				days_in_month[2] = (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) ? 29 : 28;
			}
		}
	}

	return 1;
}