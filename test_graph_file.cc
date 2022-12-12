#include <iostream>
#include <cassert>
#include "graph.hpp"
#include <algorithm>
#include <utility>
#include <set>
#include "node.hpp"
#include "edge.hpp"
#include <fstream>

using std::cout;
using std::endl;

void print_neighbours(Node* n)
{
    cout << "Anslutningar från " << n->getName() << "(" << n->getValue() << ") :\n";
    for (auto de : n->getEdges())
    {
        cout << de.getLength() << " to " << de.getDestination()->getName() << endl;
    }
}

Node *find_and_test(const std::string &s, Graph &g)
{
    Node *n = g.find(s);
    assert(n != nullptr);
    assert(n->getName() == s);
    assert(n->getValue() == Node::max_value);
    return n;
}

void test_graph()
{
    std::ifstream file("text.txt");
    if (file.is_open())
    {
        Graph g{file};
        for (auto it = g.getVec().begin(); it != g.getVec().end(); ++it)
        {
            find_and_test((*it)->getName(), g);
        }
        print_neighbours(g.find("Lund"));
        print_neighbours(g.find("Dalby"));
        print_neighbours(g.find("Sodra Sandby"));
    }

    file.close();
    cout << "test_graph passed" << endl;
}

int main()
{
    test_graph();
    return 0;
}
