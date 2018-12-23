//
// Created by shira on 12/20/18.
//

#ifndef MILESTONE_EQUALS_H
#define MILESTONE_EQUALS_H
#include "Command.h"
#include "../Maps.h"
#include "../Expression/Expression.h"
#define FIRST 0
#define SECOND 2

class EqualsCommand : public Command
{
    Maps* maps;
public:
    EqualsCommand(Maps* maps) {
        this->maps = maps;
    }
    void execute(vector<string>::iterator);
};

#endif //MILESTONE_EQUALS_H
