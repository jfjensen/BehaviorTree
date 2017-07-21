#ifndef BEHAVIORTREE_H
#define BEHAVIORTREE_H

#include "node.h"
#include "returncode.h"
#include <vector>

using namespace std;

class BehaviorTree
{

private:
	Node root;
	vector<Node> observers;


public:
	BehaviorTree(){};
	~BehaviorTree(){};

	void runTask(){};
	void abortTask(){};
	void subscribe(Node){};
	void notifyAll(Node){};
	ReturnCode run(){};

};

#endif // BEHAVIORTREE_H
