//
//  main.cpp
//  Borley Rectory Haunted Mansion Text-Based Console Game
//
//  Created by Oscar Martinez on 21/03/2024.
//
#include <iostream>
#include <string>
#include <map>
#include "Layout.h"
#include "GameState.h"
#include "CommonDefinitions.h"
#include "Character.h"
#include "Inventory.h"
#include "ActionPick.h"
#include "ActionStore.h"
#include "ActionDrop.h"
#include "ActionWear.h"
#include "ActionMove.h"
#include "ActionLight.h"
#include "ActionRead.h"
#include "ActionClimb.h"
#include "ItemPickWear.h"

using namespace std;

GUIState guiState;
string guiStrings[] = { "Main", "Move", "Explore", "Inventory"};

string intro = "Borley Rectory, located in Borley, Essex, was famously known as 'The most haunted house in England'.\nBuilt in 1862 and demolished in 1944, it gained notoriety for alleged paranormal activity.\n\nYour playful little bro 'Milo' has gone into the haunted house and he is trapped in it by the 'Ghost of the Headless Man'. Enter the house and rescue him!";


bool IsMovingAction(Action* a)
{
    bool retVal = false;
    
    if (ActionMove* aMove = dynamic_cast<ActionMove*>(a))
    {
        retVal = true;
    }

    return retVal;
}

bool HandleAction(Room* r, Action* a, Item* item, Inventory* hand, Inventory* bag, Inventory* body, string* m, int moveIdx)
{
    bool retVal = false;

    switch(a->GetActionID())
    {
    case AIDPick:
        // Check if we are holding an item
        if (item->getNumHoldingItems() == 0)
        {
            // Add the item to hand inventory
            if (hand->addItem(item, m))
            {
                // Set time as picked
                item->picked();
                // Remove item from room if in room
                r->removeItem(item);
                // Remove item from bag if in bag
                bag->removeItem(item);
                // Remove item from wearing if wearing
                body->removeItem(item);
                *m = "The " + item->getName() + " was picked and now you are holding it";
                retVal = true;
            }
            else
            {
                retVal = false;
            }
        }
        else
        {
            *m = "The " + item->getName() + " can not be picked while it is hokding items";
            retVal = false;
        }
        break;

    case AIDStore:
        // Add item to bag inventory
        if (bag->addItem(item, m))
        {
            // Check if is an item that can be lighted
            if (item->isPickStoreLight())
            {
                // Check if it is lighted
                if (item->getState() == Lighted)
                {
                    // Unlight it
                    r->setIsLighted(false, false);
                }
            }
            // Set item as stored
            item->stored();
            // Remove it from room 
            r->removeItem(item);
            // Remove it from hand if in hand
            hand->removeItem(item);
            // Remove it from body if in body
            body->removeItem(item);
            *m = "The " + item->getName() + " was stored in your bag";
            retVal = true;
        }
        else
        {
            retVal = false;
        }
        break;

    case AIDDrop:
        // Set item as dropped
        item->dropped();
        // Add it to the room
        r->setItem(item);
        // Set if room has a candle
        r->hasDroppedCandle(item);
        item->setPosDesc("Laying on the floor");
        
        // Remove it from hand if in hand
        hand->removeItem(item);
        // Remove it from bag if in bag
        bag->removeItem(item);
        // Remove from body if in body
        body->removeItem(item);
        *m = "The " + item->getName() + " has been dropped to the floor";
        retVal = true;
        break;

    case AIDWear:
        // Add item to body inventory
        if (body->addItem(item, m))
        {
            // Set item as wore
            item->wore();
            // Remove from roon
            r->removeItem(item);
            // Remove from hand if in hand
            hand->removeItem(item);
            // Remove from bag if in bag
            bag->removeItem(item);
            *m = "You are wearing the " + item->getName();
            
            retVal = true;
        }
        else
        {
            retVal = false;
        }
        break;

    case AIDMove:
        // Move to a location in index moveIdx
        item->moved(moveIdx);

        *m = "The " + item->getName() + " has been moved";
        retVal = true;
        break;

    case AIDLight:
        // Check if we are holding matches
        if (hand->areThereMatches() == true)
        {
            // Check if we have a free hand to light the item
            if (hand->getNumItems() == 1)
            {
                retVal = true;
                *m = "You have lighted the " + item->getName();
                item->lighted();
                r->setIsLighted(true, false);
            }
            else
            {
                retVal = false;
                *m = "You need the matches in one hand and the other hand free to light the " + item->getName();
            }
        }
        else
        {
            // Matches are need to light
            if (bag->areThereMatches() == true)
            {
                retVal = false;
                *m = "You need to hold the matches";
            }
            else
            {
                retVal = false;
                *m = "You need matches";
            }
        }
        break;

    case  AIDRead:
        // Read item
        *m = item->read();
        retVal = true;
        break;

    case AIDClimb:

        // Climb item
        GameState::getInstance().setClimbedItem(item);

        *m = "You climbed the " + item->getName();

        retVal = true;
        break;
    default:
        break;
    }

    return retVal;
}

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
                if (IsMovingAction(a))
                {
                    guiState = MovingGUI;
                }
                // Handle action
                else if (HandleAction(currentRoom, a, currentItem, &hands, &bag, &body, &message, -1))
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
                if (HandleAction(currentRoom, a, currentItem, &hands, &bag, &body, &message, moveOption - 1 ))
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
                if (HandleAction(currentRoom, a, currentItem, &hands, &bag, &body, &message, -1))
                {
                    guiState = InventoryGUI;
                }

            }

            break;
        }
        

    } while (mainOption != 0);
}
