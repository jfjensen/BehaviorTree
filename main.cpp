
#include <iostream>
#include <string>
#include <random>

#include "behaviortree.h"
#include "node.h"
#include "returncode.h"





using namespace std;

ReturnCode predOnComingCar()
{
	
	cout << "predOnComingCar -> ";
   	random_device rd;  //Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> dis(0,1);
	int true_false = dis(gen);
	if (true_false==1)
	{
		cout << " success" << endl;
		return ReturnCode::SUCCESS;	
	}
	else 
	{
		cout << " failure" << endl;
		return ReturnCode::FAILURE;	
	}
	
	
}

ReturnCode predCarInFront()
{
   	cout << "predCarInFront -> " ;
   	random_device rd;  //Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> dis(0,1);
	int true_false = dis(gen);
	if (true_false==1)
	{
		cout << " success" << endl;
		return ReturnCode::SUCCESS;	
	}
	else 
	{
		cout << " failure" << endl;
		return ReturnCode::FAILURE;	
	}
	
}


ReturnCode actionAvoid()
{
	cout << "Avoiding car -> ";
	random_device rd;  //Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> dis(0,1);
	int true_false = dis(gen);
	if (true_false == 1)
	{
		cout << " success" << endl;
		return ReturnCode::SUCCESS;
	}
	else
	{
		cout << " running" << endl;
		return ReturnCode::RUNNING;
	}
}

// ReturnCode actionOvertake()
// {
// 	cout << "Overtaking car" << endl;
// 	return ReturnCode::SUCCESS;
// }

ReturnCode actionTurnOut()
{
	cout << "Turning out -> ";
	random_device rd;  //Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> dis(0,1);
	int true_false = dis(gen);
	if (true_false == 1)
	{
		cout << " success" << endl;
		return ReturnCode::SUCCESS;
	}
	else
	{
		cout << " running" << endl;
		return ReturnCode::RUNNING;
	}
}

ReturnCode actionPassCar()
{
	cout << "Passing car -> ";
	random_device rd;  //Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> dis(0,1);
	int true_false = dis(gen);
	if (true_false == 1)
	{
		cout << " success" << endl;
		return ReturnCode::SUCCESS;
	}
	else
	{
		cout << " running" << endl;
		return ReturnCode::RUNNING;
	}
}

ReturnCode actionTurnIn()
{
	cout << "Turning in -> ";
	random_device rd;  //Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> dis(0,1);
	int true_false = dis(gen);
	if (true_false == 1)
	{
		cout << " success" << endl;
		return ReturnCode::SUCCESS;
	}
	else
	{
		cout << " running" << endl;
		return ReturnCode::RUNNING;
	}
}

ReturnCode actionCruise()
{
	cout << "Cruising -> ";
	random_device rd;  //Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    uniform_int_distribution<> dis(0,1);
	int true_false = dis(gen);
	if (true_false == 1)
	{
		cout << " success" << endl;
		return ReturnCode::SUCCESS;
	}
	else
	{
		cout << " running" << endl;
		return ReturnCode::RUNNING;
	}
}


int main(int argc, char const *argv[])
{
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
		result = sel->tick();
	}

	// Conditional cond (pred);
	// cout << (cond.tick() == ReturnCode::SUCCESS) << endl;


	cout << "code working so far" << endl;
	return 0;
}
