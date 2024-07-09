//
//  ItemPickStoreLight.cpp
//  Borley Rectory Haunted Mansion Text-Based Console Game
//
//  Created by Oscar Martinez on 21/03/2024.
//
#include "ActionDrop.h"
#include "ActionLight.h"
#include "ActionPick.h"
#include "ActionStore.h"
#include "ItemPickStoreLight.h"

ItemPickStoreLight::ItemPickStoreLight(const string name, const string desc, const string dp) : ItemPickStore(name, desc, dp)
{
	setAction(new ActionLight());
}


void ItemPickStoreLight::lighted()
{
	ItemPickStore::dropped();

	setState(Lighted);
}

void ItemPickStoreLight::picked()
{
	ItemState tmpState = _state;

	ItemPickStore::picked();

	if (tmpState == Lighted)
	{
		setState(Lighted);
	}
}

void ItemPickStoreLight::dropped()
{
	ItemState tmpState = _state;

	ItemPickStore::dropped();

	if (tmpState == Lighted)
	{
		setState(Lighted);
	}
	else
	{
		setAction(new ActionLight());
	}
}

void ItemPickStoreLight::stored()
{
	ItemPickStore::stored();

	setState(Stored);
}


