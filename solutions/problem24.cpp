#include <iostream>
#include <ctime> // Timing implementation
#include <vector>
using std::clock_t;
using std::clock;
using std::cout;
using std::endl;
using std::vector;

/*
 * 
 * Very happy with this solution, takes
 * O(n) space and O(n) time, where n is
 * the number of digits (10 here)
 *
 * For this problem, this reduces to
 * the same amount of time for any
 * convolution index, 1 through 10!
 *
 * This makes calculation significantly
 * faster than creating a 10!-length list
 * of convolutions and then sorting it
 *
 */

#define CONVOLUTION_NUMBER 1000000

// Factorial
int fact(int x) {
	return x ? x*fact(x-1) : 1;
}

int main(int argc, char** argv) {
	clock_t start;
 	double duration;
	start = clock();

	vector<int> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int toProcess = CONVOLUTION_NUMBER - 1;
	int currFact;
	for (int i = 9; i >= 0; i--) {
		currFact = fact(i);
		cout << digits[toProcess/currFact];
		digits.erase(digits.begin() + (toProcess/currFact));
		toProcess %= currFact;
	}

	duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
	cout << " calculated in " << duration << " seconds." << endl;
}