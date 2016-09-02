#include <iostream>
#include <vector>
#include <ctime> // Timing implementation
using std::clock_t;
using std::clock;
using std::cout;
using std::endl;
using std::vector;
#include "../headers/bigint.h"

int main(int argc, char** argv) {
	clock_t start;
 	double duration;
	start = clock();

	auto n = BigInt(2);
	for (int i = 3; i <= 100; i++) {
		n = n * BigInt(i);
	}
	auto v = n.toVector();
	int sum = 0;
	for (auto it = v.begin(); it != v.end(); ++it) {
		sum += *it;
	}

	duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
	cout << "100! = "; n.print();

	cout << "Sum of its digits: " << sum;
	cout << " calculated in " << duration << " seconds." << endl;
}