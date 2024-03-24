#pragma once
#include "ItemPick.h"

class ItemPickStore : public ItemPick
{
public:
	ItemPickStore(string name, string desc, string dp);

	void picked() override;
	void stored() override;
	void dropped() override;
};

