
#ifndef LOGIC_H_
#define LOGIC_H_


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include "Task.h"
#include "Parser.h"
#include "addExecutor.h"
#include "deleteExecutor.h"
#include "editExecutor.h"
#include "searchExecutor.h"
#include "markDoneExecutor.h"
#include "Display.h"
#include "Storage.h"
#include "History.h"
#include "SystemResponse.h"
#include <stdio.h>

class Logic{

private:


    Parser parse;

	
    addExecutor add;
    deleteExecutor deleteATask;
    editExecutor edit;
	searchExecutor search;
	markDoneExecutor mark;
	Storage storage;
	Display disp;
	History history;
	SystemResponse response;


public:
	Logic();
	~Logic();
    vector<Task> taskList;
	vector<Task> deadlineList;
    vector<Task> floatingList;

	enum COMMAND_TYPE {

		_ADD, _DELETE, _EDIT, _SEARCH, _MARKDONE, _DISPLAY, _UNDO, _REDO, _ERROR

	};
	void retriveStorage();
    void addTask();
	void deleteTask();
	void editTask();
	void searchTask();
	void markDoneTask();
	void display();
	void undoTask();
	void redoTask();
	bool checkIndex(int);
	string tellGUI();
	COMMAND_TYPE determineCommandType(string);
    void executeUserCommand (string);


};
#endif