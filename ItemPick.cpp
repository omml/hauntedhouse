//
//  ItemPick.cpp
//  Borley Rectory Haunted Mansion Text-Based Console Game
//
//  Created by Oscar Martinez on 21/03/2024.
//
#include "ActionDrop.h"
#include "ActionPick.h"
#include "ItemPick.h"

ItemPick::ItemPick(string name, string desc, string dp) : Item(name, desc, dp)
{
	setAction(new ActionPick());
}

void ItemPick::picked()
{
	removeActions();

	_posDesc = "";

	setAction(new ActionDrop());

	setState(Picked);
}


void ItemPick::dropped()
{
	removeActions();
	setAction(new ActionPick());

	setState(Dropped);
}
