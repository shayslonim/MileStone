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
    map<string, string> bindMap;
    map<string, string> reversedBindMap;
    map<string, double> valMap;
public:
    // Double-binding
    void insertBind(string key, string val);

    void insertVal(string key, double val);

    string getBind(string key);

    string getReversedBind(string val);

    double getVal(string key);
};

#endif //PROJECT_VARBINDMAP_H
