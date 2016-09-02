#include <iostream>
#include <cmath>
using std::cout;
using std::endl;
using std::sqrt;

bool isPrime(int n) {
	if (n == 1) return false;
	if (n == 2) return true;
	if (n%2 == 0) return false;
	for (int i = 3; i <= sqrt(n); i+=2) {
		if (n%i == 0) return false;
	}
	return true;
}

int main(int argc, char** argv) {
	int primesFound = 1;
	int iter = 3;
	int latestPrime = 2;
	while (primesFound < 10001) {
		if (isPrime(iter)) {
			primesFound++;
			latestPrime = iter;
		}
		iter+=2;
	}
	cout << latestPrime << endl;
}