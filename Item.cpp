//
//  Item.cpp
//  Borley Rectory Haunted Mansion Text-Based Console Game
//
//  Created by Oscar Martinez on 21/03/2024.
//
#include <iostream>

#include "Action.h"
#include "Item.h"
#include "ItemPickStoreLight.h"

Item::Item(const string name, const string desc, const string pd) : MainObject(name, desc)
{
	_posDesc = pd;
	_visibleInDark = false;
	_canLightItems = false;
	_roomLevel = 0;
}

void Item::removeActions()
{
	for (Action* a : _actions)
	{
		delete a;
	}
	_actions.clear();
}

string Item::getPosDesc()
{
	return _posDesc;
}
void Item::setPosDesc(string newDesc)
{
	if (newDesc.empty())
	{
		throw invalid_argument("Description must not be empty");
	}
	_posDesc = newDesc;
}

void Item::setAction(Action* a)
{
	_actions.push_back(a);
}

Action* Item::getAction(int idx)
{
	return _actions[idx];
}

int Item::getNumActions()
{
	return (int)_actions.size();
}

string Item::getDisplayString()
{
	return getName() + " - " + getPosDesc();
}

void Item::displayActions()
{
	for (int i = 0; i < _actions.size(); i++)
	{
		cout << "[" << i + 1 << "]" << " " << _actions[i]->getName() << "\n";
	}
}

void Item::setState(ItemState s)
{
	_state = s;
}

ItemState Item::getState()
{
	return _state;
}

void Item::setHoldingItem(Item* it)
{
	_holding.push_back(it);
}

Item* Item::getHoldingItem(int idx)
{
	return _holding[idx];
}

int Item::getNumHoldingItems()
{
	return (int)_holding.size();
}

void Item::removeHoldingItem(Item* it)
{
	auto r = std::find(_holding.begin(), _holding.end(), it);

	// Check if the element was found
	if (r != _holding.end()) {
		// Erase the element from the vector
		_holding.erase(r);
	}
}

void Item::displayHoldingItems()
{
	if (_holding.size() > 0)
	{
		cout << "It has:" << endl;
	}
	for (int i = 0; i < _holding.size(); i++)
	{
		cout << "-" << _holding[i]->getName() << endl;
	}
	if (_holding.size() > 0)
	{
		cout << endl << endl;
	}
}

void Item::setParent(Item* p)
{
	_parent = p;
	p->setHoldingItem(this);
}

Item* Item::getParent()
{
	return _parent;
}

void Item::setVisibleInDark(bool v)
{
	_visibleInDark = v;
}

bool Item::getVisibleInDark()
{
	return _visibleInDark;
}

void Item::setCanLightItems(bool v)
{
	_canLightItems = v;
}

bool Item::getCanLightItems()
{
	return _canLightItems;
}

bool Item::isPickStoreLight()
{
	bool retVal = false;

	if (ItemPickStoreLight* iPickStoreLight = dynamic_cast<ItemPickStoreLight*>(this))
	{
		retVal = true;
	}
	return retVal;
}

void Item::setRoomLevel(int level)
{
	_roomLevel = level;
}

int Item::getRoomLevel()
{
	return _roomLevel;
}



void Item::setViewableItem(Item* it)
{
	_viewable = it;
	it->setViewFromItem(this);
}

Item* Item::getViewableItem()
{
	return _viewable;
}

int Item::getNumViewableItems()
{
	int retVal = 0;

	if (_viewable != nullptr)
	{
		retVal = 1;
	}

	return retVal;
}

void Item::removeViewableItem()
{
	_viewable = nullptr;
}

void Item::displayViewableItems()
{
	if (_viewable != nullptr)
	{
		cout << "[" << 1 << "] " << _viewable->getName() << endl;
	}
}

void Item::setViewFromItem(Item* it)
{
	_viewFrom = it;
}

void Item::removeViewFromItem()
{
	_viewFrom = nullptr;
}

void Item::picked(){}
void Item::stored() {}
void Item::wore(){}
void Item::lighted(){}
void Item::hanged(){}
void Item::dropped(){}
void Item::moved(int idx) {}
string Item::read() { return ""; }
void Item::displayDestinations(){}
Item* Item::getCurrentDestination() { return nullptr; }