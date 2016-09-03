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
using std::pair;

class STNode; // Forward declaration of STNode

class STEdge {
	STNode *fork;
	pair<int, int> label; // label->second of -1 = current end
public:
	// CTOR
	STEdge(int start, int end) {
		label = {start, end};
	}
	// DTOR
	~STEdge();

	// Other functions

};

class STNode {
	vector<STEdge *> edges;
public:
	// CTOR
	STNode() {
		// TO BE IMPLEMENTED !!!
	}
	// DTOR
	~STNode() {
		for (auto it = edges.begin(); it != edges.end(); ++it) {
			delete *it;
		}
	}

	// Other functions

};


// STEdge DTOR (defined here, to avoid issues w/ incomplete types)
STEdge::~STEdge() {
	delete fork;
}


class SuffixTree {
	STNode *root;
public:
	// CTOR
	SuffixTree(const string &s) {

	}

	// DTOR
	~SuffixTree() {
		delete root;
	}

	// Other functions

};

#endif