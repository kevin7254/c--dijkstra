#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include "node.hpp"
#include "edge.hpp"

class Dijkstra
{
public:
	Dijkstra() = default;
	~Dijkstra() {}
	static void printPath(Node* node);
	static void shortestPathOld(Node *n);
	static void shortestPath(Node* start, int (*f)(Node*, Edge&));

private:

};

#endif
