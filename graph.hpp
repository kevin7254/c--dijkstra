#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <string>
#include <iostream>
#include "node.hpp"
#include <fstream>

class Graph
{
public:
	Graph() = default;
	Graph(std::istream& in);
	~Graph();
	Node *find(const std::string &find);
	void addNode(const std::string &ss);
	void resetVals();
	const std::vector <std::unique_ptr<Node>> getVector();
private:
	const std::vector <std::unique_ptr<Node>> vec;
};

#endif