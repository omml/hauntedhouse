//
//  Action.h
//  Borley Rectory Haunted Mansion Text-Based Console Game
//
//  Created by Oscar Martinez on 21/03/2024.
//
#pragma once
#ifndef ACTION_H
#define ACTION_H
#include "MainObject.h"
#include "CommonDefinitions.h"
#include <vector>

class Item;

class Action : public MainObject
{
public:
	Action(const string name, const string desc);
	void setReceiver(Item* r);
	virtual ~Action() {}
	ActionIdentifier GetActionID();

private:
	vector<Item*> _posibleReceivers = {};
protected:
	ActionIdentifier _actionId;

};

#endif
