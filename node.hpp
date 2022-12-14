/**
 * Made by Viktor Eriksson vi2476er-s and Kevin Nilsson ke6880ni-s
 */
#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include <string>
class Edge;

class Node
{
public:
    Node() : m_name{"default"} {}
    Node(const Node &n) : m_name(n.m_name), value(n.value) {}
    Node(const std::string &name) : m_name(name), value(max_value) {}
    ~Node() { m_name = "default"; }
    /** Hämtar nodens namn. */
    std::string getName() const;

    /** Sätter nodens värde till v. */
    void setValue(int v);

    /** Hämtar nodens värde. */
    int getValue() const;

    /** Sätter parent till p. */
    void setParent(Node *p);

    /** Hämtar nodens parent. */
    Node *getParent() const;

    /** Lägger till en ny båge från denna nod till en given destination.
     * Bågen ska ha längden length. */
    void addEdge(Node *destination, int length);

    /** Hämtar de bågar som utgår från denna nod. */
    const std::vector<Edge> &getEdges() const;

    static const int max_value = 1000000;

    Node operator=(const Node &n)
    {
        m_name = n.m_name;
        value = n.value;
        return *this;
    }

    bool operator>(const Node &n)
    {
        return value > n.value;
    }

private:
    std::string m_name = "default";
    int value = max_value;
    Node *parent = nullptr;
    std::vector<Edge> m_edges = {};
};

#endif
