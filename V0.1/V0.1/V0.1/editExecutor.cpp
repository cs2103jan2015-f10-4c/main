#include "editExecutor.h"

editExecutor::editExecutor(void){}

editExecutor::~editExecutor(void){}

void editExecutor::editTask(int index, string newTaskName, string newStartTime, string newEndTime){
	taskList = storage.getTaskList();
	taskList[index - 1].taskName = newTaskName;
	taskList[index - 1].startingTime = newStartTime;
	taskList[index - 1].endingTime = newEndTime;
	taskList[index - 1].status = DEFAULT_TASK_STATUS;


	updateStorage();
    cout << "Editted result: " << taskList[index - 1].taskName << setw(15) << taskList[index - 1].startingTime << setw(15) <<
		taskList[index - 1].endingTime << setw(15) << taskList[index - 1].status <<endl;
    //displayAll();

}