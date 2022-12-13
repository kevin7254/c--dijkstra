#include "edge.hpp"
#include "node.hpp"
#include "nodeset.hpp"
#include "dijkstra.hpp"
#include <limits>
#include <iostream>
#include <algorithm>

/* Dijkstras algoritm i ett nät av noder genom dess 
 * bågar, med startnoden start*/
void Dijkstra::shortestPathOld(Node *start)
{
	start->setValue(0);
	NodeSet s;
	s.add(start);
	while (!s.isEmpty())
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
/* Printar ut namnet på noderna i den kortaste vägen 
 * baserat på dess värde. Vägen ska vara den kostaste vägen 
 * till destinationsnoden node*/
void Dijkstra::printPath(Node *node)
{
	std::vector<Node *> v{};
	Node *org_node = node;
	std::string allNodes;
	while (node->getParent() != nullptr)
	{
		v.push_back(node);
		node = node->getParent();
	}
	reverse(v.begin(), v.end());

	for (auto n : v)
	{
		allNodes.append(n->getName() + " ");
	}

	std::cout << "Result for " << org_node->getName() << ": " 
			  << allNodes << org_node->getValue() << std::endl << "\n";
}


/**
 * En generell Dijkstra-algoritm som tar en funktion som parameter.
*/
void Dijkstra::shortestPath(Node *start, int (*f)(Node *, Edge&))
{
	start->setValue(0);
	NodeSet s;
	s.add(start);
	while (!s.isEmpty())
	{
		Node *n = s.removeMin();
		for (Edge e : n->getEdges())
		{
			int a = f(n, e);
			Node *d = e.getDestination();
			if (a < d->getValue())
			{
				d->setValue(a);
				d->setParent(n);
				s.add(d);
			}
		}
	}
}
