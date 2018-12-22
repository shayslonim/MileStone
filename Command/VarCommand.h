//
// Created by shira on 12/20/18.
//

#ifndef MILESTONE_VAR_H
#define MILESTONE_VAR_H
#include "Command.h"
#include "../Maps.h"
#define INDEX 1

class Var : public Command
{
    Maps* maps;
public:
    Var(Maps* maps) {
        this->maps = maps;
    }
    void execute(vector<string>::iterator);

};

#endif //MILESTONE_VAR_H
