#pragma once

#include <vector>
#include "Room.h"

using namespace std;

class Layout
{
public:
	Layout();
	Room* getFirstRoom();

private: 
	vector<Room*> _roomList = {};
};

