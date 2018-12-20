//
// Created by shira on 12/19/18.
//

#include "Maps.h"
using namespace std;

double Maps::getVal(string key) {
    if (valMap[key] == NULL) {
        return DEFAULT;
    }
    return valMap[key];
}

string Maps::getBind(string key) {
    return bindMap[key];
}

void Maps::insertVal(string key, double val) {
    valMap[key] = val;
}

void Maps::insertBind(string key, string val) {
    bindMap[key] = val;
}
