#ifndef ACTION_H
#define ACTION_H

#include "returncode.h"

class Action {
private:
	int counter;
public:
	Action(){ counter = 0; };
	~Action(){};

	ReturnCode run();
};

#endif // ACTION_H
