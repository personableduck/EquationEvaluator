/*
 File Name: MapInfo.h
 Purpose: Header file for class MapValue.h
 Author: DUCK HA HWANG
 */

#pragma once
#include<string>
#include<list>

using namespace std;
class MapInfo
{
public:
    //Constructor/Destructor
    MapInfo();
    ~MapInfo();
    
    //Getter/Setter
    bool getallValuesFound();
    void setallValuesFound(bool valuesFound);
    int getValue();
    void setValue(int writeValue);
    
    //List to store RHS variables
    list<string> VariableList;
    
private:
    int value; // Value of RHS
    bool allValuesFound; // bool if all variables are found
};
