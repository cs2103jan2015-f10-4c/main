#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include "Storage.h"
#include "Task.h"

using namespace std;

<<<<<<< HEAD

Storage::Storage(){
}

Storage::~Storage(){}

void Storage::storeTask(string task, string startingTime, string endingTime, string date){
=======
void Storage::storeTask(string task, string startingTime, string endingTime){
>>>>>>> aadd4e3110a98adfe2195bde96f717c7fb5bdbcb
	Task tempStorage;
	tempStorage.taskName = task;
	tempStorage.startingTime = startingTime;
	tempStorage.endingTime = endingTime;
	//tempStorage.date = date;
	taskList.push_back(tempStorage);
};

void Storage::updateTaskList(vector<Task> taskStorage){
	taskList = taskStorage;
};

void Storage::saveFile(vector<Task> fileStorage){
	ofstream writeFile;
	writeFile.open("file.txt");
	for (int i = 0; i < fileStorage.size(); i++){
		writeFile << fileStorage[i].taskName;
		//writeFile << fileStorage[i].date;
		writeFile << fileStorage[i].startingTime;
		writeFile << fileStorage[i].endingTime << endl;
	}
	writeFile.close();
};

vector<Task> Storage::getTaskList(){
	return taskList;
};
	




