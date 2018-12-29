//
// Created by shira on 12/20/18.
//

#ifndef MILESTONE_IFCOMMAND_H
#define MILESTONE_IFCOMMAND_H

#include "ConditionCommand.h"
#include "../Expression/Expression.h"

class IfCommand : public ConditionCommand {
public:
    explicit IfCommand(vector<string> line, Maps* maps); //Expression - boolean, list of commands to excecute
    void execute(/*vector<string>::iterator*/);
    void addCommand(vector<string> command);
    bool isExpressionTrue();
    vector<vector<string>>* getCommands();
    //void doParse();
};

#endif //MILESTONE_IFCOMMAND_H
