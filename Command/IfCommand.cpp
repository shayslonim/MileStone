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
    if (this->booleanExpression->calculate() == TRUE) {
        for (int i = 0; i < this->commands.size(); i++) {
            this->commands[i].execute();
        }
    }
}