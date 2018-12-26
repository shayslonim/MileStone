//
// Created by shira on 12/20/18.
//

#ifndef MILESTONE_IF_H
#define MILESTONE_IF_H

#include "Command.h"
#include "../Expression/Expression.h"

class IfCommand : public Command {
public:
    IfCommand(); //Expression - boolean, list of commands to excecute
    void execute(/*vector<string>::iterator*/);

private:
    Expression* booleanExpression;
};

#endif //MILESTONE_IF_H
