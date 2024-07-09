//
//  main.cpp
//  Borley Rectory Haunted Mansion Text-Based Console Game
//
//  Created by Oscar Martinez on 21/03/2024.
//

#include "GameState.h"
#include "GUIHandler.h"
#include "Inventory.h"
#include "Layout.h"

using namespace std;

string intro = "Borley Rectory, located in Borley, Essex, was famously known as 'The most haunted house in England'.\nBuilt in 1862 and demolished in 1944, it gained notoriety for alleged paranormal activity.\n\nYour playful little bro 'Milo' has gone into the haunted house and he is trapped in it by the 'Ghost of the Headless Man'. Enter the house and rescue him!";
ActionHandler actionHandler;
GUIHandler guiHandler;

int main()
{
    Inventory bag = Inventory("Bag", 6, false);
    Inventory hands = Inventory("Hands", 2, true);
    Inventory body = Inventory("Wear", 2, true);

	Layout house = Layout();
    GameState::getInstance() = GameState();
    GameState::getInstance().setCurrentRoom(house.getFirstRoom(), &hands);

    int mainOption = -1;
    
    Room* currentRoom;
    Room* nextRoom = nullptr;
    Item* currentItem = nullptr;
    Item* climbedItem = nullptr;

    cout << intro << endl << endl;

    cout << "Press enter to continue> " << endl;

    getchar();

    do
    {
        system("cls");

        currentRoom = GameState::getInstance().getCurrentRoom();

        // Display game state
        cout << "Standing in the "
            + currentRoom->getName()
            + ": \n\n"
            + currentRoom->getDesc()
            + "\n\n";
        cout << currentRoom->getIsDarkDescription() << endl << endl;
        

        mainOption = guiHandler.DisplayGUI(&actionHandler, currentRoom, nextRoom, &hands, &bag, &body, currentItem, climbedItem);
        

    } while (mainOption != 0);
}

