#include <iostream>
#include <ctime> // Timing implementation
#include <vector>
using std::clock_t;
using std::clock;
using std::cout;
using std::endl;
using std::vector;

// Greatly optimized divisor summer
int sumDivisors(int n) {
	int sum = 1;
	int lowerBound = 2;
	int upperBound = n/2;
	for (int i = lowerBound; i <= upperBound; i++) {
		if (n%i == 0) {
			sum+=i;
			if (n/i == i) return sum;
			upperBound = n/i;
			sum+=upperBound;
			upperBound--;
		}
	}
	return sum;
}

int main(int argc, char** argv) {
	clock_t start;
 	double duration;
	start = clock();

	// Bool array representing ability to be represented by sum
	// of 2 abundant numbers, for natural numbers 25 - 28123
	bool rep[28098] = {0};

	// Abundant numbers 12 - 28112
	vector<short> abundants;
	for (short i = 12; i <= 28112; i++) {
		if (sumDivisors(i) > i) {
			abundants.push_back(i);
		}
	}

	// Qualify numbers through iteration
	for (auto it1 = abundants.begin(); it1 != abundants.end(); ++it1) {
		for (auto it2 = abundants.begin(); 
			(it2 != abundants.end()) && (*it1 + *it2 < 28124); ++it2) {

			rep[*it1 + *it2 - 25] = true;
		}
	}

	// Start with sum of natural numbers 1-23
	int sum = 276;
	for (int i = 25; i < 28124; i++) {
		if (!rep[i - 25]) sum += i;
	}

	duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
	cout << sum << " calculated in " << duration << " seconds." << endl;
}