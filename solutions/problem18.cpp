#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using std::vector;
using std::string;
using std::pow;
using std::cout;
using std::endl;

#define SUBTREE_SCAN_DEPTH 5

vector<vector<int>> pyramid = {

								{75},
							  {95, 64},
							{17, 47, 82},
						  {18, 35, 87, 10},
						{20,  4, 82, 47, 65},
					  {19,  1, 23, 75,  3, 34},
					{88,  2, 77, 73,  7, 63, 67},
				  {99, 65,  4, 28,  6, 16, 70, 92},
				{41, 41, 26, 56, 83, 40, 80, 70, 33},
			  {41, 48, 72, 33, 47, 32, 37, 16, 94, 29},
			{53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14},
		  {70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57},
		{91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48},
	  {63, 66,  4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31},
	{ 4, 62, 98, 27, 23,  9, 70, 98, 73, 93, 38, 53, 60,  4, 23}

};

void printPyramid(vector<vector<int>> &p) {
	cout << endl;
	int height = p.size();
	for (auto it1 = pyramid.begin(); it1 != pyramid.end(); ++it1) {
		for (int i = 0; i < height; i++) { cout << (i%2 ? "  " : " "); }
		for (auto it2 = it1->begin(); it2 != it1->end(); ++it2) {
			cout << (*it2 < 10 ? " " : "") << *it2 << " ";
		}
		cout << endl;
		height--;
	}
	cout << endl;
}

int predictUpdate(vector<vector<int>> &p, unsigned int &tier, unsigned int &x) {
	int maxSum = 0;
	unsigned int maxRoute = 0;
	unsigned int tempTier;
	unsigned int tempX;

	// 6 -> 110 -> LEFT RIGHT RIGHT, etc. thru 2^SUBTREE_SCAN_DEPTH
	unsigned int scanDepth = (SUBTREE_SCAN_DEPTH > (p.size() - tier - 1)) ? (p.size() - tier - 1) : SUBTREE_SCAN_DEPTH;
	unsigned int upperBound = (unsigned int)pow(2, scanDepth);
	for (unsigned int i = 0; i < upperBound; i++) {
		tempTier = tier;
		tempX = x;
		unsigned int bitMask = 1; // To get individual bits of i, the scan number
		int currSum = 0;
		for (unsigned int j = 0; j < scanDepth; j++) {
			// go down
			tempTier++;
			if ((i&bitMask) >> j) {
				// go right
				tempX++;
			}
			currSum += p[tempTier][tempX];
			bitMask <<= 1;
		}
		if (currSum > maxSum) {
			maxSum = currSum;
			maxRoute = i;
		}
	}

	if (!tier) maxSum += p[tier][x]; // add root of tree

	unsigned int bitMask = 1;
	for (unsigned int j = 0; j < scanDepth; j++) {
		// move references down
		tier++;
		if ((maxRoute&bitMask) >> j) {
			// move references right
			x++;
		}
		bitMask <<= 1;
	}

	return maxSum;
}

int main(int argc, char** argv) {
	printPyramid(pyramid);
	unsigned int tier = 0;
	unsigned int x = 0;
	int sum = 0;
	while (tier != pyramid.size() - 1) {
		sum += predictUpdate(pyramid, tier, x);
	}
	cout << "Greatest path: " << sum << "\n" << endl;
}