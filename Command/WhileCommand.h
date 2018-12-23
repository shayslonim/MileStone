//
// Created by shira on 12/20/18.
//

#ifndef MILESTONE_WHILE_H
#define MILESTONE_WHILE_H
#include "Command.h"

class WhileCommand : public Command
{
public:
    WhileCommand();
    void execute(vector<string>::iterator);
};

#endif //MILESTONE_WHILE_H
