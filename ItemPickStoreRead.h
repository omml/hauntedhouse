//
//  ItemPickStoreRead.h
//  Borley Rectory Haunted Mansion Text-Based Console Game
//
//  Created by Oscar Martinez on 21/03/2024.
//
#pragma once
#include "ItemPickStore.h"

class ItemPickStoreRead : public ItemPickStore
{
public:
	ItemPickStoreRead(const string name, const string desc, const string dp, const string info);

	void setText(string i);

	void picked() override;
	void stored() override;
	string read() override;
	
private:
	string _text;
};

