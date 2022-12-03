fndef EDGE_H
#define EDGE_H

#include <iostream>
#include <string>
#include "node.hpp"

using std::cout;
using std::endl;

class Edge{
public:
	Edge() :destination{"default"}, length{"default"};
	Edge(const Node* n, int i) :destination{n}, length{i} {}
	~Edge() {destination= null, length=0;}
	Edge() = default;

	Node* getDestination() const {return destination;}
	int getLength() const {return length;}
		


private:
Node* destination;
int length;
};

#endif
