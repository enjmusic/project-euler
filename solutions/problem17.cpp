#include <iostream>
#include <map>
using std::cout;
using std::endl;
using std::string;
using std::map;

map<int, int> tens = {
	{2, 6}, // twenty
	{3, 6}, // thirty
	{4, 5}, // forty
	{5, 5}, // fifty
	{6, 5}, // sixty
	{7, 7}, // seventy
	{8, 6}, // eighty
	{9, 6}  // ninety
};

map<int, int> ones = {
	{0, 0}, // 0
	{1, 3}, // one
	{2, 3}, // two
	{3, 5}, // three
	{4, 4}, // four
	{5, 4}, // five
	{6, 3}, // six
	{7, 5}, // seven
	{8, 5}, // eight
	{9, 4}  // nine
};

map<int, int> teens = {
	{10, 3}, // ten
	{11, 6}, // eleven
	{12, 6}, // twelve
	{13, 8}, // thirteen
	{14, 8}, // fourteen
	{15, 7}, // fifteen
	{16, 7}, // sixteen
	{17, 9}, // seventeen
	{18, 8}, // eighteen
	{19, 8}  // nineteen
};

int lettersWritten(int i) {
	if (i == 1000) return 11; // "one thousand"
	int sum = 0;
	if (i > 99) {
		sum += ones[i/100] + 7; // Add 7 for "hundred"
		i %= 100;
		if (i) sum += 3; // Add 3 for "and" if values following hundreds place
	}
	if (i > 19) {
		sum += tens[i/10];
		i %= 10;
	}
	if (i > 9) {
		sum += teens[i];
		return sum;
	}
	sum += ones[i];
	return sum;
}

int main(int argc, char** argv) {
	int letterSum = 0;
	for (int i = 1; i <= 1000; i++) {
		letterSum += lettersWritten(i);
	}
	cout << letterSum << endl;
}
