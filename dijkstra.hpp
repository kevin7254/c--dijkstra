#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include "node.hpp"
#include "edge.hpp"
class Dijkstra;

class Dijkstra
{
public:
	Dijkstra() = default;
	~Dijkstra() {}
	static void shortestPath(Node *n);

private:
};

#endif
