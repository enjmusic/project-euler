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
	long sum = 2;
	for (int i = 3; i < 2000000; i+=2) {
		if (isPrime(i)) {
			sum += i;
		}
	}
	cout << sum << endl;
}
