#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char** argv) {
	int sumOfSquares = 0;
	int sumOfNums = 0;
	
	for (int i = 1; i <= 100; i++) {
		sumOfNums += i;
		sumOfSquares += i*i;
	}

	cout << sumOfNums*sumOfNums - sumOfSquares << endl;
}