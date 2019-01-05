//
// Created by shira on 12/26/18.
//

#include "ConditionCommand.h"
#include "../InfixHandler.h"

/**
 * Add to list of commands
 * @param command vector<string>
 */
void ConditionCommand::addCommand(vector<string> command) {
    this->commands->push_back(command);
}

/**
 * Constructor
 * @param line vector string pointer
 * @param maps Maps*
 */
ConditionCommand::ConditionCommand(vector<string> &line, Maps* maps) {
    this->line = line;
    this->maps = maps;
    this->commands = new vector<vector<string>>();
}

//void ConditionCommand::doParse() {
//    this->parser->parse(*(this->commands));
//}

/**
 * Evaluate
 * @return true or false by the expression
 */
bool ConditionCommand::isExpressionTrue() {
    InfixHandler infixHnadler = InfixHandler();
    ExpressionFactory factory = ExpressionFactory(this->maps);
    vector<string> expressionVector = vector<string>();
    //expressionVector = vector<string>(line.begin() + 1, line.end());
    //cout << this->line.size() <<std::endl;
    for (int i = 1; i < this->line.size(); i++) {
        if (this->line[i] != "{") {
            expressionVector.push_back(this->line[i]);
        }
    }
//    int count = 0;
//    for (int i = 1; i < this->line.size(); i++) {
////        if (this->line[i] == "(") {
////            count++;
////        }
////        if (this->line[i] == ")") {
////            count--;
////        }
////        if (count > 0) {
//            expressionVector.push_back(line[i]);
////        }
//    }
    this->booleanExpression = factory.getExpression(infixHnadler.convertToPostfix(expressionVector));
    return this->booleanExpression->calculate() == TRUE;
}

/**
 * Get the list of commands
 * @return vector<vector<string>>* commands
 */
vector<vector<string>>* ConditionCommand::getCommands() {
    return this->commands;
}

/**
 * Do the commands
 */
void ConditionCommand::execute(/*vector<string>::iterator*/) {}

/**
 * Destructor
 */
ConditionCommand::~ConditionCommand() {}