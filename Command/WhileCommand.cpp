//
// Created by shira on 12/20/18.
//

#include "WhileCommand.h"

//void WhileCommand::addCommand(Command command) {
//    this->commands.push_back(command);
//}
//
//WhileCommand::WhileCommand(Expression* exp) {
//    this->booleanExpression = exp;
//}

void WhileCommand::execute(/*vector<string>::iterator*/) {
    if (this->isExpressionTrue()) {
        this->doParse();
    }
}

WhileCommand::WhileCommand(vector<string> line) : ConditionCommand(line) {}

bool WhileCommand::isExpressionTrue() {
    return ConditionCommand::isExpressionTrue();
}

void WhileCommand::doParse() {
    ConditionCommand::doParse();
}

void WhileCommand::addCommand(vector<string> command) {
    ConditionCommand::addCommand(command);
}