#include "ItemMoveClimb.h"
#include "ActionClimb.h"

ItemMoveClimb::ItemMoveClimb(const string name, const string desc, const string dp) : ItemMove(name, desc, dp)
{
	setAction(new ActionClimb());
}
