//
// Created by shira on 12/26/18.
//

#ifndef MILESTONE_EXITCOMMAND_H
#define MILESTONE_EXITCOMMAND_H
#include "Command.h"
#include "../Maps.h"

class ExitCommand : public Command
{
    Maps* maps;
    bool shouldExit;
public:
    ExitCommand(Maps* maps);
    void execute(/*vector<string>::iterator*/);
    bool getShouldExit();
};


#endif //MILESTONE_EXITCOMMAND_H
