//
// Created by shira on 12/26/18.
//

#ifndef MILESTONE_CONDITIONCOMMAND_H
#define MILESTONE_CONDITIONCOMMAND_H
#include "Command.h"
#include "../Expression/Expression.h"
#include "../ExpressionFactory.h"
//#include "../Parser.h"

//class Parser;

class ConditionCommand : public Command
{
    Expression* booleanExpression;
    vector<vector<string>>* commands;
    //Parser* parser;
public:
    ConditionCommand(vector<string> line, Maps* maps);
    virtual void execute();
    void addCommand(vector<string> command);
    // void doParse();
    bool isExpressionTrue();
    vector<vector<string>>* getCommands();
};

#endif //MILESTONE_CONDITIONCOMMAND_H
