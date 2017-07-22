#include "node.h"


ReturnCode Conditional::tick()
{
	return predicate();
}

ReturnCode Action::tick()
{
	return action();
}

ReturnCode Sequence::tick()
{
	
	// cout << "Sequence Tick - " << children.size() << " children" << endl;

	for (int i = currentChild; i < children.size(); ++i)
	{
		ReturnCode childstatus = children[i]->tick();

		currentChild = i;

		if (childstatus == ReturnCode::RUNNING)
		{
			return ReturnCode::RUNNING;
		}
		else if (childstatus == ReturnCode::FAILURE)
		{
			currentChild = 0;
			return ReturnCode::FAILURE;
		}
	}

	currentChild = 0;
	return ReturnCode::SUCCESS;

};

ReturnCode Selector::tick()
{
	
	// cout << "Selector Tick - " << children.size() << " children" << endl;

	for (int i = currentChild; i < children.size(); ++i)
	{
		ReturnCode childstatus = children[i]->tick();
		//cout << "tick" << endl;

		currentChild = i;

		if (childstatus == ReturnCode::RUNNING)
		{
			// cout << "running" << endl;
			return ReturnCode::RUNNING;
		}
		else if (childstatus == ReturnCode::SUCCESS)
		{
			currentChild = 0;
			// cout << "success" << endl;
			return ReturnCode::SUCCESS;
		}
		
	}
	currentChild = 0;
	// cout << "failure" << endl;
	return ReturnCode::FAILURE;

};