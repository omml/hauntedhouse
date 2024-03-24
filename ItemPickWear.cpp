#include "ItemPickWear.h"
#include "ActionWear.h"
#include "ActionDrop.h"
#include "ActionPick.h"

ItemPickWear::ItemPickWear(string name, string desc, string dp) : ItemPick(name, desc, dp)
{

}

void ItemPickWear::picked()
{
	ItemPick::picked();

	setAction(new ActionWear());

	if (_parent != nullptr)
	{
		_parent->removeHoldingItem(this);
	}
}

void ItemPickWear::wore()
{
	removeActions();

	setAction(new ActionDrop());

	_state = Wore;
}

void ItemPickWear::hanged()
{
	removeActions();

	setAction(new ActionPick());

	_state = Hanged;
}
