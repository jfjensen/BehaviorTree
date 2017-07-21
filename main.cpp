
#include <iostream>
#include <string>

#include "behaviortree.h"
#include "node.h"
#include "returncode.h"


using namespace std;

ReturnCode pred()
{
	return ReturnCode::SUCCESS;
}




int main(int argc, char const *argv[])
{
	BehaviorTree bt;
	//Node nd;


	Selector *sel = new Selector();

	Node *seq_oncoming_car = new Sequence();
	sel->addChild(seq_oncoming_car);


	Node *seq_overtake = new Sequence();
	sel->addChild(seq_overtake);

	sel->tick();

	Conditional cond (pred);
	cout << (cond.tick() == ReturnCode::SUCCESS) << endl;


	cout << "code working so far" << endl;
	return 0;
}
