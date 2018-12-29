//
// Created by shira on 12/20/18.
//

#ifndef MILESTONE_WHILECOMMAND_H
#define MILESTONE_WHILECOMMAND_H
#include "ConditionCommand.h"
#include "../Expression/Expression.h"

class WhileCommand : public ConditionCommand
{
public:
    explicit WhileCommand(vector<string> line, Maps* maps); //Expression - boolean, list of commands to excecute
    void execute(/*vector<string>::iterator*/);
    void addCommand(vector<string> command);
    bool isExpressionTrue();
    void doParse();
};

#endif //MILESTONE_WHILECOMMAND_H
