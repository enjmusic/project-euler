#include <iostream>
#include <ctime> // Timing implementation
#include <vector>
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

	int index = 1;
	auto prev = BigInt(0);
	auto curr = BigInt(1);
	BigInt temp;
	while (curr.numDigits() != 1000) {
		temp = curr;
		curr = curr + prev;
		prev = temp;
		index++;
	}

	duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
	cout << index << " calculated in " << duration << " seconds." << endl;
}