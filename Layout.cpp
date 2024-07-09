//
//  Layout.cpp
//  Borley Rectory Haunted Mansion Text-Based Console Game
//
//  Created by Oscar Martinez on 21/03/2024.
//
#include "ActionClimb.h"
#include "ActionMove.h"
#include "ActionPick.h"
#include "ActionStore.h"
#include "ActionWear.h"
#include "CommonDefinitions.h"
#include "Item.h"
#include "ItemMoveClimb.h"
#include "ItemPickStoreLight.h"
#include "ItemPickStoreRead.h"
#include "ItemPickWear.h"
#include "Layout.h"

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
	Room* porch = new Room("Porch", "A small, sheltered area that serves as the threshold to Borley Rectory. The wooden floorboards creak underfoot, and ivy-clad walls frame the entrance. The air is cooler here, carrying a faint, musty scent. As you take in the surroundings, you notice the overgrown garden beyond, its shadows deepening with the setting sun. A subtle chill runs down your spine, and you can't shake the feeling that unseen eyes are watching from the darkened windows above.");
	Room* corr1 = new Room("Corridor 1", "The walls are lined with dark, aged wood paneling, and the floor is covered in a faded runner rug that muffles your footsteps. Dim, flickering light from an old wall sconce casts long shadows, making the space feel even narrower. The air is cool and carries a hint of dampness. As you move down the corridor, the silence is occasionally broken by distant, unexplained creaks and the faint whisper of a draft, heightening the sense of unease.");
	Room* dinn = new Room("Dinning Room", "Frozen in time with cobweb-covered chandeliers. Portraits of previous rectors and their families stare down at you from the walls. The air is thick with tension, and you can almost hear the faint sound of disembodied footsteps echoing through the room. Occasionally, a chair seems to move ever so slightly.");
	Room* hall = new Room("Hall", "A grand yet foreboding space. High ceilings loom above, and dark wood paneling lines the walls. A large staircase ascends to the upper floors, casting long shadows. The atmosphere feels oppressively heavy, as if the air itself bears witness to countless untold stories..");
	Room* study = new  Room("Study", "A smaller, more intimate room filled with bookshelves and a large writing desk. This was where the rector conducted his work, and the air still carries a sense of solemn purpose. As you explore, you notice strange writing on the walls, difficult to decipher, appearing as if from nowhere.");
	Room* corr2 = new Room("Corridor 2", "The floor creaks underfoot. The walls are lined with faded wallpaper. The air is cool and carries a faint musty scent. Every step echoes slightly, amplifying the unsettling quiet that envelops you.");
	Room* draw = new Room("Drawing Room", "A spacious area intended for entertaining guests. Large windows overlook the garden, and Victorian-era sofas and armchairs invite you to sit. Despite its welcoming appearance, the room feels chilly. An inexplicable cold spot sends shivers down your spine, and you have the unsettling feeling that you're not alone.");
	Room* pantry1 = new Room("Pantry 1", "The room has a utilitarian feel, with a single dim light bulb casting a yellowish glow. The air is cool and slightly damp, carrying the faint scent of preserved food and spices. Occasionally, you hear the soft rustle of something moving in the shadows, but when you look, the room appears empty.");
	Room* pantry2 = new Room("Pantry 2", "A small and cramped. The shelves are packed tightly with various kitchen supplies and older, dust-covered jars. The light is dimmer, with shadows lurking in every corner. The air feels colder here, with an almost tangible sense of neglect. A slight draft stirs the dust, making it difficult to shake the feeling that you're not alone.");
	Room* kitpass = new Room("Kitchen Passage", "The walls are lined with worn, pale tiles, and the floor is covered with scuffed linoleum. The passage is dimly lit by a single overhead light, casting long, eerie shadows. The air is filled with the faint smell of cooking and something slightly sour. Your footsteps echo softly, amplifying the sense of isolation as you make your way toward the kitchen.");
	Room* couyar = new Room("Courtyard", "Overgrown ivy clings to the stone, and patches of moss cover the ground. In the center, a neglected fountain stands, its water long since dried up, now home to a few stray plants. The air is cool and fresh, but a sense of abandonment lingers. Weeds push through the cracked cobblestones, and the faint rustle of leaves is the only sound that breaks the silence. As you look around, the surrounding windows of the rectory seem to watch you, adding to the uneasy feeling that you're never truly alone here.");
	Room* kitchen = new Room("Kitchen", "A bustling center of past activity. A large stove dominates one side, and numerous cupboards line the walls. Despite its mundane function, the kitchen feels oddly alive. Shadowy figures seem to flit at the edge of your vision, and you catch the faint scent of floral perfume that has no apparent source.");

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
	pantry1->setItem(pan1Matches);
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
