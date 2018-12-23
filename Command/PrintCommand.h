//
// Created by shira on 12/20/18.
//

#ifndef MILESTONE_PRINT_H
#define MILESTONE_PRINT_H
#include "Command.h"

class PrintCommand : public Command
{
public:
    PrintCommand();
    void execute(/*vector<string>::iterator*/);
};

#endif //MILESTONE_PRINT_H