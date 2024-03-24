#pragma once
#ifndef ACTION_H
#define ACTION_H
#include "MainObject.h"
#include <vector>

class Item;

class Action : public MainObject
{
public:
	Action(const string name, const string desc);
	void setReceiver(Item* r);
	virtual ~Action() {}

private:
	vector<Item*> _posibleReceivers = {};
};

#endif
