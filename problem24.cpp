#include <iostream>
#include <ctime> // Timing implementation
#include <vector>
using std::clock_t;
using std::clock;
using std::cout;
using std::endl;
using std::vector;

// Factorial
int fact(int x) {
	return x ? x*fact(x-1) : 1;
}

int main(int argc, char** argv) {
	clock_t start;
 	double duration;
	start = clock();

	vector<int> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int toProcess = 999999;
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