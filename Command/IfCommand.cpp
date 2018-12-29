//
// Created by shira on 12/20/18.
//

#include "IfCommand.h"

//void IfCommand::addCommand(Command command) {
//    this->commands.push_back(command);
//}
//
//IfCommand::IfCommand(Expression* exp) {
//    this->booleanExpression = exp;
//}

void IfCommand::execute(/*vector<string>::iterator*/) {
    if (this->isExpressionTrue()) {
        this->doParse();
    }
}

IfCommand::IfCommand(vector<string> line, Maps* maps) : ConditionCommand(line, maps) {}

bool IfCommand::isExpressionTrue() {
    return ConditionCommand::isExpressionTrue();
}

void IfCommand::doParse() {
    ConditionCommand::doParse();
}

void IfCommand::addCommand(vector<string> command) {
    ConditionCommand::addCommand(command);
}
