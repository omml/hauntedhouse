#include "ItemPick.h"
#include "ActionPick.h"
#include "ActionDrop.h"

ItemPick::ItemPick(string name, string desc, string dp) : Item(name, desc, dp)
{
	setAction(new ActionPick());
}

void ItemPick::picked()
{
	removeActions();

	_posDesc = "";

	setAction(new ActionDrop());

	setState(Picked);
}


void ItemPick::dropped()
{
	removeActions();
	setAction(new ActionPick());

	setState(Dropped);
}
