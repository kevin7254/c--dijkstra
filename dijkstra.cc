#include "edge.hpp"
#include "node.hpp"
#include "nodeset.hpp"
#include <limits>

void Dijkstra(){
	Node* start;
}


void Dijkstra::shortestPath(start&){
	start.setValue(0);
	NodeSet s;
       s.add(start&);	
       while(s.isEmpty() != true){
	Node* n = s.removeMin();
	for(Edge e : n.getEdges()){
		l = e.getLength();
		d = e.getDestination();
		a = n.getValue() + l;
		if(a < d){
		d = a;
		s.add(d);
		}
	}	

       }

}
