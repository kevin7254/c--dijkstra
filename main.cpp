#include <iostream>
#include <vector>
#include <string>
#include "edge.hpp"
#include "node.hpp"
#include "dijkstra.hpp"
#include "graph.hpp"
#include <cassert>

using namespace std;

int passedNodes(Node*, Edge&);
int countedChars(Node*, Edge&);

int main()
{
    cout << "Hello Dijkstra fan!" << endl << endl;


    Graph g{};

    g.addNode("Sweden");
    g.addNode("Qatar");
    g.addNode("Atlantis");
    g.addNode("Russia");
    g.addNode("Denmark");

    g.find("Sweden")->addEdge(g.find("Denmark"), 10);
    g.find("Sweden")->addEdge(g.find("Russia"), 20);

    g.find("Denmark")->addEdge(g.find("Sweden"), 10);
    g.find("Denmark")->addEdge(g.find("Russia"), 5);
    g.find("Denmark")->addEdge(g.find("Qatar"), 30);

    g.find("Russia")->addEdge(g.find("Sweden"), 20);
    g.find("Russia")->addEdge(g.find("Qatar"), 10);
    g.find("Russia")->addEdge(g.find("Denmark"), 5);

    g.find("Qatar")->addEdge(g.find("Russia"), 10);
    g.find("Qatar")->addEdge(g.find("Denmark"), 30);
    g.find("Qatar")->addEdge(g.find("Atlantis"), 20);

   g.find("Atlantis")->addEdge(g.find("Qatar"), 20);
   

   Dijkstra::shortestPathOld(g.find("Sweden"));
   Dijkstra::printPath(g.find("Qatar"));
   assert(g.find("Qatar")->getValue() == 25);

   Dijkstra::printPath(g.find("Russia"));
   assert(g.find("Russia")->getValue() == 15);

 
   g.resetVals();

	

   Dijkstra::shortestPath(g.find("Sweden"), passedNodes);
   Dijkstra::printPath(g.find("Denmark"));


   g.resetVals();

   Dijkstra::shortestPath(g.find("Sweden"), countedChars);
   Dijkstra::printPath(g.find("Atlantis"));

}
/* Räknar upp antalet noder passerade i grafen*/
int passedNodes(Node* node, Edge& e){
	
	int count =1;
	while(node->getParent() != nullptr){
		++count;
		node= node->getParent();
	}
	return count;
}
/* Räknar upp antalet tecken för varje nod i grafen
 * som man har passerat*/
int countedChars(Node* node, Edge& e){

	int count = 0;
	while(node->getParent() != nullptr){
		count += node->getName().length();
		node = node->getParent();
	}
		count += e.getDestination()->getName().length();	

	return count;


}





