#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include <fstream>
#include "node.hpp"

class Graph
{
public:
	Graph();
	Graph(std::istream s) {}
	~Graph() {}

	// std::vector<std::unique_ptr<Node>> getVec() const {return vec;}
	Node *find(const std::string &find) const;
	void addNode(const std::string &ss);
	void resetVals() const;
	void printPath(const std::string&sss);

private:
	std::vector<std::unique_ptr<Node>> vec;
	//std::istream &in;
};
#endif
