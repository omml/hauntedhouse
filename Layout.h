//
//  Layout.h
//  Borley Rectory Haunted Mansion Text-Based Console Game
//
//  Created by Oscar Martinez on 21/03/2024.
//
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

