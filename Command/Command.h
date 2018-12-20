//
// Created by shay on 12/17/18.
//

#ifndef MILESTONE_COMMAND_H
#define MILESTONE_COMMAND_H

#include <string>
#include <vector>

using namespace std;
class Command {
    virtual void execute(vector<string>::iterator iter) = 0;
};

#endif //MILESTONE_COMMAND_H
