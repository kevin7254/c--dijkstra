#include "graph.hpp"
#include "node.hpp"

#include <iostream>
#include <string>
#include <vector>

void Graph (){

}

void Graph(std::istream s){
	
	std::string temp= "";
	std::string sub = "";
	std::string::size_type pos;
	while(getline(in, temp)){
	pos = temp.find(':');

	}	

}

Node* find(std::string& s){
	for(auto a : vec){
		if(a->getName() == s){
		return a*;
		}
	}
}

void addNode(std::string ss){
	vec.push_back(std::unique_ptr<Node>(ss));
}
