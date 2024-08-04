//
//  ItemContainer.cpp
//  Borley Rectory Haunted Mansion Text-Based Console Game
//
//  Created by Oscar Martinez on 31/07/2024.
//
#include "ItemContainer.h"
#include "ActionInspect.h"
#include "ActionPlaceInside.h"

ItemContainer::ItemContainer(const string name, const string desc, const string pd) : Item(name, desc, pd)
{
	setAction(new ActionInspect());
	setAction(new ActionPlaceInside());
	_itemsInside = new Inventory(name, 30, false);
}

Inventory* ItemContainer::getContainer()
{
	return _itemsInside;
}

bool ItemContainer::setItemInside(Item* item, string* m)
{
	return _itemsInside->addItem(item, m);
}

Item* ItemContainer::getItemInside(int idx)
{
	return _itemsInside->getItem(idx);
}

int ItemContainer::getNumItemsInside()
{
	return _itemsInside->getNumItems();
}

void ItemContainer::displayItems()
{
	_itemsInside->displayInventory();
}

void ItemContainer::displayItemsNameDesc()
{
	_itemsInside->displayInventoryNameDesc();
}
