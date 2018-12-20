//
// Created by shira on 12/20/18.
//

#ifndef MILESTONE_VAR_H
#define MILESTONE_VAR_H
#include "Command.h"

class Var : public Command
{
public:
    void execute(vector<string>::iterator);
};

#endif //MILESTONE_VAR_H
