/*
 File Name: Map.cpp
 Purpose: cpp file for class MapValue
 Author: DUCK HA HWANG
 */

#include"MapInfo.h"
#include<map>
#include<string>

using namespace std;
MapInfo::MapInfo()
{
    value = -1;
    allValuesFound = false;
}

MapInfo::~MapInfo()
{
}

bool MapInfo::getallValuesFound()
{
    return allValuesFound;
    ;
}
void MapInfo::setallValuesFound(bool valuesFound)
{
    allValuesFound = valuesFound;
}

int MapInfo::getValue()
{
    return value;
}
void MapInfo::setValue(int writeValue)
{
    value = writeValue;
}
