#include <iostream>
using std::cout;
using std::endl;

// Greatly optimized divisor counter
int numDivisors(unsigned long n) {
	int ret = 1;
	unsigned long lowerBound = 2;
	unsigned long upperBound = n/2;
	for (unsigned long i = lowerBound; i <= upperBound; i++) {
		if (n%i == 0) {
			ret++;
			if (n/i == i) return ret;
			ret++;
			upperBound = n/i;
		}
	}
	return ret;
}

int main(int argc, char** argv) {
	unsigned long currNum = 1;
	for (int i = 2; numDivisors(currNum) <= 500; i++) { currNum += i; }
	cout << currNum << endl;
}
