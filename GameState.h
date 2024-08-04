//
//  GameState.h
//  Borley Rectory Haunted Mansion Text-Based Console Game
//
//  Created by Oscar Martinez on 21/03/2024.
//
#pragma once

#include "Inventory.h"
#include "Room.h"

class GameState
{
public:
	static GameState& getInstance();

	GameState();

	void setCurrentRoom(Room* r, Inventory* i);
	Room* getCurrentRoom();

	void setCurrentRoomLevel(int level);
	int getCurrentRoomLevel();

	void setClimbedItem(Item* i);
	void setInspectingItem(bool inspecting, Item* i);
	Item* getInspectingItem();
	Item* getClimbedItem();

private:
	Room* _currentRoom;
	int _currentRoomLevel;
	Item* _climbedItem;
	bool _isInspecting;
	Item* _inspectingItem;
};

