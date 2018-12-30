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
    varToValMap[key] = val;
    if (this->reversedBindMap.find(key) != this->reversedBindMap.end()) {
        this->pathToValMap[getReversedBind(key)] = val;
        this->updater->update(getReversedBind(key), val);
    }
}

string Maps::getBind(string key) {
    return bindMap[key];
}

string Maps::getReversedBind(string val) {
    return reversedBindMap[val];
}

double Maps::getValbyPath(string path) {
    return this->pathToValMap[path];
}

double Maps::getValbyVar(string key) {
    return varToValMap[key];
}

Maps::Maps() {
    this->bindMap = map<string, string>();
    this->reversedBindMap = map<string, string>();
    this->varToValMap = map<string, double>();
}

void Maps::setValue(string var, double val) {
    this->pathToValMap[var] = val;
    if (this->bindMap.find(var) != this->bindMap.end()) {
        this->varToValMap[var] = val;
    }
    this->updater->update(var, val);
}
