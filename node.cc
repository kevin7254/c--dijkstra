#include "edge.hpp"
#include "node.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>

std::string Node::getName() const {
    return m_name;
}

void Node::setValue(int v) {
    value = v;
}

int Node::getValue() const {
    return value;
}

void Node::setParent(Node* p){
	parent = p;
}

Node* Node::getParent()const{
	return parent;

}

void Node::addEdge(Node* n, int i)
{
    m_edges.push_back(Edge(n, i));
}

const std::vector<Edge>& Node::getEdges() const
{
    return m_edges;
}
