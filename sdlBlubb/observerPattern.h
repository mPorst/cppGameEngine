#ifdef _WIN32
	#pragma once
#endif

#include <vector>
#include <string>
#include <iostream>
#include <glew\glew.h>

enum subsystem_t { NIL_SYS, PHYSICS, RENDER, INPUT, OTHER};
enum button_Press_t { NO_KEY, GAME_EXIT, MOVE_FORWARD, MOVE_LEFT, MOVE_RIGHT, MOVE_BACK, MOVE_UP, MOVE_DOWN };

struct sysKey {
	subsystem_t system;
	button_Press_t key;

	bool operator!=(const sysKey& otherSysKey)  // I did not initially understand this: This is a comparison between the "this" object and otherSysKey.
	{
		if (otherSysKey.system != system && otherSysKey.key != key) return true;
		else return false;
	}
};

class subject;

class observer
{
public:
	observer();
	~observer();

	void onNotify(subsystem_t system, button_Press_t key); // called by subject via notify
	void subscribe(subject* observedThing);  
	void unsubscribe(subject* observedThing);
	void answerPing();
	sysKey getKey();
	void refreshSysKey();

private:
	subsystem_t _system = NIL_SYS; // initialise to "0"
	button_Press_t _key = NO_KEY;	// initialise to "0"
	sysKey _sysKey;
};

class subject
{
public:
	subject();
	~subject(); // remove ALL pointers !!!

	void removeObserver(observer* observerToRemove); // public API
	GLboolean addObserver(observer* observerToAdd); // public API
	void notify(subsystem_t system_, button_Press_t key_); //send information
	int subject::observerListSize(); 

private:
	// variables
	std::vector<observer*> observerList;

	//methods

	void cleanObserverList(); // in case some observers just disappear without saying goodbye
	GLboolean pingObserver(); // nice to have in order to clean observer list

};

