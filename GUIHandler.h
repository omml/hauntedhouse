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
	int inspectOption;
	int itemOption;
	int actionOption;
	int selectInventoryOption;
	int inventoryOption;
	string message;
	int numItems;

	void DisplayMainGUI();
	void DisplayMoveGUI(ActionHandler* actionHandler, Room* currentRoom, Room* next, Inventory* hands, Inventory* bag, Inventory* body, Item* currentItem, Item* climbedItem);
	void DisplayExploreGUI(ActionHandler* actionHandler, Room* currentRoom, Room* next, Inventory* hands, Inventory* bag, Inventory* body, Item* currentItem, Item* climbedItem);
	void DisplayItemGUI(ActionHandler* actionHandler, Room* currentRoom, Room* next, Inventory* hands, Inventory* bag, Inventory* body, Item* currentItem, Item* climbedItem);
	void DisplayMovingGUI(ActionHandler* actionHandler, Room* currentRoom, Room* next, Inventory* hands, Inventory* bag, Inventory* body, Item* currentItem, Item* climbedItem);
	void DisplaySelectInventoryGUI(ActionHandler* actionHandler, Room* currentRoom, Room* next, Inventory* hands, Inventory* bag, Inventory* body, Item* currentItem, Item* climbedItem);
	void DisplayInventoryGUI(ActionHandler* actionHandler, Room* currentRoom, Room* next, Inventory* hands, Inventory* bag, Inventory* body, Item* currentItem, Item* climbedItem);
	void DisplayInventoryItemGUI(ActionHandler* actionHandler, Room* currentRoom, Room* next, Inventory* hands, Inventory* bag, Inventory* body, Item* currentItem, Item* climbedItem);
	void DisplayContainerGUI(ActionHandler* actionHandler, Room* currentRoom, Room* next, Inventory* hands, Inventory* bag, Inventory* body, Item* currentItem, Item* climbedItem);
	void DisplayContainerItemGUI(ActionHandler* actionHandler, Room* currentRoom, Room* next, Inventory* hands, Inventory* bag, Inventory* body, Item* currentItem, Item* climbedItem);
	void DisplayPlaceItemGUI(ActionHandler* actionHandler, Room* currentRoom, Room* next, Inventory* hands, Inventory* bag, Inventory* body, Item* currentItem, Item* climbedItem);
};

