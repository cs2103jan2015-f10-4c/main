//@author A0115404W

#include "Logic.h"


Logic::Logic() {}
Logic::~Logic() {}


void Logic::executeUserCommand(string userInput) {
	
	string commandWord;
	commandWord = parse.getCommandWord(userInput);
	CommandType commandType;
	commandType = determineCommandType(commandWord);

	switch (commandType) {
	case _ADD:
		 return addTask();
	case _DELETE:
		return deleteTask();
	case _EDIT:
		return editTask();
	case _SEARCH:
		return searchTask();
	case _MARKDONE:
		return markDoneTask();
	case _DISPLAY:
		return displayVariousType();
	case _UNDO:
		return undoTask();
	case _REDO:
		return redoTask();
	case _DIRECTORY:
		return getDirectory();
	case _CLEAR:
		return clearTaskList();
	case _EXIT:
		return exitProgram();
	default:
		return showUserInvalidResponse();
	}
}


Logic:: CommandType Logic::determineCommandType(string commandWord) {

	if (commandWord == "add") {
		return CommandType::_ADD;
	} else if (commandWord == "delete") {
		return CommandType::_DELETE;
	} else if (commandWord == "edit") {
		return CommandType::_EDIT;
	} else if (commandWord == "search") {
		return CommandType::_SEARCH;
	} else if (commandWord == "mark done") {
		return CommandType::_MARKDONE;
	} else if (commandWord == "display") {
		return CommandType::_DISPLAY;
	} else if (commandWord == "undo") {
		return CommandType::_UNDO;
	} else if (commandWord == "redo") {
		return CommandType::_REDO;
	}else if (commandWord == "directory") {
		return CommandType::_DIRECTORY;
	}else if (commandWord == "clear") {
		return CommandType::_CLEAR;
	}else if (commandWord == "exit") {
		return CommandType::_EXIT;
	}else {
		return CommandType::_INVALID;
	}
}


void Logic::addTask() {

	bool isAddedValidTime = false;
	isAddedValidTime = parse.getvalidTime();
	bool isAddedCorrectFormat = false;
	isAddedCorrectFormat = parse.getIsCorrectFormat();

	if (isAddedValidTime && isAddedCorrectFormat) {
	string taskType = parse.getTaskType();
	if (taskType == "timed") {
		string taskName = parse.getTaskName();
		string startTime = parse.getStartTime();
		string endTime = parse.getEndTime();
		add.addTimedTask(taskName, startTime, endTime, taskType, taskList);
	} else if (taskType == "deadline") {
		string taskName = parse.getTaskName();
		string endTime = parse.getEndTime();
		add.addDeadlineTask(taskName, endTime, taskType, deadlineList,taskList);
	} else if (taskType == "floating") {
		string taskName = parse.getTaskName();
		add.addFloatingTask(taskName, taskType, floatingList, taskList);
	}

	history.saveOperation(taskList);
	response.addResponse(isAddedValidTime, isAddedCorrectFormat);
	disp.setDefaultDisplay(taskList);
	storage.saveFile(taskList);
	}else if (!isAddedValidTime) {
		response.addResponse(isAddedValidTime, true);
	}else if (!isAddedCorrectFormat) {
		response.addResponse(true, isAddedCorrectFormat);
	}
}

void Logic::deleteTask() {

	bool isCorrectIndex = false;
	int index = parse.getIndex();

	if (checkIndex(index)) {
		isCorrectIndex = true;
	    deleteATask.deleteTask(index, taskList);
	    history.saveOperation(taskList);
		response.deleteResponse(isCorrectIndex, index);
		disp.setDefaultDisplay(taskList);
	    storage.saveFile(taskList);
	} else if (!checkIndex(index)) {
		response.deleteResponse(isCorrectIndex, index);
	}
}

void Logic::editTask() {

	bool isCorrectIndex = false;
	int index = parse.getIndex();

	if (checkIndex(index)) {
		isCorrectIndex = true;
	    string newTaskName = parse.getTaskName();
	    string newStartTime = parse.getStartTime();
	    string newEndTime = parse.getEndTime();
		string newTaskType = parse.getTaskType();
	    edit.editTask(index, newTaskName, newStartTime, newEndTime, newTaskType, taskList);
	    history.saveOperation(taskList);
		response.editResponse(isCorrectIndex, index);
		disp.setDefaultDisplay(taskList);
	    storage.saveFile(taskList);
	} else {
		response.editResponse(isCorrectIndex, index);
	}
}

