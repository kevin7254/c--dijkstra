#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include <vector>
#include <string>

class Node {
public:
    Node() : m_name("default") {}
    Node(const std::string& name) : m_name(name) {}
    Node() = default;
    /** Hämtar nodens namn. */
    std::string getName() const;

    /** Sätter nodens värde till v. */
    void setValue(int v);

    /** Hämtar nodens värde. */
    int getValue() const;

    /** Lägger till en ny båge från denna nod till en given destination.
     * Bågen ska ha längden length. */
    void addEdge(Node* destination, int length);

    /** Hämtar de bågar som utgår från denna nod. */
    const std::vector<Edge>& getEdges() const;
private:
    std::string m_name;
    int m_value;
    std::vector<Edge> m_edges;
};

#endif