#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include "node.hpp"
#include "edge.hpp"
class Dijkstra;


class Dijkstra {
	public:
		Dijkstra() = default;
		Dijkstra(Node* n) : start(n) {}
		~Dijkstra() {start = nullptr;}	
		void shortestPath();


	private:
		Node* start;
	



};

#endif
