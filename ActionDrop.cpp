//
//  ActionDrop.cpp
//  Borley Rectory Haunted Mansion Text-Based Console Game
//
//  Created by Oscar Martinez on 21/03/2024.
//
#include "ActionDrop.h"

ActionDrop::ActionDrop() : Action("Drop", "Drops an item")
{
	_actionId = AIDDrop;
}