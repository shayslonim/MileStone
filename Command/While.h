//
// Created by shira on 12/20/18.
//

#ifndef MILESTONE_WHILE_H
#define MILESTONE_WHILE_H
#include "Command.h"

class While : public Command
{
public:
    void execute(vector<string>::iterator);
};

#endif //MILESTONE_WHILE_H