#include <iostream>
using std::cout;
using std::endl;
using std::string;
#include "../headers/bigint.h"

// 1 .. 125 -> 250 -> 500 -> 1000
// 2 * 2 * 2 * 2 * 2 = 2^5
// 2^5 * 2^5 * 2^5 * 2^5 * 2^5 = 2^25
// 2^25 * 2^25 * 2^25 * 2^25 * 2^25 = 2^125

int main(int argc, char** argv) {
	auto acc = BigInt(1);
	auto mult = BigInt(2);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < (i ? 4 : 5); j++) {
			acc = acc * mult;
		}
		mult = acc;
	}
	for (int i = 0; i < 3; i++) {
		acc = acc * acc;
	}

	int sum = 0;
	string s = acc.toString();
	for (auto it = s.begin(); it != s.end(); ++it) {
		sum += (*it - '0');
	}

	cout << sum << endl;
}