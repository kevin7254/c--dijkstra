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

/**
 * Graph::Graph(std::istream s)
{

	std::string temp = "";
	std::string sub = "";
	int a = 0;
	std::size_t pos;

	/**while (std::getline(s, temp))
	{
		pos = temp.find(':');
		sub = temp.substr(0, pos);
		Node node = std::unique_ptr<Node> (Node{sub});
		pos = temp.find(' ');
		a = std::stoi(temp.substr(1, pos));
		sub = temp.substr(pos + 1, temp.end());
		node->addEdge(sub, a);
	}
} */



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
