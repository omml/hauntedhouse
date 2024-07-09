//
//  main.cpp
//  Borley Rectory Haunted Mansion Text-Based Console Game
//
//  Created by Oscar Martinez on 21/03/2024.
//
#include <iostream>
#include <string>
#include <map>

#include "ActionClimb.h"
#include "ActionDrop.h"
#include "ActionHandler.h"
#include "ActionLight.h"
#include "ActionMove.h"
#include "ActionPick.h"
#include "ActionRead.h"
#include "ActionStore.h"
#include "ActionWear.h"
#include "Character.h"
#include "CommonDefinitions.h"
#include "GameState.h"
#include "Inventory.h"
#include "ItemPickWear.h"
#include "Layout.h"

using namespace std;

GUIState guiState;
string guiStrings[] = { "Main", "Move", "Explore", "Inventory"};

string intro = "Borley Rectory, located in Borley, Essex, was famously known as 'The most haunted house in England'.\nBuilt in 1862 and demolished in 1944, it gained notoriety for alleged paranormal activity.\n\nYour playful little bro 'Milo' has gone into the haunted house and he is trapped in it by the 'Ghost of the Headless Man'. Enter the house and rescue him!";
ActionHandler actionHandler;

int main()
{
    Inventory bag = Inventory("Bag", 6, false);
    Inventory hands = Inventory("Hands", 2, true);
    Inventory body = Inventory("Wear", 2, true);

	Layout house = Layout();
    GameState::getInstance() = GameState();
    GameState::getInstance().setCurrentRoom(house.getFirstRoom(), &hands);

    int mainOption = -1;
    int moveOption = -1;
    int exploreOption = -1;
    int itemOption = -1;
    int selectInventoryOption = -1;
    int inventoryOption = -1;
    int numItems = 0;
    string message = "";

    Room* currentRoom;
    Room* next;
    Item* currentItem;
    Item* climbedItem = nullptr;

    guiState = MainGUI;

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
        

        switch (guiState)
        {
        case MainGUI:
            // Main GUI

            // Check if is climbing, if it is not
            if (GameState::getInstance().getCurrentRoomLevel() == 0)
            {
                cout << "Main Options:\n";
                cout << "[0] Exit Game\n";
                cout << "[1] Move to another Room\n";
                cout << "[2] Explore Room\n";
                cout << "[3] Inventory\n";

                cout << "\nSelect an option > ";
                cin >> mainOption;

                message = "";

                // Check selected option
                switch (mainOption)
                {
                case 1:
                    guiState = MoveGUI;
                    break;
                case 2:
                    guiState = ExploreGUI;
                    break;
                case 3:
                    guiState = SelectInventoryGUI;
                    break;
                }
            }
            else
            {
                // If it is climbing
                cout << "You are on top of the " << GameState::getInstance().getClimbedItem()->getName() << endl << endl;

                cout << "Main Options:\n";
                cout << "[0] Exit Game\n";
                cout << "[1] Explore Room\n";
                cout << "[2] Climb Down\n";

                cout << "\nSelect an option > ";
                cin >> mainOption;

                message = "";

                // Check selected option
                switch (mainOption)
                {
                case 1:
                    guiState = ExploreGUI;
                    break;
                case 2:
                    GameState::getInstance().setCurrentRoomLevel(0);
                    break;
                }
            }
            break;
        case MoveGUI:
            // Move items GUI

            cout << "Move Options:\n";
            cout << "[0] Go Back\n";

            // Display connected rooms
            currentRoom->displayRooms();
            
            cout << "\nSelect an option > ";
            cin >> moveOption;

            // Check selected option
            if (moveOption == 0)
            {
                guiState = MainGUI;
            }
            else if (moveOption > 0 && moveOption < 5)
            {
                message = "";

                // Change current room
                next = currentRoom->getLinkedRoom(moveOption - 1);
                if (next != nullptr)
                {
                    GameState::getInstance().setCurrentRoom(next, &hands);
                    guiState = MainGUI;
                }
            }
            break;
        case ExploreGUI:
            // Explore room GUI

            // Check if it is climbing, if it is not
            if (GameState::getInstance().getCurrentRoomLevel() == 0)
            {
                cout << message << endl << endl;

                cout << "Explore Options:\n";
                cout << "[0] Go Back\n";

                // Display items in room
                currentRoom->displayItems();

                cout << "\nSelect an option > ";
                cin >> exploreOption;

                // Check selected option
                if (exploreOption == 0)
                {
                    guiState = MainGUI;
                }
                else if (exploreOption > 0 && exploreOption <= currentRoom->getNumItems())
                {
                    message = "";

                    guiState = ItemGUI;
                }
            }
            else
            {
                // If it is climbing

                cout << message << endl << endl;

                cout << "Explore Options:\n";
                cout << "[0] Go Back\n";

                if (climbedItem != nullptr)
                {
                    Item* tmp = climbedItem->getCurrentDestination();
                    if (tmp != nullptr)
                    {
                        tmp->displayViewableItems();
                    }
                }

                cout << "\nSelect an option > ";
                cin >> exploreOption;

                // Check selected option
                if (exploreOption == 0)
                {
                    guiState = MainGUI;
                }
                else if(climbedItem != nullptr)
                {
                    // Check if there viewable items from climbed position
                    if (exploreOption > 0 && exploreOption <= climbedItem->getCurrentDestination()->getNumViewableItems())
                    {
                        message = "";

                        guiState = ItemGUI;
                    }
                }
            }

            break;
        case ItemGUI:
            // Available items GUI

            // Check if it is climbing
            if (GameState::getInstance().getCurrentRoomLevel() == 0)
            {
                // Display room items
                currentItem = currentRoom->getItem(exploreOption - 1);
            }
            else
            {
                // Display items viewable from climbed position
                currentItem = climbedItem->getCurrentDestination()->getViewableItem();
            }

            cout << message << endl << endl;

            cout << currentItem->getDisplayString() << endl << endl;
            currentItem->displayHoldingItems();

            cout << "Item Options:\n";
            cout << "[0] Go Back\n";
            
            currentItem->displayActions();

            cout << "\nSelect an option > ";
            cin >> itemOption;

            // Check selected option
            if (itemOption == 0)
            {
                guiState = ExploreGUI;
            }
            else if (itemOption > 0 && itemOption <= currentItem->getNumActions())
            {
                message = "";

                Action* a = currentItem->getAction(itemOption - 1);

                // Check if item can be moved
                if (actionHandler.IsMovingAction(a))
                {
                    guiState = MovingGUI;
                }
                // Handle action
                else if (actionHandler.HandleAction(currentRoom, a, currentItem, &hands, &bag, &body, &message, -1))
                {
                    climbedItem = currentItem;
                    guiState = MainGUI;
                }
            }
            break;
        case MovingGUI:
            // Move GUI

            currentItem = currentRoom->getItem(exploreOption - 1);

            cout << currentItem->getDisplayString() << endl << endl;

            cout << "Move Options:\n";
            cout << "[0] Go Back\n";

            // Display moving options
            currentItem->displayDestinations();

            cout << "\nSelect an option > ";
            cin >> moveOption;

            // Check selected option
            if (moveOption == 0)
            {
                guiState = ExploreGUI;
            }
            else if (moveOption > 0 && moveOption <= currentItem->getNumActions())
            {
                message = "";

                Action* a = currentItem->getAction(itemOption - 1);

                // Handle moving action
                if (actionHandler.HandleAction(currentRoom, a, currentItem, &hands, &bag, &body, &message, moveOption - 1 ))
                {
                    guiState = ItemGUI;
                }
            }

            break;
        case SelectInventoryGUI:
            // Inventory GUI

            message = "";

            cout << "Inventory Options:\n";
            cout << "[0] Go Back\n";
            cout << "[1] Carrying on Hands\n";
            cout << "[2] Carrying in Bag\n";
            cout << "[3] Wearing\n";

            cout << "\nSelect an option > ";
            cin >> selectInventoryOption;

            if (selectInventoryOption == 0)
            {
                guiState = MainGUI;
            }
            else if (selectInventoryOption > 0 && selectInventoryOption < 4)
            {
                message = "";

                guiState = InventoryGUI;
            }
            break;
        case InventoryGUI:

            cout << message << endl << endl;

            // Display items in inventory
            if (selectInventoryOption == 1)
            {
                cout << "Carrying in hands, options:\n";
                cout << "[0] Go Back\n";
                hands.displayInventory();
                numItems = hands.getNumItems();
            }
            else if (selectInventoryOption == 2)
            {
                cout << "Carrying in bag, options:\n";
                cout << "[0] Go Back\n";
                bag.displayInventory();
                numItems = bag.getNumItems();
            }
            else
            {
                cout << "Wearing, options:\n";
                cout << "[0] Go Back\n";
                body.displayInventory();
                numItems = body.getNumItems();
            }
            
            cout << "\nSelect an option > ";
            cin >> inventoryOption;

            if (inventoryOption == 0)
            {
                guiState = SelectInventoryGUI;
            }
            else if (inventoryOption > 0 && inventoryOption <= numItems)
            {
                message = "";

                guiState = InventoryItemGUI;
            }
            break;
        case InventoryItemGUI:
            // GUI for items in inventories

            string description = "";

            cout << message << endl << endl;

            if (selectInventoryOption == 1)
            {
                description = " in one hand";
                currentItem = hands.getItem(inventoryOption - 1);
            }
            else if (selectInventoryOption == 2)
            {
                description = " in the bag";
                currentItem = bag.getItem(inventoryOption - 1);
            }
            else
            {
                description = " wearing it";
                currentItem = body.getItem(inventoryOption - 1);
            }

            cout << currentItem->getDisplayString() << description << endl << endl;
            currentItem->displayHoldingItems();

            cout << "Item Options:\n";
            cout << "[0] Go Back\n";

            currentItem->displayActions();

            cout << "\nSelect an option > ";
            cin >> itemOption;

            if (itemOption == 0)
            {
                guiState = ExploreGUI;
            }
            else if (itemOption > 0 && itemOption <= currentItem->getNumActions())
            {
                message = "";

                Action* a = currentItem->getAction(itemOption - 1);

                // Handle item action
                if (actionHandler.HandleAction(currentRoom, a, currentItem, &hands, &bag, &body, &message, -1))
                {
                    guiState = InventoryGUI;
                }

            }

            break;
        }
        

    } while (mainOption != 0);
}

