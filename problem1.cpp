#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char** argv) {
	int sum = 0;
	int i;
	for (i = 3; i < 1000; i+=3) {
		sum += i;
	}
	for (i = 5; i < 1000; i+=5) {
		if (i%3) sum += i;
	}
	cout << sum << endl;
}