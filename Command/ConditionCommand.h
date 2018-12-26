//
// Created by shira on 12/26/18.
//

#ifndef MILESTONE_CONDITIONCOMMAND_H
#define MILESTONE_CONDITIONCOMMAND_H
#include "Command.h"
#include "../Expression/Expression.h"
#include "../ExpressionFactory.h"

class ConditionCommand : public Command
{
    Expression* booleanExpression;
    vector<Command> commands;
public:
    ConditionCommand(vector<string> line);
    virtual void execute(/*vector<string>::iterator*/);
    void addCommand(Command command);
};

#endif //MILESTONE_CONDITIONCOMMAND_H
