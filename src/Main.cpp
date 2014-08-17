#include "Date.h"
#include "Entry.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
	float64 balance, last_balance, interest_on_balance;
	date today, end;

	ifstream input("Input.txt");
	input >> balance >> interest_on_balance >> today >> end;

	vector<entry> entries;
	entry e;
	while (input >> e)
		entries.push_back(e);

	ofstream output("Output.csv");
	output << today << "," << balance << endl;

	last_balance = balance;

	while (today < end) {
		for (auto& e : entries) {
			if (e.occurs == today && e.expires > today) {
				switch (e.type) {
					case entry::types::income: balance += e.amount; break;
					case entry::types::bill: balance -= e.amount; break;
					case entry::types::loan:
						if (e.balance == 0)
							continue;

						float64 interest_owed = e.balance * (e.apr / 12);
						float64 towards_principal = e.amount - interest_owed;

						if (e.balance < towards_principal) {
							towards_principal = e.balance;
							e.balance = 0;
						}
						else {
							e.balance -= towards_principal;
						}

						balance -= interest_owed + towards_principal;

						break;
				}

				e.advance();
			}
		}
		
		if (today.day == 1)
			balance *= 1 + (interest_on_balance / 12);

		if (last_balance != balance) {
			output << today << "," << balance << endl;

			last_balance = balance;
		}

		today.add_days(1);
	}

	return 1;
}