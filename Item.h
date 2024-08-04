//
//  Item.h
//  Borley Rectory Haunted Mansion Text-Based Console Game
//
//  Created by Oscar Martinez on 21/03/2024.
//
#pragma once
#ifndef ITEM_H
#define ITEM_H

#include <vector>

#include "CommonDefinitions.h"
#include "MainObject.h"

class Action;

// Class that holds funtionality for objects found in the rooms
class Item : public MainObject
{
public:
	Item(const string name, const string desc, const string posDesc);
	virtual ~Item() {}

	void setPosDesc(string s);
	string getPosDesc();

	void setAction(Action* a);
	Action* getAction(int idx);
	void displayActions();
	int getNumActions();
	string getDisplayString();
	string getNameDesc();

	void setHoldingItem(Item* it);
	Item* getHoldingItem(int idx);
	int getNumHoldingItems();
	void removeHoldingItem(Item* it);
	void displayHoldingItems();

	void setViewableItem(Item* it);
	Item* getViewableItem();
	int getNumViewableItems();
	void removeViewableItem();
	void displayViewableItems();

	void setViewFromItem(Item* it);
	void removeViewFromItem();

	void setParent(Item* p);
	Item* getParent();

	void setVisibleInDark(bool v);
	bool getVisibleInDark();

	void setCanLightItems(bool v);
	bool getCanLightItems();

	void setState(ItemState s);
	ItemState getState();

	bool isPickStoreLight();

	void setRoomLevel(int level);
	int getRoomLevel();

	virtual void picked();
	virtual void stored();
	virtual void wore();
	virtual void lighted();
	virtual void hanged();
	virtual void dropped();
	virtual void moved(int idx);
	virtual string read();
	virtual void displayDestinations();
	virtual Item* getCurrentDestination();
	
protected:
	void removeActions();
	string _posDesc;
	vector<Action*> _actions = {};
	ItemState _state;
	vector<Item*> _holding = {};
	Item* _viewable;
	Item* _viewFrom;
	Item* _parent;
	bool _visibleInDark;
	bool _canLightItems;
	int _roomLevel;
};

#endif