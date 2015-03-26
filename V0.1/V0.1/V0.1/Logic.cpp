

#include "Logic.h"

void Logic::executeUserCommand(string userInput){
	string commandWord;
	commandWord = parse.getCommandWord(userInput);
	COMMAND_TYPE commandType;
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
		return display();
	case _UNDO:
		return undoTask();
	case _REDO:
		return redoTask();
	default:
		break;
	}
}

Logic:: COMMAND_TYPE Logic::determineCommandType(string commandWord){
	if (commandWord == "Add" || commandWord == "add") {
		return COMMAND_TYPE::_ADD;
	} else if (commandWord == "Delete" || commandWord == "delete") {
		return COMMAND_TYPE::_DELETE;
	} else if (commandWord == "Edit" || commandWord == "edit") {
		return COMMAND_TYPE::_EDIT;
	} else if (commandWord == "Search" || commandWord == "search") {
		return COMMAND_TYPE::_SEARCH;
	} else if (commandWord == "Mark done" || commandWord == "mark done" || commandWord == "mark") {
		return COMMAND_TYPE::_MARKDONE;
	} else if (commandWord == "Display" || commandWord == "display") {
		return COMMAND_TYPE::_DISPLAY;
	} else if (commandWord == "Undo" || commandWord == "undo") {
		return COMMAND_TYPE::_UNDO;
	} else if (commandWord == "Redo" || commandWord == "redo") {
		return COMMAND_TYPE::_REDO;
	}
}

void Logic::addTask(){
	string taskType = parse.getTaskType();
	if (taskType == "Timed") {
		string taskName = parse.getTaskName();
		string startTime = parse.getStartTime();
		string endTime = parse.getEndTime();
		add.addTask(taskName, startTime, endTime, taskType);
	} else if (taskType == "Deadline") {
		string taskName = parse.getTaskName();
		string endTime = parse.getEndTime();
		add.addDeadlineTask(taskName, endTime, taskType);
	} else if (taskType == "Floating") {
		string taskName = parse.getTaskName();
		add.addFloatingTask(taskName, taskType);
	}
}

void Logic::deleteTask(){
	int index = parse.getIndex();
	deleteATask.deleteTask(index);
}

void Logic::editTask(){
	int index = parse.getIndex();
	string newTaskName = parse.getTaskName();
	string newStartTime = parse.getStartTime();
	string newEndTime = parse.getEndTime();
	edit.editTask(index, newTaskName, newStartTime, newEndTime);
}

void Logic::searchTask(){
	string keyPhrase = parse.getSearchWord();
	search.searchTask(keyPhrase);
}

void Logic::markDoneTask(){
	int index = parse.getIndex();
	mark.markDoneTask(index);
}

void Logic::undoTask(){
	storage.undo();
	taskList = storage.getTaskList();
	disp.setDefaultDisplay();
}

void Logic::redoTask(){
	storage.redo();
	taskList = storage.getTaskList();
	disp.setDefaultDisplay();
}

void Logic::display(){
	string displayType = parse.getTaskType();
	disp.setVariousDisplay(displayType);
}
