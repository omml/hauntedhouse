//
//  GameState.h
//  Borley Rectory Haunted Mansion Text-Based Console Game
//
//  Created by Oscar Martinez on 21/03/2024.
//
#pragma once

#include "Room.h"
#include "Inventory.h"

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
	Item* getClimbedItem();

private:
	Room* _currentRoom;
	int _currentRoomLevel;
	Item* _climbedItem;
};

