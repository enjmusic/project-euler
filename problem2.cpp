#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char** argv) {
	int sum = 0;
	int nPre = 0;
	int n = 1;

	while (n < 4000000) {
		if (!(n%2)) sum += n;
		n += nPre;
		nPre = n - nPre;
	}

	cout << sum << endl;
}