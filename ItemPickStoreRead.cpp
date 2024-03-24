#include "ItemPickStoreRead.h"
#include "ActionRead.h"

ItemPickStoreRead::ItemPickStoreRead(const string name, const string desc, const string dp, const string info) : ItemPickStore(name, desc, dp)
{
	_text = info;
}

void ItemPickStoreRead::setText(string info)
{
	_text = info;
}

void ItemPickStoreRead::picked()
{
	ItemPickStore::picked();

	setAction(new ActionRead());

	setRoomLevel(0);

	if (_viewFrom != nullptr)
	{
		_viewFrom->removeViewableItem();
		removeViewFromItem();
	}
}

void ItemPickStoreRead::stored()
{
	ItemPickStore::stored();

	if (_viewFrom != nullptr)
	{
		_viewFrom->removeViewableItem();
		removeViewFromItem();
	}
}

string ItemPickStoreRead::read()
{
	return "'"+ _name + "' text: " + _text;
}

