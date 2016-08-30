#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

int main(int argc, char** argv) {
	int product = 1;
	vector<int> multed;
	for (int i = 2; i <= 20; i++) {
		if (product%i) {
			int currRem = i;
			for (auto rit = multed.rbegin(); rit != multed.rend(); ++rit) {
				if (currRem%(*rit) == 0) currRem /= *rit;
			}
			product *= currRem;
			if (currRem > 1) multed.push_back(currRem);
		}
	}
	cout << product << endl;
}