#ifndef NODE_H
#define NODE_H

#include "behaviortree.h"
#include "returncode.h"

class Node
{

protected:
	BehaviorTree bt;

public:
	Node(){};
	~Node(){};

	void notify(Node){};
	ReturnCode tick(){};
	
};


#endif // NODE_H
