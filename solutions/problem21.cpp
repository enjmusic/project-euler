#include <iostream>
#include <ctime> // Timing implementation
using std::clock_t;
using std::clock;
using std::cout;
using std::endl;

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

	// Starts at 220
	bool amicable[9780] = {0};
	int amicableSum = 0;
	for (int i = 220; i <= 10000; i++) {
		if (!amicable[i - 220]) {
			int sigmaDivs = sumDivisors(i);
			if (!(sigmaDivs > 10000) && sumDivisors(sigmaDivs) == i && i != sigmaDivs) {
				amicable[i - 220] = 1; 
				amicable[sigmaDivs - 220] = 1;
				amicableSum += i;
				amicableSum += sigmaDivs;
			}
		}
	}

	duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
	cout << amicableSum << " calculated in " << duration << " seconds." << endl;
}