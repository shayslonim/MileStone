//
// Created by shira on 12/20/18.
//

#include "VarCommand.h"

//var breaks = bind "/controls/flight/speedbrake"
//var h0 = heading
void VarCommand::execute() {
    if (find(this->line.begin(), this->line.end(), "bind") != this->line.end()) {
        return;
    }
    vector<string>::iterator iter = this->line.begin();
    this->maps->insertVal(iter[INDEX], 0);
}

VarCommand::VarCommand(vector<string> &line, Maps* maps) {
    this->line = line;
    this->maps = maps;
}
