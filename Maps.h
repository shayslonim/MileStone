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
    static map<string, string> bindMap;
    static map<string, string> reversedBindMap;
    static map<string, double> valMap;
public:
    static void insertBind(string key, string val);
    static void insertVal(string key, double val);
    static string getBind(string key);
    static string getReversedBind(string val);
    static double getVal(string key);
};

#endif //PROJECT_VARBINDMAP_H
