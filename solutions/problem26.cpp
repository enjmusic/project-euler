#include <iostream>
#include <ctime> // Timing implementation
#include <vector>
using std::clock_t;
using std::clock;
using std::cout;
using std::endl;
using std::vector;

int main(int argc, char** argv) {
	clock_t start;
 	double duration;
	start = clock();

	int currD = 7;
	int currLongest = 6;
	for (int i = 11; i < 1000; i++) {

	}

	duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
	cout << "1/" << currD << " has cycle length of " << currLongest << ",";
	cout << " calculated in " << duration << " seconds." << endl;
}