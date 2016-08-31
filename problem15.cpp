#include <iostream>
#include <string>
using std::string;
using std::to_string;
using std::cout;
using std::endl;

// Enough of a BigInt implementation for this problem
class BigInt {
	string number;
public:
	BigInt(int i) {
		this->number = to_string(i);
	}

	void print() {
		cout << this->number << endl;
	}

	BigInt operator*(int b) {
		return *this;
	}

	BigInt operator/(int b) {
		return *this;
	}
};

BigInt factOverNSquared(unsigned char n, unsigned char d) {
	auto product = BigInt(1);
	while (n > d) {
		product = product * n;
		n--;
	}
	return product/2;
}

int main(int argc, char** argv) {
	//
	// Number of permutations in a set with 
	// 20 identical R moves and 20 identical
	// D moves:
	//
	//				40!
	//		   ------------
	//			 20! * 20!
	//

	factOverNSquared(40, 20).print();
}
