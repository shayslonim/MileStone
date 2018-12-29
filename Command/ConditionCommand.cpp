//
// Created by shira on 12/26/18.
//

#include "ConditionCommand.h"
#include "../InfixHandler.h"

void ConditionCommand::addCommand(vector<string> command) {
    this->commands->push_back(command);
}

ConditionCommand::ConditionCommand(vector<string> line, Maps* maps) {
    InfixHandler infixHnadler = InfixHandler();
    ExpressionFactory factory = ExpressionFactory(maps);
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
    this->booleanExpression = factory.getExpression(infixHnadler.convertToPostfix(expressionVector));
}

void ConditionCommand::doParse() {
    this->parser->parse(*(this->commands));
}

bool ConditionCommand::isExpressionTrue() {
    return this->booleanExpression->calculate() == TRUE;
}
