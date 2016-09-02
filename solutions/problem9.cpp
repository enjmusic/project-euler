#include <iostream>
#include <cmath>
using std::cout;
using std::endl;
using std::sqrt;

int main(int argc, char** argv) {
	for (int a = 1; a <= 500; a++) {
		for (int b = 1; b <= 500; b++) {
			int squaredSum = a*a + b*b;
			int c = sqrt(squaredSum);
			if (c*c == squaredSum) {
				if (a + b + c == 1000) {
					cout << a*b*c << endl;
					return 0;
				}
			}
		}
	}
}
