#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <glew\glew.h>

enum engine_subsystem_t { PHYSICS, RENDER, INPUT, OTHER };
enum CODE {newInput};

class observer
{
public:
	observer();
	~observer();

	void onNotify(std::string notification); // called by subject via notify
	//void subscribe();  // not required: public API of subject
	//void unsubscribe();// not required: public API of subject
	void answerPing(); // 
};

class subject
{
public:
	subject();
	~subject(); // remove ALL pointers !!!

	void removeObserver(observer* observerToRemove); // public API
	GLboolean addObserver(observer* observerToAdd); // public API

private:
	// variables
	std::vector<observer*> observerList;

	//methods
	void notify(std::string notification); //send information

	void cleanObserverList(); // in case some observers just disappear without saying goodbye
	GLboolean pingObserver(); // nice to have in order to clean observer list

};

