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
    while (this->booleanExpression->calculate() == TRUE) {
        for (int i = 0; i < this->commands.size(); i++) {
            this->commands[i].execute();
        }
    }
}