#pragma once
#include "Item.h"
class ItemPick : public Item
{
public:
	ItemPick(string name, string desc, string dp);

	void picked() override;
	void dropped() override;

};

