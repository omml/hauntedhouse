//
//  GUIHandler.h
//  Borley Rectory Haunted Mansion Text-Based Console Game
//
//  Created by Oscar Martinez on 10/07/2024.
//
#pragma once
#include "ActionHandler.h"
#include "CommonDefinitions.h"

class GUIHandler
{
public:
	GUIHandler();
	int DisplayGUI(ActionHandler* actionHandler, Room* currentRoom, Room* next, Inventory* hands, Inventory* bag, Inventory* body, Item* currentItem, Item* climbedItem);
private:
	GUIState guiState;
	int mainOption;
	int moveOption;
	int exploreOption;
	int itemOption;
	int selectInventoryOption;
	int inventoryOption;
	string message;
	int numItems;
};

