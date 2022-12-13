#include "edge.hpp"
#include "node.hpp"
#include "nodeset.hpp"
#include "dijkstra.hpp"
#include <limits>
#include <iostream>

void Dijkstra()
{
}

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
				cout << d->getName() << " dfjjbf " << d->getParent()->getName() << endl;
				d->setValue(a);
				s.add(d);
			}
		}
	}
	cout << s.isEmpty() << endl;
}


void Dijkstra::shortestPath(Node* start, int (*f)(Node*, Edge*))
{
	start->setValue(0);
	NodeSet s;
	s.add(start);
	while (!s.isEmpty())
	{
		Node *n = s.removeMin();
		for (Edge e : n->getEdges())
		{
			int a = f(n, &e);
			Node *d = e.getDestination();
			if (a < d->getValue())
			{
				d->setValue(a);
				d->setParent(n);
				cout << d->getName() << " dfjjbf " << d->getParent()->getName() << endl;
				s.add(d);
			}
		}
	}
}