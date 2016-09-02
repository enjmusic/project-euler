#include <iostream>
using std::cout;
using std::endl;

#define BOUND 1000000

int hailstone(long long n) {
	int ret = 0;
	while (n != 1) {
		// cout << n << endl;
		n = ((n%2) ? (3*n)+1 : n/2);
		ret++;
	}
	return ret;
}

int main(int argc, char** argv) {
	int lengths[BOUND];
	int maxCycles = 0;
	int maxValue = 0;
	int numCycles;
	for (long i = 1; i < BOUND; i++) {
		numCycles = 0;
		long n = i;
		while (n != 1) {
			if (n >= i) {
				n = ((n%2) ? (3*n)+1 : n/2);
				numCycles++;
			} else {
				numCycles += lengths[n];
				break;
			}
		}
		lengths[i] = numCycles;
		if (numCycles > maxCycles) {
			maxCycles = numCycles;
			maxValue = i;
		}
	}
	cout << maxValue << ", " << maxCycles << endl;
}
