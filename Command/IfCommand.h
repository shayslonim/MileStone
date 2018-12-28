//
// Created by shira on 12/20/18.
//

#ifndef MILESTONE_IF_H
#define MILESTONE_IF_H

#include "ConditionCommand.h"
#include "../Expression/Expression.h"

class IfCommand : public ConditionCommand {
public:
    IfCommand(vector<string> line); //Expression - boolean, list of commands to excecute
    void execute(/*vector<string>::iterator*/);
    void addCommand(vector<string> command);
    bool isExpressionTrue();
    void doParse();
};

#endif //MILESTONE_IF_H
