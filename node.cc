/**
 * Made by Viktor Eriksson vi2476er-s and Kevin Nilsson ke6880ni-s
 */
#include "edge.hpp"
#include "node.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
/* Returnerar namnet på noden */
std::string Node::getName() const
{
    return m_name;
}
/* Sätter värdet på noden till v*/
void Node::setValue(int v)
{
    value = v;
}
/* Returnerar värdet på noden*/
int Node::getValue() const
{
    return value;
}
/* Sätter parentnoden till p*/
void Node::setParent(Node *p)
{
    parent = p;
}
/* Returnerar parentnoden */
Node *Node::getParent() const
{
    return parent;
}
/* Lägger till en båge till vektorn m_edges*/
void Node::addEdge(Node *n, int i)
{
    m_edges.push_back(Edge(n, i));
}
/* returnerar vektorn m_edges med bågar*/
const std::vector<Edge> &Node::getEdges() const
{
    return m_edges;
}
