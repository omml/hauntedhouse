#include "Layout.h"
#include "CommonDefinitions.h"
#include "Item.h"
#include "ActionPick.h"
#include "ActionStore.h"
#include "ActionWear.h"
#include "ActionMove.h"
#include "ActionClimb.h"
#include "ItemPickStoreLight.h"
#include "ItemPickWear.h"
#include "ItemMoveClimb.h"
#include "ItemPickStoreRead.h"


Layout::Layout() 
{
	//Define Actions
	/*
	Action* aHit;// = new Action("Hit", "Hits with an item");
	Action* aCook;// = new Action("Cook", "Cooks an item");
	Action* aLight;// = new Action("Lights", "Lights an item");
	Action* aOpen;// = new Action("Open", "Opens an item");
	Action* aClimb;// = new Action("Climb", "Climbs an item");
	*/
	
	//Fight?
	//Paint what?
	//Dig?
	//Pour what on what
	//string ActionNames[] = { "Pick", "Hit", "Cook", "Move", "Fight", "Light", "Paint", "LookAt", "Dig", "Climb", "Pour", "Open" };



	//Define Rooms
	Room* porch = new Room("Porch", "Description");
	Room* corr1 = new Room("Corridor 1", "Description");
	Room* dinn = new Room("Dinning Room", "Description");
	Room* hall = new Room("Hall", "Description");
	Room* study = new  Room("Study", "Description");
	Room* corr2 = new Room("Corridor 2", "Description");
	Room* draw = new Room("Drawing Room", "Description");
	Room* pantry1 = new Room("Pantry 1", "Description");
	Room* pantry2 = new Room("Pantry 2", "Description");
	Room* kitpass = new Room("Kitchen Passage", "Description");
	Room* couyar = new Room("Courtyard", "Description");
	Room* kitchen = new Room("Kitchen", "Description");

	porch->setLinkedRoom(North, corr1);

	corr1->setLinkedRoom(North, hall);
	corr1->setLinkedRoom(East, kitpass);
	corr1->setLinkedRoom(South, porch);
	corr1->setLinkedRoom(West, dinn);
	//For rat
	corr1->setSmallPassage(North, hall);
	corr1->setSmallPassage(East, kitpass);
	corr1->setSmallPassage(West, dinn);

	dinn->setLinkedRoom(East, corr1);
	//for rat
	dinn->setSmallPassage(North, study);
	dinn->setSmallPassage(East, corr1);
	
	hall->setLinkedRoom(North, corr2);
	hall->setLinkedRoom(South, corr1);
	hall->setLinkedRoom(West, study);
	//for rat
	hall->setSmallPassage(North, corr2);
	hall->setSmallPassage(East, couyar);
	hall->setSmallPassage(South, corr1);
	hall->setSmallPassage(West, study);

	study->setLinkedRoom(East, hall);
	//for rat
	study->setSmallPassage(North, draw);
	study->setSmallPassage(East, hall);
	study->setSmallPassage(South, dinn);
	
	corr2->setLinkedRoom(North, pantry1);
	corr2->setLinkedRoom(East, pantry2);
	corr2->setLinkedRoom(South, hall);
	corr2->setLinkedRoom(West, draw);
	//for rat
	corr2->setSmallPassage(North, pantry1);
	corr2->setSmallPassage(East, pantry2);
	corr2->setSmallPassage(South, hall);
	corr2->setSmallPassage(West, draw);
	
	draw->setLinkedRoom(East, corr2);
	//for rat
	draw->setSmallPassage(East, corr2);
	draw->setSmallPassage(South, study);
	
	pantry1->setLinkedRoom(South, corr2);
	//for rat
	pantry1->setSmallPassage(South, corr2);
	
	pantry2->setLinkedRoom(West, corr2);
	//for rat
	pantry2->setSmallPassage(West, corr2);

	kitpass->setLinkedRoom(North, couyar);
	kitpass->setLinkedRoom(East, kitchen);
	kitpass->setLinkedRoom(West, corr1);
	//for rat
	kitpass->setSmallPassage(North, couyar);
	kitpass->setSmallPassage(East, kitchen);
	kitpass->setSmallPassage(West, corr1);

	couyar->setLinkedRoom( South, kitpass);
	//for rat
	couyar->setSmallPassage(South, kitpass);
	couyar->setSmallPassage(West, hall);
	
	kitchen->setLinkedRoom( West, kitpass);
	//for rat
	kitchen->setSmallPassage(West, kitpass);

	//Add items to the corridor 1
	Item* corr1Candle = new ItemPickStoreLight("Candlestick", "A candlestick with candles", "On the West wall in top of the small table");
	corr1->setItem(corr1Candle);
	corr1Candle->setVisibleInDark(true);

	Item* corr1Stand = new Item("Coat Stand", "A coat stand", "On the East wall");
	corr1Stand->setAction(new ActionPick());
	corr1->setItem(corr1Stand);

	Item* corr1Umb = new ItemPick("Umbrella", "An old umbrella", "On the East wall next to the coat stand");
	corr1->setItem(corr1Umb);

	Item* corr1Coat = new ItemPickWear("Coat", "An old coat", "On the East wall hanging on the to the coat stand");
	corr1->setItem(corr1Coat);
	corr1Coat->setParent(corr1Stand);

	Item* corr1Hat = new ItemPickWear("Hat", "An old hat", "On the East wall hanging on the to the coat stand");
	corr1->setItem(corr1Hat);
	corr1Hat->setParent(corr1Stand);

	Item* dinPortrait = new Item("Portrait", "A portrait of the house owner", "On the East wall on top of the fireplace");
	dinn->setItem(dinPortrait);
	Item* dinNote = new ItemPickStoreRead("Note", "A note", "A note next to the Portrait", "Look for the book <Enchantment of the OtherWorlds: Potions from Centures Past>");
	dinNote->setRoomLevel(1);
	dinPortrait->setViewableItem(dinNote);
	dinn->setItem(dinNote);

	Item* dinTable = new Item("Dinning Table", "An old dinning table", "On the center of the room");
	dinn->setItem(dinTable);

	//Add matches to pantry, set them so they are visible in dark and can light items
	Item* pan1Matches = new ItemPickStore("Matches", "Old matches", "On a shelve on the west wall");
	pan1Matches->setVisibleInDark(true);
	pan1Matches->setCanLightItems(true);
	//pantry1->setItem(pan1Matches);
	corr1->setItem(pan1Matches);
	//Add variable to change from dark to lighted when carrying the candle lighted
	//Do not display all items if it is not lighted

	//Add items to the dinning room
	ItemMoveClimb* dinChair = new ItemMoveClimb("Chair", "A comfortable chair", "In front of the table");
	dinChair->setDestination(dinPortrait);
	dinChair->setDestination(dinTable);
	dinChair->moved(1);
	dinn->setItem(dinChair);

	
	//TO DO: store the references to the items

	_roomList.push_back(porch);
	_roomList.push_back(corr1);
	_roomList.push_back(dinn);
	_roomList.push_back(hall);
	_roomList.push_back(study);
	_roomList.push_back(corr2);
	_roomList.push_back(draw);
	_roomList.push_back(pantry1);
	_roomList.push_back(pantry2);
	_roomList.push_back(kitpass);
	_roomList.push_back(couyar);
	_roomList.push_back(kitchen);
}

Room* Layout::getFirstRoom()
{
	return _roomList[0];
}
