//
// Created by shira on 12/20/18.
//

#ifndef MILESTONE_EQUALS_H
#define MILESTONE_EQUALS_H
#include "Command.h"
#include "../Maps.h"
#include "../Expression/Expression.h"
#define FIRST_EQUALS 0
#define SECOND_EQUALS 2

class EqualsCommand : public Command
{
    vector<string> line;
    Maps* maps;
public:
    EqualsCommand(vector<string> &line, Maps* maps);
    void execute(/*vector<string>::iterator*/);
};

#endif //MILESTONE_EQUALS_H
