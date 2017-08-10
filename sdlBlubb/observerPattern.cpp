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

void observer::refreshSysKey()
{
	_sysKey = { _system, _key };
}

sysKey observer::getKey()
{
	if (_system != NIL_SYS) // put _system and _key to NIL state so input does not get read twice !
	{
		sysKey temp = { _system, _key };
		_system = NIL_SYS;
		_key = NO_KEY;
		refreshSysKey();
		return temp;
	}
	return _sysKey;
}

void observer::subscribe(subject* observedThing)
{
	observedThing->addObserver(this);
	return;
}

void observer::unsubscribe(subject* observedThing)
{

}

void observer::answerPing()
{

}

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

int subject::observerListSize()
{
	return observerList.size();
}

void subject::cleanObserverList()
{

}

GLboolean subject::pingObserver()
{
	return GLboolean();
}
