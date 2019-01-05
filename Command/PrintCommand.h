//
// Created by shira on 12/20/18.
//

#ifndef MILESTONE_PRINT_H
#define MILESTONE_PRINT_H
#include <iostream>
#include "Command.h"
#include "../Maps.h"
#include "../ExpressionFactory.h"
#define INDEX_PRINT 1
#define START 1
#define END 1

class PrintCommand : public Command
{
    vector<string> line;
    Maps* maps;
public:
    PrintCommand(vector<string> &line, Maps* maps);
    void execute(/*vector<string>::iterator*/);
};

#endif //MILESTONE_PRINT_H