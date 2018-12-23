//
// Created by shira on 12/19/18.
//

#include "Maps.h"
using namespace std;

#include <string>
#include <map>
#include "Command/Command.h"
using namespace std;

void Maps::insertBind(string key, string val) {
    bindMap[key] = val;
    reversedBindMap[val] = key;
}

void Maps::insertVal(string key, double val) {
    valMap[key] = val;
}

string Maps::getBind(string key) {
    return bindMap[key];
}

string Maps::getReversedBind(string val) {
    return reversedBindMap[val];
}

double Maps::getVal(string key) {
    return valMap[key];
}

Maps::Maps() {
    this->bindMap = map<string, string>();
    this->reversedBindMap = map<string, string>();
    this->valMap = map<string, double>();
}
