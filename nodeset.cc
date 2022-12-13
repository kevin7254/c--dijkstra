#include "nodeset.hpp"
#include "node.hpp"
#include "edge.hpp"
#include <vector>
#include <algorithm>

void NodeSet::add(Node *node)
{
	NodeSet nodeset;
	bool nonDuplicate = true;
	for (auto i = nodelist.begin(); i != nodelist.end(); i++)
	{
		Node *n = *i;
		if (n->getName() == node->getName())
		{
			nonDuplicate = false;
		}
	}
	if (nonDuplicate)
	{
		nodelist.push_back(node);
	}
}

bool NodeSet::isEmpty()
{
	return nodelist.empty();
}

bool compareFunction(Node *a, Node *b) { return *a > *b; }

Node *NodeSet::removeMin()
{
	std::sort(nodelist.begin(), nodelist.end(), compareFunction);

	if (isEmpty())
	{
		return nullptr;
	}
	else
	{
		Node *n = nodelist.back();
		nodelist.pop_back();
		// cout << n->getName() << endl;
		return n;
	}
}
