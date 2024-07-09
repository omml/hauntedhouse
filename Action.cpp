//
//  Action.cpp
//  Borley Rectory Haunted Mansion Text-Based Console Game
//
//  Created by Oscar Martinez on 21/03/2024.
//
#include "Item.h"
#include "Action.h"

Action::Action(const string name, const string desc) : MainObject(name, desc)
{

}

void Action::setReceiver(Item* r)
{
	_posibleReceivers.push_back(r);
}

ActionIdentifier Action::GetActionID()
{
	return _actionId;
}