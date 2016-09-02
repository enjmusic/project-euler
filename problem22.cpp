#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::ifstream;
#include "bigint.h"

int main(int argc, char** argv) {
	ifstream file("downloaded_files/p022_names.txt");
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

	for (auto it = names.begin(); it != names.end(); ++it) {
		cout << *it << endl;
	}
}