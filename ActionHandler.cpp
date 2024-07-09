//
//  ActionHandler.cpp
//  Borley Rectory Haunted Mansion Text-Based Console Game
//
//  Created by Oscar Martinez on 09/07/2024.
//
#include "GameState.h"
#include "Action.h"
#include "ActionHandler.h"
#include "ActionMove.h"

ActionHandler::ActionHandler()
{}

bool ActionHandler::IsMovingAction(Action* a)
{
    bool retVal = false;

    if (ActionMove* aMove = dynamic_cast<ActionMove*>(a))
    {
        retVal = true;
    }

    return retVal;
}

bool ActionHandler::HandlePickAction(Room* r, Action* a, Item* item, Inventory* hand, Inventory* bag, Inventory* body, string* m, int moveIdx)
{
    bool retVal = false;

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

    return retVal;
}

bool ActionHandler::HandleStoreAction(Room* r, Action* a, Item* item, Inventory* hand, Inventory* bag, Inventory* body, string* m, int moveIdx)
{
    bool retVal = false;

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

    return retVal;
}

bool ActionHandler::HandleDropAction(Room* r, Action* a, Item* item, Inventory* hand, Inventory* bag, Inventory* body, string* m, int moveIdx)
{
    bool retVal = false;

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

    return retVal;
}

bool ActionHandler::HandleWearAction(Room* r, Action* a, Item* item, Inventory* hand, Inventory* bag, Inventory* body, string* m, int moveIdx)
{
    bool retVal = false;

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
    return retVal;
}

bool ActionHandler::HandleMoveAction(Room* r, Action* a, Item* item, Inventory* hand, Inventory* bag, Inventory* body, string* m, int moveIdx)
{
    bool retVal = false;

    // Move to a location in index moveIdx
    item->moved(moveIdx);

    *m = "The " + item->getName() + " has been moved";
    retVal = true;

    return retVal;
}

bool ActionHandler::HandleLightAction(Room* r, Action* a, Item* item, Inventory* hand, Inventory* bag, Inventory* body, string* m, int moveIdx)
{
    bool retVal = false;

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

    return retVal;
}

bool ActionHandler::HandleReadAction(Room* r, Action* a, Item* item, Inventory* hand, Inventory* bag, Inventory* body, string* m, int moveIdx)
{
    bool retVal = false;

    // Read item
    *m = item->read();
    retVal = true;

    return retVal;
}

bool ActionHandler::HandleClimbAction(Room* r, Action* a, Item* item, Inventory* hand, Inventory* bag, Inventory* body, string* m, int moveIdx)
{
    bool retVal = false;

    // Climb item
    GameState::getInstance().setClimbedItem(item);

    *m = "You climbed the " + item->getName();

    retVal = true;

    return retVal;
}

bool ActionHandler::HandleAction(Room* r, Action* a, Item* item, Inventory* hand, Inventory* bag, Inventory* body, string* m, int moveIdx)
{
    bool retVal = false;

    switch (a->GetActionID())
    {
    case AIDPick:
        retVal = HandlePickAction(r, a, item, hand, bag, body, m, moveIdx);
        break;

    case AIDStore:
        retVal = HandleStoreAction(r, a, item, hand, bag, body, m, moveIdx);
        break;

    case AIDDrop:
        retVal = HandleDropAction(r, a, item, hand, bag, body, m, moveIdx);
        break;

    case AIDWear:
        retVal = HandleWearAction(r, a, item, hand, bag, body, m, moveIdx);
        break;

    case AIDMove:
        retVal = HandleMoveAction(r, a, item, hand, bag, body, m, moveIdx);
        break;

    case AIDLight:
        retVal = HandleLightAction(r, a, item, hand, bag, body, m, moveIdx);
        break;

    case  AIDRead:
        retVal = HandleReadAction(r, a, item, hand, bag, body, m, moveIdx);
        break;

    case AIDClimb:
        retVal = HandleClimbAction(r, a, item, hand, bag, body, m, moveIdx);

        break;
    default:
        break;
    }

    return retVal;
}
