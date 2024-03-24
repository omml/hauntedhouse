#include "ItemMove.h"
#include "ActionMove.h"
#include <iostream>

ItemMove::ItemMove(const string name, const string desc, const string dp) : Item(name, desc, dp)
{
	setAction(new ActionMove());
}

void ItemMove::setDestination(Item* d)
{
	_destinations.push_back(d);
}

void ItemMove::moved(int idx)
{
	_currentDest = _destinations[idx];
	_posDesc = "In front of the " + _currentDest->getName();
}

void ItemMove::displayDestinations()
{
	for (int i = 0; i < _destinations.size(); i++)
	{
		cout << "[" << i + 1 << "]" << " Move in front of " << _destinations[i]->getName() << "`\n";
	}
}

Item* ItemMove::getCurrentDestination()
{
	return _currentDest;
}
