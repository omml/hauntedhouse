//
//  MainObject.h
//  Borley Rectory Haunted Mansion Text-Based Console Game
//
//  Created by Oscar Martinez on 21/03/2024.
//
#pragma once

#include <stdexcept>
#include <string>

using namespace std;

// Main base class that holds basic data and functionality 
class MainObject
{
public:
    MainObject(const string name, const string desc);

    // Returns the name of the object
    string getName();
    // Returns the description of the object
    string getDesc();

    // Sets the name of the object
    void setName(string newName);
    // Sets the description of the object
    void setDesc(string newDesc);

protected:
    // Name of the object
    string _name;
    // Description of the object
    string _desc;
};

