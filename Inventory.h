//
//  Inventory.cpp
//  Borley Rectory Haunted Mansion Text-Based Console Game
//
//  Created by Pei WANG on 21/03/2024.
//  Modified by Oscar Martinez 22/03/2024 and later
//

#pragma once

#include <iostream>
#include <vector>

#include "Item.h"

using namespace std;

class Inventory
{

public:
	//  constructors
	Inventory(string n, int c, bool p);

	//  check if inventory is full
	bool isFull();

	//  check if inventory is empty
	bool isEmpty();

	//  display inventory content
	void displayInventory();

	//  Find an item in inventory and return position if available
	bool findInventory(Item* itemPtr);

	//  add item to inventory
	bool addItem(Item* itemPtr, string* m);
	Item* getItem(int idx);
	int getNumItems();

	//  remove item from inventory
	void removeItem(Item* itemPtr);

	bool isThereCandleLighted();
	bool isThereCandle();
	bool areThereMatches();

private:
	string _name;

	vector<Item*> _container = {};

	int _capacity;

	int _itemPosn = 0;
	bool _pick;
};
