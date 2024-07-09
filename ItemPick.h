//
//  ItemPick.h
//  Borley Rectory Haunted Mansion Text-Based Console Game
//
//  Created by Oscar Martinez on 21/03/2024.
//
#pragma once
#include "Item.h"

class ItemPick : public Item
{
public:
	ItemPick(string name, string desc, string dp);

	void picked() override;
	void dropped() override;

};

