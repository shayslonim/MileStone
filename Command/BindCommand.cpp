//
// Created by shira on 12/20/18.
//

#include "BindCommand.h"
#include <iostream>

/**
 * bind between a variable to a path
 */
// The vector is expected to include strings without spaces, ex: var breaks = bind "/controls/flight/speedbrake"
void BindCommand::execute(/*vector<string>::iterator iter*/) {
    vector<string>::iterator iter = this->line.begin();
    string variable;
    string pathOld;
    string path = string();
    if (iter[0] == "var") {
        // std::cout << line.size() << std::endl;
        //this->maps->insertBind(iter[FIRST + 1], iter[SECOND + 1]);
        variable = iter[FIRST + 1];
        pathOld = iter[SECOND + 1];
    } else {
        //this->maps->insertBind(iter[FIRST], iter[SECOND]);
        variable = iter[FIRST];
        pathOld = iter[SECOND];
    }
    for (int i = 0; i < pathOld.length(); i++) {
        if (pathOld[i] != '"') {
            path += pathOld[i];
        }
    }
    this->maps->insertBind(variable, path);
}

/**
 * constructor
 * @param line vector string pointer
 * @param maps Maps*
 */
BindCommand::BindCommand(vector<string> &line, Maps* maps) {
    this->line = line;
    this->maps = maps;
}
