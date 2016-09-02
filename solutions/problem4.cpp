#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
using std::to_string;

bool isPalindrome(const string &s) {
	int front = 0;
	int back = s.length() - 1;

	while (front < back) {
		if (s[front] != s[back]) return false;
		front++; back--;
	}

	return true;
}

int main(int argc, char** argv) {
	int maxPalindrome = 9009;
	int product;
	string s;
	for (int a = 100; a < 1000; a++) {
		for (int b = 100; b < 1000; b++) {
			product = a * b;
			s = to_string(product);
			if (isPalindrome(s) && product > maxPalindrome) {
				maxPalindrome = product;
			}
		}
	}
	cout << maxPalindrome << endl;
}