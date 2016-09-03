//
// suffixtree.h
//
// Ian Hoffman
//
// 9/3/16
//

#ifndef SUFFIXTREE_H
#define SUFFIXTREE_H

#include <vector>
#include <string>
using std::vector;
using std::string;

class STNode; // Forward declaration of STNode

class STEdge {
	STNode *fork;
public:

};

class STNode {

public:

};

class SuffixTree {
	STNode *root;
public:
	// CTORs
	SuffixTree() {

	}

	SuffixTree(const string &s) {

	}

	// DTOR
	~SuffixTree() {

	}

	// Other functions
};

#endif