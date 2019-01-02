//
// Created by shira on 12/24/18.
//

#ifndef MILESTONE_SLEEPCOMMAND_H
#define MILESTONE_SLEEPCOMMAND_H
#include "Command.h"
#include "../Expression/Expression.h"
#include "../Maps.h"
#define START_SLEEP 1
#define MILI 1000

class SleepCommand : public Command
{
    double time;
public:
    SleepCommand(vector<string> &line, Maps* maps);
    void execute(/*vector<string>::iterator*/);
};


#endif //MILESTONE_SLEEPCOMMAND_H
