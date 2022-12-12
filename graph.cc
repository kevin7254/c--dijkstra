#include "graph.hpp"
#include "node.hpp"
#include "edge.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <memory>

Graph::Graph()
{
}

Graph::Graph(std::istream& s)
{

	std::string temp = "";
	std::string ort1 = "";
	std::string ort2 = "";
	int distance = 0;
	std::size_t pos;

	while (std::getline(s, temp))
	{
		pos = temp.find(':');
		ort1 = temp.substr(0, pos);
		char const* digits = "0123456789";
		std::size_t const n = temp.find_first_of(digits);
		if (n != std::string::npos)
		{
			std::size_t const m = temp.find_first_not_of(digits, n);
			if (m != std::string::npos)
			{
				ort2 = temp.substr(n, m - n);
				distance = std::stoi(ort2);
				ort2 = temp.substr(m, temp.size() - m);
				addNode(ort1);
				addNode(ort2);
				find(ort1)->addEdge(find(ort2), distance);
				continue;
			}
		}
	}
}



Node* Graph::find(const std::string &s) const
{
	for (auto& a : vec)
	{
		if (a->getName() == s)
		{
			return a.get();
		}
	}
	return nullptr;
}

void Graph::addNode(const std::string& ss)
{
	std::unique_ptr<Node> node (new Node{ss});
	vec.push_back(std::move(node));
}

void Graph::resetVals() const
{
	for (auto &a : vec)
	{
		a->setValue(Node::max_value);
	}
}

std::vector<std::unique_ptr<Node>> const& Graph::getVec()
{
	return vec;
}