#include "edge.hpp"
#include "node.hpp"
#include "nodeset.hpp"
#include "dijkstra.hpp"
#include <limits>
#include <iostream>
#include <algorithm>

void Dijkstra()
{
}

void Dijkstra::shortestPath(Node *start)
{

	start->setValue(0);
	NodeSet s;
	s.add(start);
	while (s.isEmpty() != true)
	{
		Node *n = s.removeMin();
		for (Edge e : n->getEdges())
		{
			int l = e.getLength();
			Node *d = e.getDestination();
			int a = n->getValue() + l;
			if (a < d->getValue())
			{
				d->setParent(n);
				d->setValue(a);
				s.add(d);
			}
		}
	}
}


void Dijkstra::printPath(Node* node){
	std::vector<Node*> v {};
	Node* org_node = node;
	std::string allNodes;
	while(node->getParent() != nullptr){
		v.push_back(node);
		node = node->getParent();
	}
	reverse(v.begin(), v.end());

	for(auto n : v){
		allNodes.append(n->getName() + "\n");
	}

	std::cout << "Result for " << org_node->getName() << "\n" << allNodes << org_node->getValue() <<  std::endl;


}
