//@author A0115404W

#include "searchExecutor.h"

SearchExecutor::SearchExecutor(void) {}

SearchExecutor::~SearchExecutor(void) {}

vector<Task> SearchExecutor::searchTask(string  keyPhrase, vector<Task>& taskList) {

	vector<Task> searchResult;

    for (unsigned i=0; i < taskList.size(); i++) {
		size_t found = taskList[i].taskName.find(keyPhrase);
		if (found != std::string::npos){
            searchResult.push_back(taskList[i]);
        }
    }

	return searchResult;
    
}

string SearchExecutor::getSearchedResult(vector<Task> searchResult) {

	if (searchResult.size() == 0) {
		return "";
	} else {
		for (unsigned i = 0; i < searchResult.size(); i++) {
			return searchResult[i].ToString();
		}
	}
}   


