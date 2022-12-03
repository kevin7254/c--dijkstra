#include "nodeset.hpp"
#include <vector>
#include <algorithm>

NodeSet::NodeSet(){
}


void NodeSet::add(Node* node){
bool nonDuplicate=true;
	for(Node* n: nodelist){
		if(n.getName() == node.getName()){
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

Node* NodeSet::removeMin(){
	std::sort(nodelist.begin(), nodelist.end(), getName());
	if(isEmpty()){
	return nullptr;
	}else{
	Node* n = nodelist.back();
	nodelist.pop_back();
	return n;
	}

}
