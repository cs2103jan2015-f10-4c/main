#include "Task.h"
#include <string>


Task::Task(){
}

Task::~Task(){}

void Task::setTaskName(string inputTaskName){
	taskName = inputTaskName;
}

void Task::setStartingTime(string inputStartingTime){
	startingTime = inputStartingTime;
}

void Task::setEndingTime(string inputEndingTime){
	endingTime = inputEndingTime;
}

void Task::setDone(string inputDone){
	status = inputDone;
}

void Task::setType(string inputType){
	type = inputType;
}

//void Task::setDate(string inputDate){
	//date = inputDate;
//}
