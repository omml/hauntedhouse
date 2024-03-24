#include "Room.h"
#include <iostream>
#include "CommonDefinitions.h"
#include "GameState.h"
#include "ItemPickStoreLight.h"

using namespace std;

Room::Room(const string name, const string desc) : MainObject(name,desc)
{
	_isLighted = false;

	for (int i = 0; i < 4; i++)
	{
		_linkedRooms[i] = nullptr;
		_smallPassage[i] = nullptr;
	}
}

void Room::setLinkedRoom(int idx, Room* r)
{
	_linkedRooms[idx] = r;
}

Room* Room::getLinkedRoom(int idx)
{
	return _linkedRooms[idx];
}

void Room::setSmallPassage(int idx, Room* r)
{
	_smallPassage[idx] = r;
}

Room* Room::getSmallPassage(int idx)
{
	return _smallPassage[idx];
}

int Room::getNumItems()
{
	return (int)_items.size();
}

void Room::displayRooms()
{
	for (int i = 0; i < 4; i++)
	{
		if (_linkedRooms[i] != nullptr)
		{
			cout << "[" << i+1 << "]" << " Move " << DirectionNames[i] << " - " << _linkedRooms[i]->getName() << endl;
		}
	}
}

void Room::setItem(Item* i)
{
	_items.push_back(i);
}

void Room::removeItem(Item* i)
{
	_items.erase( remove(_items.begin(), _items.end(), i), _items.end() );
}

Item* Room::getItem(int idx)
{
	return _items[idx];
}

void Room::displayItems()
{
	for (int i = 0; i < _items.size(); i++)
	{
		if (_isLighted == true || _items[i]->getVisibleInDark())
		{
			if (GameState::getInstance().getCurrentRoomLevel() == _items[i]->getRoomLevel())
			{
				cout << "[" << i + 1 << "]" << " " << _items[i]->getDisplayString() << endl;
			}
		}
	}
}

bool Room::isThereCandleLighted()
{
	bool retVal = false;

	for (int i = 0; i < _items.size(); i++)
	{
		
		if (ItemPickStoreLight* iPickStoreLight = dynamic_cast<ItemPickStoreLight*>(_items[i]))
		{
			retVal = iPickStoreLight->getState() == Lighted;
			break;
		}
	}

	return retVal;
}

void Room::setIsLighted(bool v, bool cc)
{
	_isLighted = v;
	_carryingCandle = cc;
}

void Room::hasDroppedCandle(Item* i)
{
	if(i->isPickStoreLight())
	{
		_carryingCandle = false;
	}
}

string Room::getIsDarkDescription()
{
	if (_isLighted == false)
	{
		return "It is dark, you need a lighted candle to see";
	}
	else
	{
		if (_carryingCandle)
		{
			return "It is lighted as you are carrying a lighted candle";
		}
		else
		{
			return "It is lighted as there is a lighted candle in the room";
		}
	}
}