#include<stack>
#include<string>
#include<vector>
#include"History.h"
#include"Task.h"

using namespace std;


History::History(){};
History::~History(){};



void History::saveOperation(vector<Task> taskStorage){
	undoStorageList.push(taskStorage);

};

bool History::undo(vector<Task> updatedTaskList){
	bool undoStatue = false;
	
	if (!undoStorageList.empty()){
		redoStorageList.push(undoStorageList.top());
		
		if (undoStorageList.size() > 2){
			undoStorageList.pop();

			undoStatue = true;
		}
	
		updatedTaskList.clear();

		for (int i=0; i<undoStorageList.top().size(); i++){
			updatedTaskList.push_back(undoStorageList.top()[i]);
		}
	}

	if (undoStatue == false){
		redoStorageList.pop();
	}

	return undoStatue;
};

bool History::redo(vector<Task> updatedTaskList){
	bool redoStatus = false;

	if (!redoStorageList.empty()){
		updatedTaskList.clear();

		for (int i=0; i<redoStorageList.top().size(); i++){
			updatedTaskList.push_back(redoStorageList.top()[i]);
		}

		undoStorageList.push(redoStorageList.top());
		redoStorageList.pop();

		redoStatus = true;
	}

	return redoStatus;
};

//void History::updateHistoryTaskList(vector<Task> taskStorage){
//	historyTaskList = taskStorage;
//}

