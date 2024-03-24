#include "MainObject.h"
using namespace std;

MainObject::MainObject(const string name, const string desc)
{
	_name = name;
	_desc = desc;
}

string MainObject::getName()
{
	return _name;
}
void MainObject::setName(string newName)
{
	if (newName.empty())
	{
		throw invalid_argument("Name must not be empty");
	}
	_name = newName;
}

string MainObject::getDesc()
{
	return _desc;
}
void MainObject::setDesc(string newDesc)
{
	if (newDesc.empty())
	{
		throw invalid_argument("Description must not be empty");
	}
	_desc = newDesc;
}