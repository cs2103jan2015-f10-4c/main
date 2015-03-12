
#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

class Task{

public:
	string taskName;
	string startingTime;
	string endingTime;
    bool done;
	//string date;

	Task();
	~Task();
   
	void setTaskName(string inputTaskName);
	void setStartingTime(string inputStartingTime);
	void setEndingTime(string inputEndingTime);
    void setDone(bool inputDone);
	//void setDate(string inputDate);

};





#endif
