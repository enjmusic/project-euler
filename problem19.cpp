#include <iostream>
using std::cout;
using std::endl;

char lengths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(int argc, char** argv) {
	int sum = 0;
	int year = 1901;
	int days = 366;
	while (year != 2001) {
		for (int i = 0; i < 12; i++) {
			// if (days%7 == 0), it's a Sunday
			if (days%7 == 0) sum++;
			days += lengths[i];
			// Leap year logic
			if (i == 1 && year%4 == 0 && !(year%100 == 0 && year%400 != 0)) {
				days++;
			}
		}
		year++;
	}
	cout << sum << endl;
}