//
// Created by shira on 12/26/18.
//

#include "ConditionCommand.h"

void ConditionCommand::addCommand(Command command) {
    this->commands.push_back(command);
}

ConditionCommand::ConditionCommand(vector<string> line) {
    vector<string> expressionVector;
    bool add = false;
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == "(") {
            add = true;
        }
        if (line[i] == ")") {
            add = false;
        }
        if (add) {
            expressionVector.push_back(line[i]);
        }
    }
    this->booleanExpression = exp;
}