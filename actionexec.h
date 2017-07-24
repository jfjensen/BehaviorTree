#ifndef ACTIONEXEC_H
#define ACTIONEXEC_H

#include "returncode.h"
#include "log.h"

class ActionExec {
private:
	int counter;
public:
	ActionExec(){ counter = 0; };
	~ActionExec(){};

	ReturnCode run();

	int getCounter() { return counter; }
};

#endif // ACTIONEXEC_H
