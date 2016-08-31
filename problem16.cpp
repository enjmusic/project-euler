#include <iostream>
using std::cout;
using std::endl;
using std::string;
#include "bigint.h"

int main(int argc, char** argv) {
	auto acc = BigInt(1);
	auto mult = BigInt(2);
	for (int i = 0; i < 1000; i++) {
		acc = acc * mult;
	}
	int sum = 0;
	string s = acc.toString();
	for (auto it = s.begin(); it != s.end(); ++it) {
		sum += (*it - '0');
	}
	cout << sum << endl;
}