#include <iostream>
#include <ctime> // Timing implementation
#include <string>
#include <vector>
using std::clock_t;
using std::clock;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::pair;
using std::to_string;

int main(int argc, char** argv) {
	clock_t start;
 	double duration;
	start = clock();

	int currD = 7;
	int currLongest = 6;
	// for (int i = 11; i < 1000; i++) {
	// 	string currDecimal;
	// 	int proc = 10;
	// 	for (int j = 0; j < 200 && proc; j++) {
	// 		if (proc < i) {
	// 			proc *= 10;
	// 			currDecimal.push_back('0');
	// 		} else {
	// 			currDecimal.push_back('0' + proc/i);
	// 			proc %= i;
	// 		}
	// 	}
	// 	cout << "1/" << i << " = 0." << currDecimal << endl;
	// 	cout << endl;
	// 	string placements[10] = {"", "", "", "", "", "", "", "", "", ""};
	// 	int index = 0;
	// 	for (auto it = currDecimal.begin(); it != currDecimal.end(); ++it) {
	// 		placements[*it - '0'] += to_string(index) + " ";
	// 		index++;
	// 	}
	// 	for (int i = 0; i < 10; i++) {
	// 		cout << i << ": " << placements[i] << endl;
	// 	}
	// }

	string a = "238729836754729363748436834787878787837427643325236622247827857825782578252069";
	cout << "0." << a << endl;
	vector<int> placements[10] = {};
	int index = 0;
	for (auto it = a.begin(); it != a.end(); ++it) {
		placements[*it - '0'].push_back(index);
		index++;
	}
	cout << "Indices: " << endl;
	for (int i = 0; i < 10; i++) {
		cout << i << ": ";
		for (auto it = placements[i].begin(); it != placements[i].end(); ++it) {
			cout << *it << " ";
		}
		cout << endl;
	}
	vector<int> spacings[10] = {};
	for (int i = 0; i < 10; i++) {
		int prevIndex = 0;
		for (auto it = placements[i].begin(); it != placements[i].end(); ++it) {
			if (it != placements[i].begin()) {
				spacings[i].push_back(*it - prevIndex);
				prevIndex = *it;
			}
		}
	}
	cout << "Spacings: " << endl;
	for (int i = 0; i < 10; i++) {
		cout << i << ": ";
		for (auto it = spacings[i].begin(); it != spacings[i].end(); ++it) {
			cout << *it << " ";
		}
		cout << endl;
	}



	duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
	cout << "1/" << currD << " has cycle length of " << currLongest << ",";
	cout << " calculated in " << duration << " seconds." << endl;
}