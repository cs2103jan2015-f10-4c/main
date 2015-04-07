

//@author A0116363L

#ifndef TIMECHECKER_H
#define TIMECHECKER_H
#include <time.h>
#include <iostream>
#include <vector>
#include <string>
#include "Task.h"
#include "TransformTime.h"
//#include 


class TimeChecker{

private:
	TransformTime transformTime;
	static const string NON_TARGET_TYPE;
	static const string STATUS_OVERDUE;
	static const string STATUS_DONE;

public:

	void updateStatus(vector<Task>&);
	bool checkStatus(string);

	TimeChecker();
	~TimeChecker();
};

#endif