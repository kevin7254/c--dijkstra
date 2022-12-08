#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include <fstream>
#include "node.hpp"

class Graph{
	public:
	Graph() = default;
	Graph(std::istream s) :in{s} {}
	~Graph() {}

	Node* find(const std::string& find) const;
	void addNode(const std::string& ss) const;
	void resetVals();

	private:
		std::vector<std::unique_ptr<Node>> vec;
		std::istream& in;
};
#endif


