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
    if (this->bindMap.find(key) != this->bindMap.end()) {
        this->pathToValMap[getBind(key)] = val;

        if (this->shouldUpdateServer) {
            this->serverUpdater->update(getBind(key), val);
        }
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
    this->pathToValMap = map<string, double>();
    this->shouldUpdateServer = false;
    //this->serverUpdater = new ServerUpdater();
}

void Maps::setValue(string var, double val) {
    this->pathToValMap[var] = val;
    if (this->bindMap.find(var) != this->bindMap.end()) {
        this->varToValMap[var] = val;
    }
}

void Maps::setServerUpdater(ServerUpdater* updater) {
    this->serverUpdater = updater;
    this->shouldUpdateServer = true;
}

void Maps::closeServerUpdate() {
    this->serverUpdater->disconnect();
    this->shouldUpdateServer = false;
}




