//
// Created by shira on 12/20/18.
//

#include "EqualsCommand.h"
#include "../InfixHandler.h"
#include "../ExpressionFactory.h"

//var breaks = bind "/controls/flight/speedbrake"
//breaks = 0
//var h0 = heading
//aileron = - roll / 70
/**
 * Insert a value to a variable
 */
void EqualsCommand::execute(/*vector<string>::iterator iter*/) {
    InfixHandler infixHnadler = InfixHandler();
    ExpressionFactory factory = ExpressionFactory(maps);
    vector<string>::iterator iter = this->line.begin();
    vector<string> expressionVector;
    int first = FIRST_EQUALS;
    int second = SECOND_EQUALS;
    if (iter[0] == "var") {
        first++;
        second++;
    }
    if (iter[second] == "bind") {
        return;
        //second++;
    }
    if (infixHnadler.isANumber(iter[second])) {
        this->maps->insertVal(iter[first], stod(iter[second]));
    }
    else {
        for (int i = second; i < this->line.size(); i++) {
            expressionVector.push_back(this->line[i]);
        }
        // Use ShuntingYard algorithm of Expression on iter[second] until line end
        Expression* exp = factory.getExpression(infixHnadler.convertToPostfix(expressionVector));
        // Calculate vars to double -> insert to InfixHndler -> insert to factory
        this->maps->insertVal(iter[first], exp->calculate());
    }
}

/**
 * Constructor
 * @param line vector<string> pointer
 * @param maps Maps*
 */
EqualsCommand::EqualsCommand(vector<string> &line, Maps* maps) {
    this->line = line;
    this->maps = maps;
}
