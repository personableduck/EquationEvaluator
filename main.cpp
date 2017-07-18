/*
 File Name: main.cpp
 Purpose: cpp file for main
 Author: DUCK HA HWANG; Date Created: 07/16/2017
 */

#pragma warning(disable:4996)
#include<iostream>
#include<string>
#include<fstream>
#include<map>
#include"MapInfo.h"
using namespace std;

bool CheckValueByMap(map<string, MapInfo> &myMap);
/*
 Returns true if all RHS are solved.
 */

bool Calculation(map<string, MapInfo> &myMap);
/*
 Returns true if Iterates over the map and solves equations.
 */

bool Int_validation(const std::string & s);
/*
 Returns true checks current string whther integer or not.
 */

int main(int dumm, char** EqEv)
{
    if (dumm != 2)
    {
        cout << "\n Put test input file";
        return 0;
    }
    
    map<string, MapInfo> Modify_map;
    
    string path_file = EqEv[1];
    ifstream textfile;
    textfile.open(path_file);
    if (!textfile.is_open())
    {
        cout << "\n Error: File cannot opened";
        return 0;
    }
    string t;
    string line;
    bool Key_value = true;
    while (getline(textfile, line))
    {
        MapInfo mapvalue;
        string key;
        bool nums = true;
        int numlist = 0;
        
        char * copied_str = new char[line.length() + 1];
        strncpy(copied_str, line.c_str(), line.length() + 1);
        char *pointer_ch = strtok(copied_str, " =+");
        
        while (pointer_ch != NULL)
        {
            if (Key_value == true) //First string is LHS  and is stored as key
            {
                key = pointer_ch;
                Key_value = false;
            }
            else
            {
                //Create List of strings.
                bool isNum = Int_validation(pointer_ch);
                mapvalue.VariableList.push_back(pointer_ch);
                if (!isNum)
                {
                    nums = false;
                }
                else
                {
                    numlist = numlist + stoi(pointer_ch);
                }
            }
            pointer_ch = strtok(NULL, " =+");
        }
        //allNum indicates all the variables are integers and RHS is solved
        mapvalue.setallValuesFound(nums);
        //valueoflist is current value of all integers in list.
        mapvalue.setValue(numlist);
        //Insert the value in sorted map for key
        Modify_map.insert({ key, mapvalue });
        
        Key_value = true;
        
    }
    textfile.close();
    
    bool result = Calculation(Modify_map);
    
    //Print all the key value pairs
    map<string, MapInfo>::iterator it;
    for (it = Modify_map.begin(); it != Modify_map.end(); it++)
    {
        cout << it->first << " = " << it->second.getValue() << "\n";
    }
    
    return 0;
}


bool CheckValueByMap(map<string, MapInfo> &myMap)
{
    map<string, MapInfo>::iterator it;
    for (it = myMap.begin(); it != myMap.end(); it++)
    {
        if (it->second.getallValuesFound() == false)
            return false;
    }
    return true;
}


bool Calculation(map<string, MapInfo> &myMap)
{
    map<string, MapInfo>::iterator it;
    while (!CheckValueByMap(myMap))
    {
        for (it = myMap.begin(); it != myMap.end(); it++)
        {
            if (it->second.getallValuesFound() == false)
            {
                list<string>::iterator strit;
                bool listover = true;
                for (strit = it->second.VariableList.begin(); strit != it->second.VariableList.end(); strit++)
                {
                    bool isCurrInt = Int_validation(*strit);
                    if (!isCurrInt)
                    {
                        map<string, MapInfo>::iterator pos = myMap.find(*strit);
                        if (pos != myMap.end())
                        {
                            if (pos->second.getallValuesFound())
                            {
                                *strit = to_string(pos->second.getValue());
                            }
                            else
                            {
                                listover = false;
                                break;
                            }
                        }
                    }
                }
                if (listover)
                {
                    list<string>::iterator finalListIt;
                    unsigned int finalVal = 0;
                    for (finalListIt = it->second.VariableList.begin(); finalListIt != it->second.VariableList.end(); finalListIt++)
                    {
                        finalVal += stoi(*finalListIt);
                    }
                    it->second.setValue(finalVal);
                    it->second.setallValuesFound(true);
                }
            }
        }
    }
    return true;
}

bool Int_validation(const std::string & s)
{
    if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) {
        return false;
    }
    
    char * p;
    strtol(s.c_str(), &p, 10);
    return (*p == 0);
}
