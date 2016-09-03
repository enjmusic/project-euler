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
	STEdge(int start, int end);
	~STEdge();

	int getStartIndex();
	int getEndIndex();
	void print(const string padding);
};

class STNode {
	vector<STEdge *> edges;
public:
	STNode();
	~STNode();

	auto edges_begin();
	auto edges_end();
	void print(const string padding);
	void insert_edge(int start, int end);
};


class SuffixTree {
	STNode *root;
public:
	SuffixTree(const string &s);
	~SuffixTree();

	void print();
};


/*
 * STEdge implementation
 */

// CTOR
STEdge::STEdge(int start, int end) {
	fork = NULL;
	startIndex = start;
	endIndex = end;
}
// DTOR
STEdge::~STEdge() {
	delete fork;
}

	/*
	 * OTHER FUNCTIONS
	 */

// Accessors for start/end of label
int STEdge::getStartIndex() {
	return startIndex;
}
int STEdge::getEndIndex() {
	return endIndex;
}

// Print edge
void STEdge::print(const string padding) {
	cout << padding << "  |- ( " << startIndex << ", ";
	cout << endIndex << " )" << endl;
	if (fork) {
		cout << padding << "    |" << endl;
		fork->print(padding + "  ");
	}
}

/*
 * END STEdge implementation
 */



/*
 * STNode implementation
 */

// CTOR
STNode::STNode() {
	// TO BE IMPLEMENTED !!!
	edges = {};
}
// DTOR
STNode::~STNode() {
	for (auto it = edges.begin(); it != edges.end(); ++it) {
		delete *it;
	}
}

	/*
	 * OTHER FUNCTIONS
	 */

// Edge iterators
auto STNode::edges_begin() {
	return edges.begin();
}
auto STNode::edges_end() {
	return edges.end();
}

// Print node
void STNode::print(const string padding) {
	for (auto rit = edges.begin(); rit != edges.end(); ++rit) {
		(*rit)->print(padding + "  ");
	}
}

// Insert edge
void STNode::insert_edge(int start, int end) {
	edges.push_back(new STEdge(start, end));
}

/*
 * END STNode implementation
 */



/*
 * SuffixTree implementation
 */

// CTOR
SuffixTree::SuffixTree(const string &s) {
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
SuffixTree::~SuffixTree() {
	delete root;
}

// Other functions
void SuffixTree::print() {
	cout << "ROOT\n  |" << endl;
	for (auto rit = root->edges_begin(); 
		rit != root->edges_end(); 
		++rit) {

		(*rit)->print("");
	}
}

/*
 * END SuffixTree implementation
 */

#endif