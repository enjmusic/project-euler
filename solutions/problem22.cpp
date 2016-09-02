#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime> // Timing implementation
using std::clock_t;
using std::clock;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;

int main(int argc, char** argv) {
	clock_t start;
    double duration;
    start = clock();

	ifstream file("../downloaded_files/p022_names.txt");
	vector<string> names;
	string name;

	while (file.good()) {
		getline(file, name, ',');
		name.erase(
			remove(name.begin(), name.end(), '\"'),
			name.end()
			);
		names.push_back(name);
	}

	sort(names.begin(), names.end());
	int nameNumber = 1;
	int nameSum;
	long sum = 0;
	for (auto it = names.begin(); it != names.end(); ++it) {
		nameSum = 0;
		for (auto its = it->begin(); its != it->end(); ++its) {
			nameSum += (1 + *its - 'A');
		}
		sum += nameSum * nameNumber;
		nameNumber++;
	}

	duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
	cout << sum << " calculated in " << duration << " seconds." << endl;
}