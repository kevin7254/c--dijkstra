#include "nodeset.hpp"
#include <vector>
#include <algorithm>

void NodeSet(){
}


void NodeSet::add(Node* node){
	NodeSet nodeset;
	bool nonDuplicate=true;
		for(std::vector<Node*>::const_iterator it=nodeset.nodelist.begin(); it!=nodelist.end(); ++it){
			Node* n = *it;
			if(n->getName() == node->getName()){
			nonDuplicate=false;
			}
		}
		if(nonDuplicate){
		nodelist.push_back(node);
		}

}

bool NodeSet::isEmpty(){
	return nodelist.empty();
}

bool compareFunction (std::string a, std::string b) {return a<b;} 

Node* NodeSet::removeMin(){
	std::sort(nodelist.begin(), nodelist.end(), compareFunction);

	if(isEmpty()) {
		return nullptr;
	} else {
		Node* n = nodelist.back();
		nodelist.pop_back();
		return n;
	}
}