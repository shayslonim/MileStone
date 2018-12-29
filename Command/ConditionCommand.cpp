//
// Created by shira on 12/26/18.
//

#include "ConditionCommand.h"
#include "../InfixHandler.h"

void ConditionCommand::addCommand(vector<string> command) {
    this->commands->push_back(command);
}

//ConditionCommand::ConditionCommand(vector<string> line, Maps* maps) {
//}

//void ConditionCommand::doParse() {
//    this->parser->parse(*(this->commands));
//}

bool ConditionCommand::isExpressionTrue() {
    InfixHandler infixHnadler = InfixHandler();
    ExpressionFactory factory = ExpressionFactory(this->maps);
    vector<string> expressionVector;
    bool add = false;
    for (int i = 0; i < this->line.size(); i++) {
        if (this->line[i] == "(") {
            add = true;
        }
        if (this->line[i] == ")") {
            add = false;
        }
        if (add) {
            expressionVector.push_back(line[i]);
        }
    }
    this->booleanExpression = factory.getExpression(infixHnadler.convertToPostfix(expressionVector));
    return this->booleanExpression->calculate() == TRUE;
}

vector<vector<string>>* ConditionCommand::getCommands() {
    return this->commands;
}
