//
//  ItemPickStoreLight.h
//  Borley Rectory Haunted Mansion Text-Based Console Game
//
//  Created by Oscar Martinez on 21/03/2024.
//
#pragma once
#include "ItemPickStore.h"

class ItemPickStoreLight : public ItemPickStore
{
public:
	ItemPickStoreLight(const string name, const string desc, const string dp);

	void lighted() override;
	void picked() override;
	void dropped() override;
	void stored() override;
};

