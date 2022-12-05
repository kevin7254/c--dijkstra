#ifndef NODESET_HPP
#define NODESET_HPP

#include <vector>
#include "node.hpp"
#include "edge.hpp"



class NodeSet{
public: 
	NodeSet()=default;
	~NodeSet() {};
	void add(Node* node);
	bool isEmpty();
	Node* removeMin();
private:
	std::vector<Node*> nodelist;	
};
#endif