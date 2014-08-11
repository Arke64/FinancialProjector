#include "Date.h"
#include "Entry.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
	float64 days, balance, last_balance;
	date today;

	ifstream input("Input.txt");
	input >> days >> balance >> today;

	vector<entry> entries;
	entry e;
	while (input >> e)
		entries.push_back(e);

	ofstream output("Output.csv");
	output << today << "," << balance << endl;

	last_balance = balance;

	for (word i = 0; i < days; i++) {
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

		today.add_days(1);
	}

	return 1;
}