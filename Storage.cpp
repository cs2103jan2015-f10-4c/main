#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include "Storage.h"
//hello

using namespace std;

void Storage::storeTask(string task, string startingTime, string endingTime, string date){
	Task tempStorage;
	tempStorage.taskDescription = task;
	tempStorage.startingTime = startingTime;
	tempStorage.endingTIme = endingTime;
	tempStorage.date = date;
	taskList.push_back(tempStorage);
};

void Storage::saveFile(vector<Task> fileStorage){
	ofstream writeFile;
	writeFile.open("file.txt");
	for (int i = 0; i < fileStorage.size(); i++){
		writeFile << fileStorage[i].taskDescription;
		writeFile << fileStorage[i].date;
		writeFile << fileStorage[i].startingTime;
		writeFile << fileStorage[i].endingTIme << endl;
	}
	writeFile.close();
};



