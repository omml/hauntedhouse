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
#include "ItemContainer.h"

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

	string tmpString;


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

	//Add items to study room
	//Add bookshelf on the left 
	ItemContainer* bookShelf1 = new ItemContainer("Bookshelf", "An old but full bookshelf", "On the left wall");
	study->setItem(bookShelf1);
	//Add books to left wall bookshelf
	Item* bookShelf1Book = new ItemPickStoreRead("Book", "The Haunted Lullabies: Songs of the Damned", "", "Sing these cursed lullabies under the full moon to summon spirits. Beware, for not all spirits are friendly. The final lullaby calls forth the weeping woman, a ghost of tragedy.");
	bookShelf1->setItemInside(bookShelf1Book, &tmpString);
	bookShelf1Book = new ItemPickStoreRead("Book", "Cryptic Runes: Deciphering the Symbols of Darkness", "", "These ancient runes, when inscribed in blood, unlock hidden doors to realms best left unexplored. Each rune holds a different power, but deciphering them wrong can bring about untold horrors.");
	bookShelf1->setItemInside(bookShelf1Book, &tmpString);
	bookShelf1Book = new ItemPickStoreRead("Book", "Wendigo Tales: Encounters in the Frozen North", "", "Detailed accounts of explorers who ventured into the icy wilderness and encountered the Wendigo. These stories serve as warnings of the beast’s insatiable hunger for human flesh.");
	bookShelf1->setItemInside(bookShelf1Book, &tmpString);
	bookShelf1Book = new ItemPickStoreRead("Book", "Phantom Shadows: Ghosts of the Forgotten Asylum", "", "Stories of patients who died under mysterious circumstances. Their restless spirits now haunt the corridors, seeking revenge on those who wronged them.");
	bookShelf1->setItemInside(bookShelf1Book, &tmpString);
	bookShelf1Book = new ItemPickStoreRead("Book", "Demonic Incantations: Words of Power", "", "Chant these ancient incantations to call upon demonic entities. Each spell has a unique effect, but be cautious; demons are notorious tricksters.");
	bookShelf1->setItemInside(bookShelf1Book, &tmpString);
	bookShelf1Book = new ItemPickStoreRead("Book", "The Cursed Relics: Artifacts of Malevolence", "", "A catalog of cursed artifacts found across the globe. Each relic brings misfortune to its possessor, from causing madness to summoning malevolent spirits.");
	bookShelf1->setItemInside(bookShelf1Book, &tmpString);
	bookShelf1Book = new ItemPickStoreRead("Book", "Twisted Fairytales: Stories to Terrorize", "", "Classic fairytales reimagined with dark twists. Happy endings are rare, and the creatures of these stories are more sinister than they appear.");
	bookShelf1->setItemInside(bookShelf1Book, &tmpString);
	bookShelf1Book = new ItemPickStoreRead("Book", "Nightmares of the Deep: Sea Monsters and Specters", "", "Tales of sailors encountering horrific creatures beneath the waves. The Kraken, ghost ships, and cursed treasures lurk in these stories, waiting to drag the unwary to their doom.");
	bookShelf1->setItemInside(bookShelf1Book, &tmpString);
	bookShelf1Book = new ItemPickStoreRead("Book", "Enchantment of the OtherWorlds: Potions from Centuries Past", "", "Gather spider blood, cockroach legs, and avocado leaves. Put cooking oil in a frying pan, fry for 20 minutes. Empty result into a molcajete to crush and grind. Use resulting paste to paint; strange things can happen depending on what you paint.");
	bookShelf1->setItemInside(bookShelf1Book, &tmpString);
	bookShelf1Book = new ItemPickStoreRead("Book", "Forbidden Rituals: Ceremonies of the Damned", "", "Descriptions of occult rituals performed by secret cults. Performing these rituals grants power at a terrible price, often requiring blood sacrifices and eternal servitude.");
	bookShelf1->setItemInside(bookShelf1Book, &tmpString);
	bookShelf1Book = new ItemPickStoreRead("Book", "The Whispering Woods: Legends of Forest Spirits", "", "Folklore about spirits dwelling in dark forests. They lure travelers off the path, leading them to their doom. Some stories tell of ways to appease these spirits and gain their favor.");
	bookShelf1->setItemInside(bookShelf1Book, &tmpString);
	bookShelf1Book = new ItemPickStoreRead("Book", "Vampire Chronicles: The Bloodthirsty Night", "", "Accounts of vampire sightings and attacks throughout history. Details on vampire hunters and methods to ward off these bloodthirsty creatures.");
	bookShelf1->setItemInside(bookShelf1Book, &tmpString);
	bookShelf1Book = new ItemPickStoreRead("Book", "The Unseen Watchers: Tales of Invisible Stalkers", "", "Chilling stories of entities that cannot be seen by the naked eye but leave behind evidence of their presence. Victims often go mad, driven by the feeling of being watched.");
	bookShelf1->setItemInside(bookShelf1Book, &tmpString);
	bookShelf1Book = new ItemPickStoreRead("Book", "The Dark Carnival: Spectacles of Horror", "", "Accounts of a traveling carnival that appears without warning. Each attraction holds a deadly secret, and visitors often leave changed or do not leave at all.");
	bookShelf1->setItemInside(bookShelf1Book, &tmpString);
	bookShelf1Book = new ItemPickStoreRead("Book", "Possessed Dolls: Playthings of the Damned", "", "Stories of dolls possessed by malevolent spirits. These cursed toys bring misfortune and death to their owners, often moving on their own and whispering dark secrets.");
	bookShelf1->setItemInside(bookShelf1Book, &tmpString);
	bookShelf1Book = new ItemPickStoreRead("Book", "Lich's Grimoire: Secrets of Undeath", "", "A guide to becoming a lich, an undead sorcerer with immense power. The transformation requires dark rituals and the sacrifice of one's humanity.");
	bookShelf1->setItemInside(bookShelf1Book, &tmpString);
	bookShelf1Book = new ItemPickStoreRead("Book", "Shadow Beasts: Predators of the Darkness", "", "Descriptions of nocturnal creatures that hunt in the shadows. These beasts are nearly invisible in the dark and are attracted to fear and blood.");
	bookShelf1->setItemInside(bookShelf1Book, &tmpString);
	bookShelf1Book = new ItemPickStoreRead("Book", "The Bone Collector: Stories of Grave Robbers", "", "Tales of grave robbers who disturbed the dead and faced horrific consequences. The dead do not rest easy, and their wrath is terrifying.");
	bookShelf1->setItemInside(bookShelf1Book, &tmpString);
	bookShelf1Book = new ItemPickStoreRead("Book", "Eyewitness Accounts: Encounters with the Paranormal", "", "First-hand accounts of ghost sightings, poltergeist activity, and other paranormal phenomena. These stories provide chilling details of the unexplained.");
	bookShelf1->setItemInside(bookShelf1Book, &tmpString);
	bookShelf1Book = new ItemPickStoreRead("Book", "Hexes and Curses: Magic of Vengeance", "", "Instructions for casting powerful hexes and curses. These spells are intended to bring suffering to one's enemies but often backfire, bringing misfortune to the caster as well.");
	bookShelf1->setItemInside(bookShelf1Book, &tmpString);

	//Add bookshelf on the right wall
	ItemContainer* bookShelf2 = new ItemContainer("Bookshelf", "An old but full bookshelf", "On the right wall");
	study->setItem(bookShelf2);
	//Add books to the the right wall bookshelf
	Item* bookShelf2Book = new ItemPickStoreRead("Book", "Baking Delicious Pastries", "", "Combine flour, sugar, and butter in a bowl. Mix until dough forms. Roll out the dough, cut into shapes, and bake at 350°F for 15 minutes.");
	bookShelf2->setItemInside(bookShelf2Book, &tmpString);
	bookShelf2Book = new ItemPickStoreRead("Book", "Simple Soups and Stews", "", "Chop celery, carrots, and potatoes. Add to a pot with chicken broth. Simmer for 45 minutes until vegetables are tender.");
	bookShelf2->setItemInside(bookShelf2Book, &tmpString);
	bookShelf2Book = new ItemPickStoreRead("Book", "Perfect Pasta Dishes", "", "Boil pasta in salted water until al dente. In a separate pan, sauté garlic and tomatoes in olive oil. Combine with pasta and serve.");
	bookShelf2->setItemInside(bookShelf2Book, &tmpString);
	bookShelf2Book = new ItemPickStoreRead("Book", "Grilling Meats to Perfection", "", "Marinate chicken breasts in olive oil, lemon juice, and herbs. Grill over medium heat for 6-7 minutes per side until cooked through.");
	bookShelf2->setItemInside(bookShelf2Book, &tmpString);
	bookShelf2Book = new ItemPickStoreRead("Book", "Savory Stir-Fries", "", "Slice bell peppers, onions, and beef. Stir-fry in a hot pan with soy sauce and ginger for 5-7 minutes. Serve over rice.");
	bookShelf2->setItemInside(bookShelf2Book, &tmpString);
	bookShelf2Book = new ItemPickStoreRead("Book", "Homemade Bread Recipes", "", "Mix yeast, warm water, and sugar. Let sit until foamy. Add flour and salt, knead into dough. Let rise, then bake at 375°F for 30 minutes.");
	bookShelf2->setItemInside(bookShelf2Book, &tmpString);
	bookShelf2Book = new ItemPickStoreRead("Book", "Hearty Breakfast Ideas", "", "Whisk eggs with milk, salt, and pepper. Pour into a hot pan, add cheese and spinach. Cook until eggs are set.");
	bookShelf2->setItemInside(bookShelf2Book, &tmpString);
	bookShelf2Book = new ItemPickStoreRead("Book", "Delicious Desserts", "", "Melt chocolate in a double boiler. Dip strawberries in melted chocolate and place on parchment paper to cool.");
	bookShelf2->setItemInside(bookShelf2Book, &tmpString);
	bookShelf2Book = new ItemPickStoreRead("Book", "Healthy Smoothies", "", "Blend spinach, banana, and almond milk until smooth. Add ice cubes and blend again for a refreshing drink.");
	bookShelf2->setItemInside(bookShelf2Book, &tmpString);
	bookShelf2Book = new ItemPickStoreRead("Book", "Creative Salads", "", "Combine mixed greens, cherry tomatoes, and cucumbers in a bowl. Drizzle with olive oil and balsamic vinegar. Toss to coat.");
	bookShelf2->setItemInside(bookShelf2Book, &tmpString);
	bookShelf2Book = new ItemPickStoreRead("Book", "Tasty Tacos", "", "Cook ground beef with taco seasoning. Serve in taco shells with lettuce, cheese, and salsa.");
	bookShelf2->setItemInside(bookShelf2Book, &tmpString);
	bookShelf2Book = new ItemPickStoreRead("Book", "Appetizing Appetizers", "", "Wrap asparagus spears in prosciutto. Bake at 400°F for 10-12 minutes until prosciutto is crispy.");
	bookShelf2->setItemInside(bookShelf2Book, &tmpString);
	bookShelf2Book = new ItemPickStoreRead("Book", "Quick Snacks", "", "Spread peanut butter on celery sticks. Top with raisins for a healthy and fun snack.");
	bookShelf2->setItemInside(bookShelf2Book, &tmpString);
	bookShelf2Book = new ItemPickStoreRead("Book", "Exotic Curry Recipes", "", "Cook onions and garlic in oil until soft. Add curry powder and coconut milk. Simmer with chicken pieces for 20 minutes.");
	bookShelf2->setItemInside(bookShelf2Book, &tmpString);
	bookShelf2Book = new ItemPickStoreRead("Book", "Comfort Food Classics", "", "Layer sliced potatoes, cheese, and ham in a baking dish. Pour over cream and bake at 375°F for 45 minutes.");
	bookShelf2->setItemInside(bookShelf2Book, &tmpString);
	bookShelf2Book = new ItemPickStoreRead("Book", "Flavorful Fish Dishes", "", "Season salmon fillets with lemon, dill, and garlic. Bake at 400°F for 12-15 minutes until flaky.");
	bookShelf2->setItemInside(bookShelf2Book, &tmpString);
	bookShelf2Book = new ItemPickStoreRead("Book", "Refreshing Beverages", "", "Mix lemonade with iced tea in equal parts. Serve over ice with a slice of lemon.");
	bookShelf2->setItemInside(bookShelf2Book, &tmpString);

	//Add bookshelf on the right wall
	ItemContainer* bookShelf3 = new ItemContainer("Bookshelf", "An old but full bookshelf", "On the front wall");
	study->setItem(bookShelf3);
	//Add books to the the right wall bookshelf
	Item* bookShelf3Book = new ItemPickStoreRead("Book", "Digital Photography Basics", "", "Learn to use manual settings on your camera. Experiment with aperture, shutter speed, and ISO for creative effects.");
	bookShelf3->setItemInside(bookShelf3Book, &tmpString);
	bookShelf3Book = new ItemPickStoreRead("Book", "Basics of Calligraphy", "", "Start with simple strokes and basic letterforms. Practice consistency and fluidity with each letter.");
	bookShelf3->setItemInside(bookShelf3Book, &tmpString);
	bookShelf3Book = new ItemPickStoreRead("Book", "Introduction to Sculpting", "", "Begin with clay and simple tools. Focus on shaping basic forms before adding intricate details.");
	bookShelf3->setItemInside(bookShelf3Book, &tmpString);
	bookShelf3Book = new ItemPickStoreRead("Book", "Songwriting Essentials", "", "Write lyrics from personal experiences. Pair your lyrics with a simple chord progression to create a melody.");
	bookShelf3->setItemInside(bookShelf3Book, &tmpString);
	bookShelf3Book = new ItemPickStoreRead("Book", "Indoor Herb Gardening", "", "Plant herbs like basil, thyme, and mint in small pots. Place them on a sunny windowsill and water regularly.");
	bookShelf3->setItemInside(bookShelf3Book, &tmpString);
	bookShelf3Book = new ItemPickStoreRead("Book", "Understanding Abstract Art", "", "Explore the use of color, shape, and texture. Create art that expresses emotions rather than depicting reality.");
	bookShelf3->setItemInside(bookShelf3Book, &tmpString);
	bookShelf3Book = new ItemPickStoreRead("Book", "Learning to Play the Flute", "", "Hold the flute correctly and practice breath control. Start with simple scales and melodies to build your skills.");
	bookShelf3->setItemInside(bookShelf3Book, &tmpString);
	bookShelf3Book = new ItemPickStoreRead("Book", "Urban Gardening Tips", "", "Use vertical space and container gardening. Grow plants suitable for small spaces and urban environments.");
	bookShelf3->setItemInside(bookShelf3Book, &tmpString);
	bookShelf3Book = new ItemPickStoreRead("Book", "Crafting Short Stories", "", "Develop a compelling plot and well-rounded characters. Keep the narrative concise and engaging.");
	bookShelf3->setItemInside(bookShelf3Book, &tmpString);
	bookShelf3Book = new ItemPickStoreRead("Book", "Exploring Mixed Media Art", "", "Combine different materials like paint, paper, and found objects. Experiment with layering and textures for unique results.");
	bookShelf3->setItemInside(bookShelf3Book, &tmpString);
	bookShelf3Book = new ItemPickStoreRead("Book", "Introduction to Watercolor Painting", "", "Start with light washes of color on wet paper. Gradually add layers for depth, using a dry brush for fine details.");
	bookShelf3->setItemInside(bookShelf3Book, &tmpString);
	bookShelf3Book = new ItemPickStoreRead("Book", "Mastering Guitar Basics", "", "Learn basic chords: G, C, D, and E minor. Practice transitioning between chords smoothly.");
	bookShelf3->setItemInside(bookShelf3Book, &tmpString);
	bookShelf3Book = new ItemPickStoreRead("Book", "Gardening for Beginners", "", "Plant seeds in well-drained soil. Water regularly and ensure plants get at least 6 hours of sunlight per day.");
	bookShelf3->setItemInside(bookShelf3Book, &tmpString);
	bookShelf3Book = new ItemPickStoreRead("Book", "Haiku for the Heart", "", "Compose a haiku: three lines with a 5-7-5 syllable structure. Capture a moment in nature or an emotion.");
	bookShelf3->setItemInside(bookShelf3Book, &tmpString);
	bookShelf3Book = new ItemPickStoreRead("Book", "Sketching the Human Figure", "", "Start with basic shapes to outline the figure. Focus on proportions before adding details and shading.");
	bookShelf3->setItemInside(bookShelf3Book, &tmpString);
	bookShelf3Book = new ItemPickStoreRead("Book", "Basics of Piano Playing", "", "Familiarize yourself with the keys. Practice scales and simple melodies to improve finger coordination.");
	bookShelf3->setItemInside(bookShelf3Book, &tmpString);
	bookShelf3Book = new ItemPickStoreRead("Book", "Container Gardening", "", "Choose containers with good drainage. Fill with potting mix and plant herbs or flowers suitable for container growth.");
	bookShelf3->setItemInside(bookShelf3Book, &tmpString);
	bookShelf3Book = new ItemPickStoreRead("Book", "Sonnets of Love", "", "Write a sonnet: 14 lines in iambic pentameter with a specific rhyme scheme (ABABCDCDEFEFGG).");
	bookShelf3->setItemInside(bookShelf3Book, &tmpString);
	bookShelf3Book = new ItemPickStoreRead("Book", "Acrylic Painting Techniques", "", "Use a palette knife for texture. Experiment with layering colors and blending for dynamic effects.");
	bookShelf3->setItemInside(bookShelf3Book, &tmpString);
	bookShelf3Book = new ItemPickStoreRead("Book", "Learning to Play the Violin", "", "Hold the violin and bow correctly. Practice bowing open strings to get a clear sound before learning notes.");
	bookShelf3->setItemInside(bookShelf3Book, &tmpString);
	bookShelf3Book = new ItemPickStoreRead("Book", "Organic Vegetable Gardening", "", "Use compost and organic fertilizers. Rotate crops annually to maintain soil health and reduce pests.");
	bookShelf3->setItemInside(bookShelf3Book, &tmpString);
	bookShelf3Book = new ItemPickStoreRead("Book", "Crafting Limericks", "", "Write a limerick: five lines with an AABBA rhyme scheme. The first, second, and fifth lines are longer.");
	bookShelf3->setItemInside(bookShelf3Book, &tmpString);
	bookShelf3Book = new ItemPickStoreRead("Book", "Pastel Drawing for Beginners", "", "Blend pastels with your fingers or a blending stump. Use different pressures for varying intensity.");
	bookShelf3->setItemInside(bookShelf3Book, &tmpString);
	bookShelf3Book = new ItemPickStoreRead("Book", "Understanding Music Theory", "", "Learn the basics of scales, chords, and key signatures. Practice identifying notes and intervals by ear.");
	bookShelf3->setItemInside(bookShelf3Book, &tmpString);
	
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
