#pragma once
#include "Item.h"
class ItemMove : public Item
{
public:
	ItemMove(const string name, const string desc, const string pd);

	void setDestination(Item* d);
	void displayDestinations() override;
	void moved(int idx) override;
	Item* getCurrentDestination() override;

private:
	vector<Item*> _destinations = {};
	Item* _currentDest;
};

