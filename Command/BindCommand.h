//
// Created by shira on 12/20/18.
//

#ifndef MILESTONE_BIND_H
#define MILESTONE_BIND_H
#include "Command.h"
#include "../Maps.h"
#define FIRST 0
#define SECOND 3

class BindCommand : public Command
{
    vector<string> line;
    Maps* maps;
public:
    BindCommand(vector<string> &line, Maps* maps);
    void execute(/*vector<string>::iterator*/) override;
};

#endif //MILESTONE_BIND_H
