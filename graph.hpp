#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <string>
#include <iostream>

Class Graph{
	public:
	Graph() = default;
	Graph(std::istream s) :in{s} {}
	~Graph() {}

	Node* find(std::string& find);
	void addNode(std::string& ss);


	private:
		std::vector<std::unique_ptr<Node>>> vec;
		std::istream& in;
}
#endif


