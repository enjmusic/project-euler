//
// bigint.h
//
// Ian Hoffman
//
// 8/30/16
//

#ifndef BIGINT_H
#define BIGINT_H

#include <vector>
#include <string>
using std::vector;
using std::string;
using std::cout;
using std::endl;

// Enough of a BigInt implementation for this problem
class BigInt {
	vector<int> num;
public:
	BigInt() {
		this->num = {};
	}

	BigInt(int i) {
		this->num = {};
		vector<int> rev = {};
		while (i) {
			rev.push_back(i%10);
			i /= 10;
		}
		for (auto it = rev.rbegin(); it != rev.rend(); ++it) {
			this->num.push_back(*it);
		}
	}

	string toString() {
		string out;
		for (auto it = this->num.begin(); it != this->num.end(); ++it) {
			out.push_back(*it + '0');
		}
		return out;
	}

	vector<int> toVector() {
		return num;
	}

	int numDigits() {
		return num.size();
	}

	void print() {
		for (auto it = this->num.begin(); it != this->num.end(); ++it) {
			cout << *it;
		}
		cout << endl;
	}

	BigInt operator+(const BigInt &b) {
		auto result = BigInt();

		auto thisIter = this->num.rbegin();
		auto otherIter = b.num.rbegin();

		int sum = 0;
		do {
			if (thisIter != this->num.rend()) {
				sum += *thisIter;
				thisIter++;
			}
			if (otherIter != b.num.rend()) {
				sum += *otherIter;
				otherIter++;
			}

			result.num.push_back(sum%10);
			sum /= 10;
		} while (sum || 
			thisIter != this->num.rend() ||
			otherIter != b.num.rend());

		vector<int> reversed;
		for (auto it = result.num.rbegin(); it != result.num.rend(); ++it) {
			reversed.push_back(*it);
		}
		result.num = reversed;

		return result;
	}

	BigInt operator*(const BigInt &b) {
		auto result = BigInt();

		int place = 0;
		auto it = this->num.rbegin();
		for (; it != this->num.rend(); ++it) {
			auto thisPlace = BigInt();

			int place2 = 0;
			auto it2 = b.num.rbegin();
			for (; it2 != b.num.rend(); ++it2) {
				auto subPlace = BigInt((*it) * (*it2));

				for (int i = 0; i < place2; i++) {
					subPlace.num.push_back(0);
				}

				thisPlace = thisPlace + subPlace;
				place2++;
			}

			for (int i = 0; i < place; i++) {
				thisPlace.num.push_back(0);
			}

			result = result + thisPlace;
			place++;
		}

		return result;
	}

	bool operator<(const BigInt &b) const {
		if (this->num.size() < b.num.size()) return true;
		if (this->num.size() > b.num.size()) return false;
		auto it1 = this->num.begin();
		auto it2 = b.num.begin();
		while (it1 != this->num.end()) {
			if (*it1 > *it2) {
				return false;
			}
			if (*it1 < *it2) {
				return true;
			}
			it1++; it2++;
		}
		return false;
	}

	// NOT 100% EFFICIENT, JUST A TEMPORARY, WORKING VERSION
	BigInt operator/(const BigInt &b) {
		auto dummy = BigInt(0);
		auto result = BigInt(0);
		if (!b.num.size()) return result;

		int figsDiff = this->num.size() - b.num.size();
		auto toAdd = BigInt(0) + b;
		for (int i = 0; i < figsDiff; i++) {
			toAdd.num.push_back(0);
		}

		while (dummy < *this) {
			if ((*this < (dummy + toAdd)) && figsDiff) {
				figsDiff--;
				toAdd.num.pop_back();
			}

			dummy = dummy + toAdd;
			auto toInc = BigInt(1);
			for (int i = 0; i < figsDiff; i++) {
				toInc.num.push_back(0);
			}
			result = result + toInc;
		}
		return result;
	}
};

#endif