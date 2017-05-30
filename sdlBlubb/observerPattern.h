#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <glew\glew.h>

enum subsystem_t { NIL_SYS, PHYSICS, RENDER, INPUT, OTHER};
enum button_Press_t { EMPTY, MOVE_FORWARD, MOVE_LEFT, MOVE_RIGHT, MOVE_BACK, MOVE_UP, MOVE_DOWN };

class observer
{
public:
	observer();
	~observer();

	void onNotify(subsystem_t system, button_Press_t key); // called by subject via notify
	//void subscribe();  // not required: public API of subject
	//void unsubscribe();// not required: public API of subject
	void answerPing(); // 
	int getKey();

private:
	subsystem_t _system = NIL_SYS;
	button_Press_t _key = EMPTY;	
};

class subject
{
public:
	subject();
	~subject(); // remove ALL pointers !!!

	void removeObserver(observer* observerToRemove); // public API
	GLboolean addObserver(observer* observerToAdd); // public API
	void notify(subsystem_t system_, int key_); //send information

private:
	// variables
	std::vector<observer*> observerList;

	//methods

	void cleanObserverList(); // in case some observers just disappear without saying goodbye
	GLboolean pingObserver(); // nice to have in order to clean observer list

};

