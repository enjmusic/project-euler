//
// bigint.h
//
// Ian Hoffman
//
// 8/30/16
//

#ifndef BIGINT_H
#define BIGINT_H

using std::string;
using std::to_string;

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

	string toString() {
		return this->number;
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

	BigInt operator*(const BigInt &b) {
		auto result = BigInt();

		int place = 0;
		auto it = this->number.rbegin();
		for (; it != this->number.rend(); ++it) {
			auto thisPlace = BigInt();

			int place2 = 0;
			auto it2 = b.number.rbegin();
			for (; it2 != b.number.rend(); ++it2) {
				auto subPlace = BigInt((*it2 - '0') * (*it - '0'));

				for (int i = 0; i < place2; i++) {
					subPlace.number.push_back('0');
				}

				thisPlace = thisPlace + subPlace;
				place2++;
			}

			for (int i = 0; i < place; i++) {
				thisPlace.number.push_back('0');
			}

			result = result + thisPlace;
			place++;
		}

		return result;
	}

	bool operator<(const BigInt &b) const {
		if (this->number.length() < b.number.length()) return true;
		if (this->number.length() > b.number.length()) return false;
		return (this->number < b.number);
	}

	// bool operator>(const BigInt &b) const {
	// 	if (this->number.length() < b.number.length()) return true;
	// 	if (this->number.length() > b.number.length()) return false;
	// 	return (this->number < b.number);
	// }

	// NOT 100% EFFICIENT, JUST A TEMPORARY, WORKING VERSION
	BigInt operator/(const BigInt &b) {
		auto dummy = BigInt(0);
		auto result = BigInt(0);
		if (b.number == "0") return result;

		int figsDiff = this->number.length() - b.number.length();
		auto toAdd = BigInt(0) + b;
		for (int i = 0; i < figsDiff; i++) {
			toAdd.number.push_back('0');
		}

		while (dummy < *this) {
			if ((*this < (dummy + toAdd)) && figsDiff) {
				figsDiff--;
				toAdd.number.pop_back();
			}

			dummy = dummy + toAdd;
			auto toInc = BigInt(1);
			for (int i = 0; i < figsDiff; i++) {
				toInc.number.push_back('0');
			}
			result = result + toInc;
		}
		return result;
	}
};

#endif