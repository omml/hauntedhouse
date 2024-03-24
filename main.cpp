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


int main2()
{
    return 0;
    Character c = Character("hola", "hola2");

    cout << c.getName() << endl;
    cout << c.getDesc() << endl;

}

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

    if (ActionPick* aPick = dynamic_cast<ActionPick*>(a))
    {
        if (item->getNumHoldingItems() == 0)
        {
            if (hand->addItem(item, m))
            {
                item->picked();
                r->removeItem(item);
                bag->removeItem(item);
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
    }
    else if (ActionStore* aStore = dynamic_cast<ActionStore*>(a))
    {
        if (bag->addItem(item, m))
        {
            if (item->isPickStoreLight())
            {
                if (item->getState() == Lighted)
                {
                    r->setIsLighted(false, false);
                }
            }
            item->stored();
            r->removeItem(item);
            hand->removeItem(item);
            body->removeItem(item);
            *m = "The " + item->getName() + " was stored in your bag";
            retVal = true;
        }
        else
        {
            retVal = false;
        }
    }
    else if (ActionDrop* aDrop = dynamic_cast<ActionDrop*>(a))
    {
        item->dropped();
        r->setItem(item);
        r->hasDroppedCandle(item);
        item->setPosDesc("Laying on the floor");
        
        hand->removeItem(item);
        bag->removeItem(item);
        body->removeItem(item);
        *m = "The " + item->getName() + " has been dropped to the floor";
        retVal = true;
    }
    else if (ActionWear* aWear = dynamic_cast<ActionWear*>(a))
    {
        if (body->addItem(item, m))
        {
            item->wore();
            r->removeItem(item);
            hand->removeItem(item);
            bag->removeItem(item);
            *m = "You are wearing the " + item->getName();
            
            retVal = true;
        }
        else
        {
            retVal = false;
        }
    }
    else if (ActionMove* aMove = dynamic_cast<ActionMove*>(a))
    {
        item->moved(moveIdx);

        *m = "The " + item->getName() + " has been moved";
        retVal = true;
    }
    else if (ActionLight* aLight = dynamic_cast<ActionLight*>(a))
    {
        //Check if we are holding matches
        if (hand->areThereMatches() == true)
        {
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
    }
    else if (ActionRead* aRead = dynamic_cast<ActionRead*>(a))
    {
        *m = item->read();
        retVal = true;
    }
    else if (ActionClimb* aClimb = dynamic_cast<ActionClimb*>(a))
    {
        GameState::getInstance().setClimbedItem(item);

        *m = "You climbed the " + item->getName();

        retVal = true;
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

    do
    {
        system("cls");

        currentRoom = GameState::getInstance().getCurrentRoom();

        cout << "Looking around "
            + currentRoom->getName()
            + " you see "
            + currentRoom->getDesc()
            + "\n\n";
        cout << currentRoom->getIsDarkDescription() << endl << endl;
        

        switch (guiState)
        {
        case MainGUI:
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
                cout << "You are on top of the " << GameState::getInstance().getClimbedItem()->getName() << endl << endl;

                cout << "Main Options:\n";
                cout << "[0] Exit Game\n";
                cout << "[1] Explore Room\n";
                cout << "[2] Climb Down\n";

                cout << "\nSelect an option > ";
                cin >> mainOption;

                message = "";

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
            cout << "Move Options:\n";
            cout << "[0] Go Back\n";

            currentRoom->displayRooms();
            
            cout << "\nSelect an option > ";
            cin >> moveOption;

            if (moveOption == 0)
            {
                guiState = MainGUI;
            }
            else if (moveOption > 0 && moveOption < 5)
            {
                message = "";

                next = currentRoom->getLinkedRoom(moveOption - 1);
                if (next != nullptr)
                {
                    GameState::getInstance().setCurrentRoom(next, &hands);
                    guiState = MainGUI;
                }
            }
            break;
        case ExploreGUI:
            if (GameState::getInstance().getCurrentRoomLevel() == 0)
            {
                cout << message << endl << endl;

                cout << "Explore Options:\n";
                cout << "[0] Go Back\n";

                currentRoom->displayItems();

                cout << "\nSelect an option > ";
                cin >> exploreOption;

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

                if (exploreOption == 0)
                {
                    guiState = MainGUI;
                }
                else if(climbedItem != nullptr)
                {
                    if (exploreOption > 0 && exploreOption <= climbedItem->getCurrentDestination()->getNumViewableItems())
                    {
                        message = "";

                        guiState = ItemGUI;
                    }
                }
            }

            break;
        case ItemGUI:
            if (GameState::getInstance().getCurrentRoomLevel() == 0)
            {
                currentItem = currentRoom->getItem(exploreOption - 1);
            }
            else
            {
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

            if (itemOption == 0)
            {
                guiState = ExploreGUI;
            }
            else if (itemOption > 0 && itemOption <= currentItem->getNumActions())
            {
                message = "";

                Action* a = currentItem->getAction(itemOption - 1);

                if (IsMovingAction(a))
                {
                    guiState = MovingGUI;
                }
                else if (HandleAction(currentRoom, a, currentItem, &hands, &bag, &body, &message, -1))
                {
                    climbedItem = currentItem;
                    guiState = MainGUI;
                }
            }
            break;
        case MovingGUI:
            currentItem = currentRoom->getItem(exploreOption - 1);

            cout << currentItem->getDisplayString() << endl << endl;

            cout << "Move Options:\n";
            cout << "[0] Go Back\n";

            currentItem->displayDestinations();

            cout << "\nSelect an option > ";
            cin >> moveOption;

            if (moveOption == 0)
            {
                guiState = ExploreGUI;
            }
            else if (moveOption > 0 && moveOption <= currentItem->getNumActions())
            {
                message = "";

                Action* a = currentItem->getAction(itemOption - 1);

                if (HandleAction(currentRoom, a, currentItem, &hands, &bag, &body, &message, moveOption - 1 ))
                {
                    guiState = ItemGUI;
                }
            }

            break;
        case SelectInventoryGUI:

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

                if (HandleAction(currentRoom, a, currentItem, &hands, &bag, &body, &message, -1))
                {
                    guiState = InventoryGUI;
                }

            }

            break;
        }
        

    } while (mainOption != 0);
}
