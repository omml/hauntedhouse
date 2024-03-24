#pragma once

#include <stdexcept>
#include <string>

using namespace std;


class MainObject
{
public:
    MainObject(const string name, const string desc);

    // getters
    string getName();
    string getDesc();

    // Setters, it is void bec it is merely setting the name/description
    void setName(string newName);
    void setDesc(string newDesc);

protected:
    string _name;
    string _desc;
};

