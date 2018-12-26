//
// Created by shira on 12/20/18.
//

#ifndef MILESTONE_WHILE_H
#define MILESTONE_WHILE_H
#include "ConditionCommand.h"
#include "../Expression/Expression.h"

class WhileCommand : public ConditionCommand
{
    Expression* booleanExpression;
    vector<Command> commands;
public:
    WhileCommand(vector<string> line);
    void execute(/*vector<string>::iterator*/);
    void addCommand(Command command);
};

#endif //MILESTONE_WHILE_H
