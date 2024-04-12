//
//  CommonDefinitions.h
//  Borley Rectory Haunted Mansion Text-Based Console Game
//
//  Created by Oscar Martinez on 21/03/2024.
//
//#pragma once
#ifndef COMMONDEFS
#define COMMONDEFS
enum GUIState { IntroGUI, MainGUI, MoveGUI, ExploreGUI, ItemGUI, SelectInventoryGUI, InventoryGUI, InventoryItemGUI, MovingGUI};
enum Directions { North = 0, East, South, West };
enum ItemState { Picked, Stored, Lighted, Dropped, Wore, Hanged};
enum ObjectType { OTPickedWore, OTPickedStored, 
};
#endif