#include "edge.hpp"
#include "node.hpp"
#include "nodeset.hpp"
#include "dijkstra.hpp"
#include <limits>
#include <iostream>

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
