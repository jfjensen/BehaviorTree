#include "actionexec.h"

ReturnCode ActionExec::run()
{
	counter += 1;

	if (counter > 4)
	{
		counter = 0;
		LOG(DEBUG) << "---> success" ;
		return ReturnCode::SUCCESS;
	}
	else
	{
		LOG(DEBUG) << "---> running" ;
		return ReturnCode::RUNNING;
	}


}
