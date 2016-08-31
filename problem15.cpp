#include <iostream>
#include <string>
#include <algorithm>
using std::string;
using std::to_string;
using std::max;
using std::cout;
using std::endl;
#include "bigint.h"

BigInt factOverNSquared(unsigned char n, unsigned char d) {
	auto product = BigInt(1);
	while (n > d) {
		product = product * n;
		n--;
	}
	auto divisor = BigInt(1);
	while (d > 0) {
		divisor = divisor * d;
		d--;
	}
	return product/divisor;
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
