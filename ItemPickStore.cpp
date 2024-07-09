//
//  ItemPickStore.cpp
//  Borley Rectory Haunted Mansion Text-Based Console Game
//
//  Created by Oscar Martinez on 21/03/2024.
//
#include "ActionDrop.h"
#include "ActionPick.h"
#include "ActionStore.h"
#include "ItemPickStore.h"

ItemPickStore::ItemPickStore(string name, string desc, string dp) : ItemPick(name, desc, dp)
{
	setAction(new ActionStore());
}

void ItemPickStore::picked()
{
	ItemPick::picked();

	setAction(new ActionStore());
}

void ItemPickStore::stored()
{
	_posDesc = "";

	removeActions();
	setAction(new ActionPick());
	setAction(new ActionDrop());

	setState(Stored);
}

void ItemPickStore::dropped()
{
	ItemPick::dropped();

	setAction(new ActionStore());
}

