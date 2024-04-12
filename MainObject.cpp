//
//  MainObject.cpp
//  Borley Rectory Haunted Mansion Text-Based Console Game
//
//  Created by Oscar Martinez on 21/03/2024.
//
#include "MainObject.h"
using namespace std;

MainObject::MainObject(const string name, const string desc)
{
	_name = name;
	_desc = desc;
}

// Returns the name of the object
string MainObject::getName()
{
	return _name;
}

// Sets the name of the object
void MainObject::setName(string newName)
{
	if (newName.empty())
	{
		throw invalid_argument("Name must not be empty");
	}
	_name = newName;
}

// Returns the description of the object
string MainObject::getDesc()
{
	return _desc;
}

// Sets the description of the object
void MainObject::setDesc(string newDesc)
{
	if (newDesc.empty())
	{
		throw invalid_argument("Description must not be empty");
	}
	_desc = newDesc;
}