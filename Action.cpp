#include "Item.h"
#include "Action.h"

Action::Action(const string name, const string desc) : MainObject(name, desc)
{

}

void Action::setReceiver(Item* r)
{
	_posibleReceivers.push_back(r);
}