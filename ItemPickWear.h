#pragma once
#include "ItemPick.h"
class ItemPickWear : public ItemPick
{
public:
	ItemPickWear(string name, string desc, string dp);

	void picked() override;
	void wore() override;
	void hanged() override;
};

