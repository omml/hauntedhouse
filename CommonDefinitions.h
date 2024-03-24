//#pragma once
#ifndef COMMONDEFS
#define COMMONDEFS
enum GUIState { MainGUI, MoveGUI, ExploreGUI, ItemGUI, SelectInventoryGUI, InventoryGUI, InventoryItemGUI, MovingGUI};
enum Directions { North = 0, East, South, West };
enum ItemState { Picked, Stored, Lighted, Dropped, Wore, Hanged};
enum ObjectType { OTPickedWore, OTPickedStored, 
};
#endif