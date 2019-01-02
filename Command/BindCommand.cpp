//
// Created by shira on 12/20/18.
//

#include "BindCommand.h"
#include <iostream>

// The vector is expected to include strings without spaces, ex: var breaks = bind "/controls/flight/speedbrake"
void BindCommand::execute(/*vector<string>::iterator iter*/) {
    vector<string>::iterator iter = this->line.begin();
    if (iter[0] == "var") {
        // std::cout << line.size() << std::endl;
        this->maps->insertBind(iter[FIRST + 1], iter[SECOND + 1]);
    } else {
        this->maps->insertBind(iter[FIRST], iter[SECOND]);
    }
}

BindCommand::BindCommand(vector<string> line, Maps* maps) {
    this->line = line;
    this->maps = maps;
}
