#include "action.h"

ReturnCode Action::run()
{
	counter += 1;

	if (counter > 4)
	{
		return ReturnCode::SUCCESS;
	}
	else
	{
		return ReturnCode::RUNNING;
	}


}
