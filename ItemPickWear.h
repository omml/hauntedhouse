//
//  ItemPickWear.h
//  Borley Rectory Haunted Mansion Text-Based Console Game
//
//  Created by Oscar Martinez on 21/03/2024.
//
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

