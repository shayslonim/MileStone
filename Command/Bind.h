//
// Created by shira on 12/20/18.
//

#ifndef MILESTONE_BIND_H
#define MILESTONE_BIND_H
#include "Command.h"

class Bind : public Command
{
    void execute(vector<string>::iterator);
};

#endif //MILESTONE_BIND_H
