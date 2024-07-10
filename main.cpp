//
//  main.cpp
//  Borley Rectory Haunted Mansion Text-Based Console Game
//
//  Created by Oscar Martinez on 21/03/2024.
//

#include <iostream>
#include <string>
#include <vector>

#include "GameState.h"
#include "GUIHandler.h"
#include "Inventory.h"
#include "Layout.h"

using namespace std;

// Set a fixed width for main displaying rectangle
const int RECTANGLE_WIDTH = 50;  

string intro = "Borley Rectory, located in Borley, Essex, was famously known as 'The most haunted house in England'. Built in 1862 and demolished in 1944, it gained notoriety for alleged paranormal activity. Your playful little bro 'Milo' has gone into the haunted house and he is trapped in it by the 'Ghost of the Headless Man'. Enter the house and rescue him!";
ActionHandler actionHandler;
GUIHandler guiHandler;

// Function to wrap text to fit within the rectangle width
vector<string> WrapText(const string& text, int width) {
    vector<string> wrappedText;
    int start = 0;
    int end = width;

    while (start < text.length()) {
        if (end >= text.length()) {
            wrappedText.push_back(text.substr(start));
            break;
        }
        else {
            int spacePos = (int)text.rfind(' ', end);
            if (spacePos != string::npos && spacePos > start) {
                wrappedText.push_back(text.substr(start, spacePos - start));
                start = spacePos + 1;
                end = start + width;
            }
            else {
                wrappedText.push_back(text.substr(start, width));
                start += width;
                end += width;
            }
        }
    }

    return wrappedText;
}

void DisplayTextInRectangle(const string& title, const string& text1, const string& text2) {
    string border(RECTANGLE_WIDTH, '*');
    string emptyLine = "*" + string(RECTANGLE_WIDTH - 2, ' ') + "*";

    cout << border << endl;
    cout << emptyLine << endl;

    // Display the room name centered
    string titleLine = title;
    int padding = (int)(RECTANGLE_WIDTH - titleLine.size() - 4) / 2; // 4 accounts for border and extra whitespace
    cout << "*" << ' ' << string(padding, ' ') << titleLine << string(RECTANGLE_WIDTH - titleLine.size() - padding - 4, ' ') << ' ' << "*" << endl;

    cout << emptyLine << endl;

    // Display the room description, word-wrapped if necessary
    vector<string> wrappedText1 = WrapText(text1, RECTANGLE_WIDTH - 4); // 4 accounts for border and extra whitespace
    for (const string& line : wrappedText1) {
        cout << "*" << ' ' << line << string(RECTANGLE_WIDTH - line.size() - 4, ' ') << ' ' << "*" << endl;
    }

    cout << emptyLine << endl;

    // Display the darkness description
    vector<string> wrappedText2 = WrapText(text2, RECTANGLE_WIDTH - 4); // 4 accounts for border and extra whitespace
    for (const string& line : wrappedText2) {
        cout << "*" << ' ' << line << string(RECTANGLE_WIDTH - line.size() - 4, ' ') << ' ' << "*" << endl;
    }

    cout << emptyLine << endl;
    cout << border << endl;
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
    
    Room* currentRoom;
    Room* nextRoom = nullptr;
    Item* currentItem = nullptr;
    Item* climbedItem = nullptr;

    DisplayTextInRectangle("Haunted House", intro, "Press enter to continue");

    getchar();

    do
    {
        system("cls");

        currentRoom = GameState::getInstance().getCurrentRoom();

        // Display game state
        DisplayTextInRectangle("Standing in the " + currentRoom->getName() + ":", currentRoom->getDesc(), currentRoom->getIsDarkDescription());

        mainOption = guiHandler.DisplayGUI(&actionHandler, currentRoom, nextRoom, &hands, &bag, &body, currentItem, climbedItem);

    } while (mainOption != 0);
}

