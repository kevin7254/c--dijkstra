#include "graph.hpp"
#include "node.hpp"
#include "edge.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <unique_ptr>
void Graph (){

}
using namespace std::string;

void Graph(std::istream s){
	
	temp= "";
	sub = "";
	int a = 0;
	size_type pos;

	while(getline(in, temp)){
	pos = temp.find(':');
	sub = temp.substr(0, pos);
	std::unique_ptr<Node>(sub) node;
	pos = temp.find(' ');
	a = std::stoi(temp.substr(1, pos));
	sub = temp.substr(pos+1, temp.end());
	node->addEdge(sub, a);
	}	

}

Node* find(const std::string& s)const {
	for(auto a : vec){
		if(a->getName() == s){
		return a*;
		}
	}
}

void addNode(const std::string ss)const {
	vec.push_back(std::unique_ptr<Node>(ss));
}


void resetVals(){
	for(auto a : vec){
	a->setValue(Node::max_value);
	}
	

}

