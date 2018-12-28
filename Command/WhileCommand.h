//
// Created by shira on 12/20/18.
//

#ifndef MILESTONE_WHILE_H
#define MILESTONE_WHILE_H
#include "ConditionCommand.h"
#include "../Expression/Expression.h"

class WhileCommand : public ConditionCommand
{
public:
    WhileCommand(vector<string> line); //Expression - boolean, list of commands to excecute
    void execute(/*vector<string>::iterator*/);
    void addCommand(vector<string> command);
    bool isExpressionTrue();
    void doParse();
};

#endif //MILESTONE_WHILE_H
