#ifdef NODESET_HPP
#define NODESET_HPP

#include "node.hpp"
#include "edge.hpp"


class NodeSet{
public: 
	NodeSet() : {}
	~NodeSet() {};
	
	void add(Node* node);
	bool isEmpty();
	Node* removeMin();

private:

	std::vector<Node*> nodelist;	




}
