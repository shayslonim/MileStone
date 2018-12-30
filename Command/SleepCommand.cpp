//
// Created by shira on 12/24/18.
//

#include <thread>
#include <unistd.h>
#include "SleepCommand.h"
#include "../ExpressionFactory.h"
#include "../InfixHandler.h"


SleepCommand::SleepCommand(vector<string> line, Maps* maps) {
    InfixHandler infixHnadler = InfixHandler();
    ExpressionFactory factory = ExpressionFactory(maps);
    vector<string>::iterator iter = line.begin();
    vector<string> expressionVector;
    int start = START_SLEEP;
    for (int i = start; i < line.size(); i++) {
        expressionVector.push_back(line[i]);
    }
    // Use ShuntingYard algorithm of Expression on iter[start] until line end
    Expression* exp = factory.getExpression(infixHnadler.convertToPostfix(expressionVector));
    // Calculate vars to double -> insert to InfixHndler -> insert to factory
    this->time = exp->calculate();
}

void SleepCommand::execute() {
    sleep(this->time/MILI);
}
