//
//  ItemPickStore.h
//  Borley Rectory Haunted Mansion Text-Based Console Game
//
//  Created by Oscar Martinez on 21/03/2024.
//
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

