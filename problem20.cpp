#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
#include "bigint.h"

int main(int argc, char** argv) {
	auto n = BigInt(2);
	for (int i = 3; i <= 100; i++) {
		n = n * BigInt(i);
	}
	auto v = n.toVector();
	int sum = 0;
	for (auto it = v.begin(); it != v.end(); ++it) {
		sum += *it;
	}
	cout << "100! = "; n.print();
	cout << "Sum of its digits: " << sum << endl;
}