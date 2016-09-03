//
// suffixtree.h
//
// Ian Hoffman
//
// 9/3/16
//

#ifndef SUFFIXTREE_H
#define SUFFIXTREE_H

#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::string;
using std::cout;
using std::endl;

class STNode; // Forward declaration of STNode

class STEdge {
	STNode *fork;
	int startIndex;
	int endIndex; // endIndex of -1 for current end a.k.a #
public:
	// CTOR
	STEdge(int start, int end) {
		startIndex = start;
		endIndex = end;
	}
	// DTOR
	~STEdge();

	/*
	 * OTHER FUNCTIONS
	 */

	// Accessors for start/end of label
	int getStartIndex() {
		return startIndex;
	}
	int getEndIndex() {
		return endIndex;
	}

};

class STNode {
	vector<STEdge *> edges;
public:
	// CTOR
	STNode() {
		// TO BE IMPLEMENTED !!!
		edges = {};
	}
	// DTOR
	~STNode() {
		for (auto it = edges.begin(); it != edges.end(); ++it) {
			delete *it;
		}
	}

	/*
	 * OTHER FUNCTIONS
	 */

	// Edge iterators
	auto edges_begin() {
		return edges.begin();
	}
	auto edges_end() {
		return edges.end();
	}

	// Insert edge
	void insert_edge(int start, int end) {
		edges.push_back(new STEdge(start, end));
	}

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
		root = new STNode();

		STNode *active_node = root;
		// STEdge *active_edge;
		char active_edge = '\0';
		int active_length = 0;
		int rem = 1;

		int index = 0;
		// c_end = current end a.k.a. #
		for (auto c_end = s.begin(); c_end != s.end(); ++c_end) {
			for (auto rit = active_node->edges_begin(); 
				rit != active_node->edges_end(); 
				++rit) {

				if (s[(*rit)->getStartIndex()] == *c_end) {
					active_edge = *c_end;
					active_length++;
					rem++;
					break;
				}
			}
			if (!active_length) {
				root->insert_edge(index, -1);
			}

			index++;
		}
	}
	// DTOR
	~SuffixTree() {
		delete root;
	}

	// Other functions
	void print() {
		cout << "To be implemented!" << endl;
	}

};

#endif