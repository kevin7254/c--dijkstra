#ifndef EDGE_HPP
#define EDGE_HPP

#include <iostream>
#include <string>
#include "node.hpp"

using std::cout;
using std::endl;

class Edge{
public:
	Edge() :destination{}, length{1}{};
	Edge(Node* n, int i) :destination{n}, length{i} {}
	~Edge() {destination= nullptr, length=0;}
	Node* getDestination() const {return destination;}
	int getLength() const {return length;}
private:
Node* destination;
int length;
};

#endif
