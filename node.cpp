#include "node.h"


ReturnCode Conditional::tick()
{
	return predicate();
}


ReturnCode Sequence::tick()
{
	
	cout << "Sequence Tick - " << children.size() << " children" << endl;

	for (int i = 0; i < children.size(); ++i)
	{
		ReturnCode childstatus = children[i]->tick();

		currentChild = i;

		if (childstatus == ReturnCode::RUNNING)
		{
			return ReturnCode::RUNNING;
		}
		else if (childstatus == ReturnCode::FAILURE)
		{
			return ReturnCode::FAILURE;
		}
	}
	return ReturnCode::SUCCESS;

};

ReturnCode Selector::tick()
{
	
	cout << "Selector Tick - " << children.size() << " children" << endl;

	for (int i = 0; i < children.size(); ++i)
	{
		ReturnCode childstatus = children[i]->tick();
		cout << "tick" << endl;

		currentChild = i;

		if (childstatus == ReturnCode::RUNNING)
		{
			cout << "running" << endl;
			return ReturnCode::RUNNING;
		}
		else if (childstatus == ReturnCode::SUCCESS)
		{
			cout << "success" << endl;
			return ReturnCode::SUCCESS;
		}
		else
		{
			cout << "failure" << endl;
		}
	}
	cout << "failure" << endl;
	return ReturnCode::FAILURE;

};