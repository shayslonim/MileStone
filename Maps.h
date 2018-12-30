//
// Created by shira on 12/19/18.
//

#ifndef PROJECT_VARBINDMAP_H
#define PROJECT_VARBINDMAP_H
#include <string>
#include <map>
#include "Command/Command.h"
using namespace std;

class Maps
{
    // path: "/controls/flight/speedbrake", variable: breaks, value: 5
    map<string, string> bindMap; // path to variable
    map<string, string> reversedBindMap; // variable to path
    map<string, double> varToValMap; // variable to value: breaks = 5
    map<string, double> pathToValMap; // path to value: "/controls/flight/speedbrake" = 5
public:
    Maps();
    // Double-binding
    void insertBind(string key, string val);

    void insertVal(string key, double val); // variable to value

    string getBind(string key);

    string getReversedBind(string val);

    double getValbyVar(string key);

    double getValbyPath(string path);

    /**
     * The funciton would get a binded server variable and set its value
     * @param var the variable to be set in the table
     * @param val the value to set the variable in the table
     */
    void setValue(string var, double val);
};

#endif //PROJECT_VARBINDMAP_H
