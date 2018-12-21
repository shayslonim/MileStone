//
// Created by shira on 12/19/18.
//

#include "Maps.h"
using namespace std;

double Maps::getVal(string key) {
    return valMap[key];
}

string Maps::getBind(string key) {
    return bindMap[key];
}

string Maps::getReversedBind(string val) {
    return reversedBindMap[val];
}

void Maps::insertVal(string key, double val) {
    valMap[key] = val;
}

// Double-binding
void Maps::insertBind(string key, string val) {
    bindMap[key] = val;
    reversedBindMap[val] = key;
}
