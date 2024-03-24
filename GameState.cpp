#include "GameState.h"

GameState::GameState()
{
	_currentRoom = nullptr;
	_currentRoomLevel = 0;
}

GameState& GameState::getInstance()
{
	static GameState instance;
	return instance;
}

void GameState::setCurrentRoom(Room* r, Inventory* i)
{
	bool isCarryingLightedCandle = i->isThereCandleLighted();

	_currentRoom = r;

	if (isCarryingLightedCandle == true)
	{
		_currentRoom->setIsLighted(false, false);
		r->setIsLighted(true, true);
	}
}

Room* GameState::getCurrentRoom()
{
	return _currentRoom;
}

void GameState::setCurrentRoomLevel(int level)
{
	_currentRoomLevel = level;
}

int GameState::getCurrentRoomLevel()
{
	return _currentRoomLevel;
}

void GameState::setClimbedItem(Item* i)
{
	if (_climbedItem != nullptr)
	{
		_currentRoomLevel = 1;
	}
	else
	{
		_currentRoomLevel = 0;
	}
	_climbedItem = i;
}

Item* GameState::getClimbedItem()
{
	return _climbedItem;
}