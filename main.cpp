
#include <iostream>
#include <string>
#include <random>

#include "behaviortree.h"
#include "node.h"
#include "returncode.h"

#include "log.h"
// https://stackoverflow.com/questions/5028302/small-logger-class


using namespace std;

structlog LOGCFG = {};


ReturnCode succ_fail()
{
	random_device rd;  //Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> dis(0,1);
	int true_false = dis(gen);
	if (true_false==1)
	{
		LOG(DEBUG) << "---> success" ;
		return ReturnCode::SUCCESS;	
	}
	else 
	{
		LOG(DEBUG) << "---> failure" ;
		return ReturnCode::FAILURE;	
	}
}

ReturnCode succ_runn()
{
	random_device rd;  //Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> dis(0,1);
	int true_false = dis(gen);
	if (true_false == 1)
	{
		LOG(DEBUG) << "---> success" ;
		return ReturnCode::SUCCESS;
	}
	else
	{
		LOG(DEBUG) << "---> running" ;
		return ReturnCode::RUNNING;
	}
}


ReturnCode predOnComingCar()
{
	
	LOG(DEBUG) << "predOnComingCar:";
   	
	return succ_fail();
	
}

ReturnCode predCarInFront()
{
   	LOG(DEBUG) << "predCarInFront:" ;
   	return succ_fail();
	
}


ReturnCode actionAvoid()
{
	LOG(DEBUG) << "Avoiding car:";
	return succ_runn();
}


ReturnCode actionTurnOut()
{
	LOG(DEBUG) << "Turning out:";
	return succ_runn();
}

ReturnCode actionPassCar()
{
	LOG(DEBUG) << "Passing car:";
	return succ_runn();
}

ReturnCode actionTurnIn()
{
	LOG(DEBUG) << "Turning in:";
	return succ_runn();
}

ReturnCode actionCruise()
{
	LOG(DEBUG) << "Cruising:";
	return succ_runn();
}


int main(int argc, char const *argv[])
{

	LOGCFG.headers = false; 
    LOGCFG.level = DEBUG;

	LOG(INFO) << "Main executed with " << (argc - 1) << " arguments";

	BehaviorTree bt;
	//Node nd;


	Selector *sel = new Selector();

		Sequence *seq_oncoming_car = new Sequence();
		sel->addChild(seq_oncoming_car);

			Conditional *cond_oncoming = new Conditional(predOnComingCar);
			seq_oncoming_car->addChild(cond_oncoming);

			Action *act_avoiding = new Action(actionAvoid);
			seq_oncoming_car->addChild(act_avoiding);

		Sequence *seq_overtake = new Sequence();
		sel->addChild(seq_overtake);

			Conditional *cond_car_infront = new Conditional(predCarInFront);
			seq_overtake->addChild(cond_car_infront);

			Sequence *seq_overtake_exec = new Sequence();
			seq_overtake->addChild(seq_overtake_exec);

				Action *act_turn_out = new Action(actionTurnOut);
				seq_overtake_exec->addChild(act_turn_out);

				Action *act_pass_car = new Action(actionPassCar);
				seq_overtake_exec->addChild(act_pass_car);

				Action *act_turn_in = new Action(actionTurnIn);
				seq_overtake_exec->addChild(act_turn_in);

		Action *act_cruise = new Action(actionCruise);
		sel->addChild(act_cruise);

	
	ReturnCode result;
	result = sel->tick();
	while (result != ReturnCode::SUCCESS)
	{
		LOG(INFO) << "---------- new iteration ---------";
		result = sel->tick();
	}

	// Conditional cond (pred);
	// cout << (cond.tick() == ReturnCode::SUCCESS) << endl;


	LOG(INFO) << "code working so far" ;
	return 0;
}