void Logic::searchTask() {

	string keyPhrase = parse.getSearchWord();
	bool isEmptyList = checkFoundList(search.searchTask(keyPhrase, taskList));

	if (isEmptyList) {
		response.searchResponse(isEmptyList);
		disp.setDefaultDisplay(search.searchTask(keyPhrase, taskList));
	} else {
		response.searchResponse(isEmptyList);
		disp.setDefaultDisplay(search.searchTask(keyPhrase, taskList));
	}
}

void Logic::markDoneTask() {

	bool isCorrectIndex = false;
	bool isDone = false;
	int index = parse.getIndex();

	if (checkIndex(index)) {
		isCorrectIndex = true;
		if (taskList[index-1].status != "done") {
			mark.markDoneTask(index, taskList);
			history.saveOperation(taskList);
			response.markDoneResponse(isCorrectIndex,isDone, index);
			disp.setDefaultDisplay(taskList); 
			storage.saveFile(taskList);
		} else {
            isDone = true; 
			response.markDoneResponse(isCorrectIndex, isDone, index);
		}	
	} else {
		response.markDoneResponse(isCorrectIndex,isDone,index);
	}
}

void Logic::undoTask() {

	bool isSuccessful = false;
	isSuccessful = history.checkUndoEmpty();

	if (isSuccessful) {
		taskList = history.undo();
		response.undoResponse(isSuccessful);
	    disp.setDefaultDisplay(taskList);
	    storage.saveFile(taskList);
	} else {
		response.undoResponse(isSuccessful);
	}
}

void Logic::redoTask() {

	bool isSuccessful = false;
	isSuccessful = history.checkRedoEmpty();

	if (isSuccessful) {
		taskList = history.redo();
		response.redoResponse(isSuccessful);
	    disp.setDefaultDisplay(taskList);
	    storage.saveFile(taskList);
	} else {
		response.redoResponse(isSuccessful);
	}
}

void Logic::displayVariousType() {       

	string displayType = parse.getTaskType();
	string outputMsg = disp.setVariousDisplay(taskList, displayType);
	response.dispVariousResponse(outputMsg);
}

void Logic::showUserInvalidResponse(){

	response.invalidResponse();
}

string Logic::tellGUI(){

	return disp.getContent();
}

string Logic::tellGUIResponse() {

	return response.tellResponse();
}

void Logic::checkDirectory() {

	bool hasDirectory;
	hasDirectory = storage.hasDirectory();

	if (hasDirectory) {
		response.welcomeExistingMessage();
		storage.readFile(taskList);
		history.saveOperation(taskList);
	} else {
		response.noDirectoryResponse();
	}
}

void Logic::getDirectory() {

	bool isValid = false;
	struct stat sb;
	string pathname;
	pathname = parse.getTaskType();

	if(stat(pathname.c_str(), &sb) != 0 || !(S_IFDIR & sb.st_mode)) {
		response.DirectoryResponse(isValid);
	} else {
		isValid = true;
		response.DirectoryResponse(isValid);
		storage.setUserInputPath(pathname);
		storage.readFile(taskList);
	}
}

bool Logic::checkIndex(int index) {
	
		if (index > 0 && index <= taskList.size()) {
			return true;
		} else {
			return false;
		}
}

void Logic::refreshStatus() {

	checker.updateStatus(taskList);
	disp.setDefaultDisplay(taskList);
}

bool Logic::checkFoundList(vector<Task> foundList) {

	if (foundList.size() == 0) {
		return true;
	} else {
		return false;
	}
}

void Logic::clearTaskList() {

	taskList.clear();
	history.saveOperation(taskList);
    response.clearAllResponse();
	disp.setDefaultDisplay(taskList);
	storage.saveFile(taskList);
}

void Logic::exitProgram() {
	exit(EXIT_SUCCESS);
}

