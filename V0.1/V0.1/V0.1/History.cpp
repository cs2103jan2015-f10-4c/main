#include<stack>
#include<string>
#include<vector>
#include"History.h"
#include"Task.h"

using namespace std;


History::History(){};
History::~History(){};



void History::saveOperation(vector<Task>& taskStorage){
	undoStorageList.push(taskStorage);

};

vector<Task> History::undo(){
    
    vector<Task> updatedTaskList;
    
	if (!undoStorageList.empty()){
        redoStorageList.push(undoStorageList.top());
        
            undoStorageList.pop();
            
            updatedTaskList = undoStorageList.top();
        
        
        return updatedTaskList;
    }
    // else ?  take note of exceptions and assertiona failure
};


vector<Task> History::redo(){
	vector<Task> updatedTaskList;

	if (!redoStorageList.empty()){
		
		updatedTaskList = redoStorageList.top();
		

		undoStorageList.push(redoStorageList.top());
		redoStorageList.pop();

		return updatedTaskList;
	}
	
	//else return?  take note of exceptions and assertion failure 
};


stack <vector<Task>> History::getUndoStorageList(){
	return undoStorageList;
}

stack <vector<Task>> History::getRedoStorageList(){
	return redoStorageList;
}


