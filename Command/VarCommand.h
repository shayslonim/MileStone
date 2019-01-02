//
// Created by shira on 12/20/18.
//

#ifndef MILESTONE_VAR_H
#define MILESTONE_VAR_H
#include <regex>
#include "Command.h"
#include "../Maps.h"
#define INDEX 1
using namespace std;

class VarCommand : public Command
{
    vector<string> line;
    Maps* maps;
public:
    VarCommand(vector<string> &line, Maps* maps);
    void execute(/*vector<string>::iterator*/);
};

#endif //MILESTONE_VAR_H
