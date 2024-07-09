//
//  Room.h
//  Borley Rectory Haunted Mansion Text-Based Console Game
//
//  Created by Oscar Martinez on 21/03/2024.
//
#pragma once

#include <vector>

#include "Item.h"
#include "MainObject.h"

using namespace std;

class Room : public MainObject
{
public:
	Room(const string name, const string desc);

    Room* getLinkedRoom(int index);
    void setLinkedRoom(int index, Room* r);

    Room* getSmallPassage(int index);
    void setSmallPassage(int index, Room* r);
    void setItem(Item* i);
    Item* getItem(int idx);
    int getNumItems();
    void removeItem(Item* i);

    void displayRooms();
    void displayItems();

    bool isThereCandleLighted();
    string getIsDarkDescription();

    void setIsLighted(bool v, bool cc);
    void hasDroppedCandle(Item* i);

    //TO DO: add set and get functions for items and add code to cpp file

private:
    Room* _linkedRooms[4];
    Room* _smallPassage[4];

    //TO DO: add a container for the room items
    vector<Item*> _items = {};

    string DirectionNames[4] = { "North", "West", "South", "East" };

    bool _isLighted = false;
    bool _carryingCandle = false;
};

