#include <iostream>
#include <cmath>
using std::cout;
using std::endl;
using std::sqrt;

int main(int argc, char** argv) {
	int maxPrimeFactor = 1;
	unsigned long n = 600851475143;

	if (n%2 == 0) maxPrimeFactor = 2;
	while (n%2 == 0) { n /= 2; }

	for (int i = 3; i < sqrt(n); i+=2) {
		if (n%i == 0) maxPrimeFactor = i;
		while (n%i == 0) { n /= i; }
	}

	if (n>(unsigned int)maxPrimeFactor) maxPrimeFactor = n;
	cout << maxPrimeFactor << endl;
}