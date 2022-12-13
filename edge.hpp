/**
 * Made by Viktor Eriksson vi2476er-s and Kevin Nilsson ke6880ni-s
 */
#ifndef EDGE_HPP
#define EDGE_HPP

#include <iostream>
#include <string>
#include "node.hpp"

using std::cout;
using std::endl;

class Edge
{
public:
	Edge() = default;
	Edge(Node *n, int i) : destination{n}, length{i} {}
	~Edge() { destination = nullptr, length = 0; }
	Node *getDestination() const { return destination; }
	int getLength() const { return length; }

private:
	Node *destination = nullptr;
	int length = 0;
};

#endif
