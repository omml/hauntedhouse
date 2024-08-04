//
//  ActionHandler.h
//  Borley Rectory Haunted Mansion Text-Based Console Game
//
//  Created by Oscar Martinez on 09/07/2024.
//
#pragma once

#include "Inventory.h"
#include "Room.h"

class ActionHandler
{
public:
	ActionHandler();

	// General function to handle actions
	bool HandleAction(Room* r, Action* a, Item* item, Inventory* hand, Inventory* bag, Inventory* body, Inventory* container, string* m, int moveIdx);

	bool IsMovingAction(Action* a);
	bool IsPlacingAction(Action* a);
private:
	// Functions to handle actions
	bool HandlePickAction(Room* r, Action* a, Item* item, Inventory* hand, Inventory* bag, Inventory* body, Inventory* container, string* m, int moveIdx);
	bool HandleStoreAction(Room* r, Action* a, Item* item, Inventory* hand, Inventory* bag, Inventory* body, Inventory* container, string* m, int moveIdx);
	bool HandleDropAction(Room* r, Action* a, Item* item, Inventory* hand, Inventory* bag, Inventory* body, Inventory* container, string* m, int moveIdx);
	bool HandleWearAction(Room* r, Action* a, Item* item, Inventory* hand, Inventory* bag, Inventory* body, Inventory* container, string* m, int moveIdx);
	bool HandleMoveAction(Room* r, Action* a, Item* item, Inventory* hand, Inventory* bag, Inventory* body, Inventory* container, string* m, int moveIdx);
	bool HandleLightAction(Room* r, Action* a, Item* item, Inventory* hand, Inventory* bag, Inventory* body, Inventory* container, string* m, int moveIdx);
	bool HandleReadAction(Room* r, Action* a, Item* item, Inventory* hand, Inventory* bag, Inventory* body, Inventory* container, string* m, int moveIdx);
	bool HandleClimbAction(Room* r, Action* a, Item* item, Inventory* hand, Inventory* bag, Inventory* body, Inventory* container, string* m, int moveIdx);
	bool HandleInspectAction(Room* r, Action* a, Item* item, Inventory* hand, Inventory* bag, Inventory* body, Inventory* container, string* m, int moveIdx);
	bool HandlePlaceInsideAction(Room* r, Action* a, Item* item, Inventory* hand, Inventory* bag, Inventory* body, Inventory* container, string* m, int moveIdx);
};

