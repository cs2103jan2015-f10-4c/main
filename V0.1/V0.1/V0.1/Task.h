//@author A0115404W

#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

class Task{
private:

	
public:
	string taskName;
	string startingTime;
	string endingTime;
	string status;
	string type;


	Task();
	~Task();
   
	void setTaskName(string inputTaskName);
	void setStartingTime(string inputStartingTime);
	void setEndingTime(string inputEndingTime);
	void setDone(string inputDone);
	void setType(string inputType);

	string ToString();

};
#endif
