//
// Created by shira on 12/20/18.
//

#ifndef MILESTONE_EQUALS_H
#define MILESTONE_EQUALS_H
#include "Command.h"

class Equals : public Command
{
public:
    void execute(vector<string>::iterator);
};

#endif //MILESTONE_EQUALS_H
