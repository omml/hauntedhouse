//
//  ItemContainer.h
//  Borley Rectory Haunted Mansion Text-Based Console Game
//
//  Created by Oscar Martinez on 31/07/2024.
//
#pragma once
#include "Item.h"
#include "Inventory.h"
class ItemContainer : public Item
{
private:
	Inventory* _itemsInside;
public:
	ItemContainer(const string name, const string desc, const string pd);
	bool setItemInside(Item* item, string* m);
	Item* getItemInside(int idx);
	int getNumItemsInside();
	void displayItems();
	void displayItemsNameDesc();
	Inventory* getContainer();
};

