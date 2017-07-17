#ifdef _WIN32
	#include "stdafx.h"
#endif
#include "observerPattern.h"

#define DEBUG 0

/// observer

//constructor, destructor
observer::observer()
{
}


observer::~observer()
{
}

//other methods
void observer::onNotify(subsystem_t system, button_Press_t key)
{
	_system = system;
	_key = key;
}

int observer::getKey()
{
	if (_system != NIL_SYS) // put _system to NIL state so input does not get read twice !
	{
		_system = NIL_SYS;
		return _key;
	}
	return _key
}

void observer::answerPing()
{

}

// variables
subsystem_t system;
int key;

/// subject
// constructor
subject::subject()
{

}

subject::~subject()
{

}

// other methods

void subject::notify(subsystem_t system, button_Press_t key)
{
	for (observer* indexObserver : observerList)
	{
		indexObserver->onNotify(system, key);
	}
}

void subject::removeObserver(observer* observerToRemove)
{
}

GLboolean subject::addObserver(observer* observerToAdd)
{
	for (observer* indexObserver : observerList ) // check if observer is already in list
	{
		if (indexObserver == observerToAdd)
		{
			#ifdef DEBUG
				std::cout << "DEBUG: hinzuzufügender Observer befindet sich bereits in Liste" << std::endl;
			#endif
			return false;
		}
	}
	// if not: push back to list
	observerList.push_back(observerToAdd); 
	return true;
}

void subject::cleanObserverList()
{

}

GLboolean subject::pingObserver()
{
	return GLboolean();
}
