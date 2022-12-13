#include <iostream>
#include <vector>
#include <string>
#include "edge.hpp"
#include "node.hpp"
#include "dijkstra.hpp"
#include "graph.hpp"
#include <cassert>

using namespace std;

int main()
{
    cout << "Hello Dijkstra fan!" << endl;


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



}
