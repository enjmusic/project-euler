#include <iostream>
#include <string>
#include <algorithm>
using std::string;
using std::to_string;
using std::max;
using std::cout;
using std::endl;

// Enough of a BigInt implementation for this problem
class BigInt {
	string number;
public:
	BigInt() {
		this->number = "";
	}

	BigInt(int i) {
		this->number = to_string(i);
	}

	void print() {
		cout << this->number << endl;
	}

	BigInt operator+(const BigInt &b) {
		auto result = BigInt();

		auto thisIter = this->number.rbegin();
		auto otherIter = b.number.rbegin();

		int sum = 0;
		do {
			if (thisIter != this->number.rend()) {
				sum += (*thisIter - '0');
				thisIter++;
			}
			if (otherIter != b.number.rend()) {
				sum += (*otherIter - '0');
				otherIter++;
			}

			result.number.push_back(sum%10 + '0');
			sum /= 10;
		} while (sum || 
			thisIter != this->number.rend() ||
			otherIter != b.number.rend());

		// Remove extra zeroes 
		// while (result.number.back() == 0) {
		// 	result.number.pop_back();
		// }

		string reversed;
		for (auto it = result.number.rbegin(); it != result.number.rend(); ++it) {
			reversed.push_back(*it);
		}
		result.number = reversed;

		return result;
	}

	BigInt operator*(int b) {
		auto result = BigInt();

		int place = 0;
		auto it = this->number.rbegin();
		for (; it != this->number.rend(); ++it) {
			auto thisPlace = BigInt((*it - '0') * b);
			for (int i = 0; i < place; i++) {
				thisPlace.number.push_back('0');
			}

			result = result + thisPlace;
			place++;
		}

		return result;
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

	// factOverNSquared(40, 20).print();
	// (BigInt(29) + BigInt(11)).print();
	(BigInt(21) * 3).print();
}
