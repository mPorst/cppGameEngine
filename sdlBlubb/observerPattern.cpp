#include "stdafx.h"
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
void observer::onNotify(std::string notification)
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

void subject::notify(std::string notification)
{
	for (observer* indexObserver : observerList)
	{
		indexObserver->onNotify(notification);
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
				std::cout << "DEBUG: hinzuzugügender Observer befindet sich bereits in Liste" << std::endl;
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
