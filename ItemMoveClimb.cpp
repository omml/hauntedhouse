//
//  ItemMoveClimb.cpp
//  Borley Rectory Haunted Mansion Text-Based Console Game
//
//  Created by Oscar Martinez on 21/03/2024.
//
#include "ActionClimb.h"
#include "ItemMoveClimb.h"

ItemMoveClimb::ItemMoveClimb(const string name, const string desc, const string dp) : ItemMove(name, desc, dp)
{
	setAction(new ActionClimb());
}
