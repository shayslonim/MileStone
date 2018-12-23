//
// Created by shira on 12/20/18.
//

#ifndef MILESTONE_IF_H
#define MILESTONE_IF_H
#include "Command.h"

class If : public Command
{
public:
    void execute(vector<string>::iterator);
};

#endif //MILESTONE_IF_H
