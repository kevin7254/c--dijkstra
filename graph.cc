#include "graph.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>


Graph::Graph(std::istream &input)
{
	//std::ifstream file("text.txt");
	// input = file;
	/*
	std::string temp= "";
	std::string sub = "";
	std::string::size_type pos;
	while(getline(in, temp)){
	pos = temp.find(':');

	}
	*/
}

const std::vector<std::unique_ptr<Node>> Graph::getVector()
{
	return vec;
}

Node *Graph::find(const std::string &s)
{
	/**
	for (auto& a : vec)
	{
		if (a->getName() == s)
			return a.get();
	}

	**/
}

void Graph::resetVals()
{
	/**
	for (auto& a : vec)
	{
		a->setValue(Node::max_value);
	}
	**/
}

void Graph::addNode(const std::string &ss)
{
	// vec.push_back(std::unique_ptr<Node>(ss));
}
