//
// Created by shay on 12/17/18.
//

#include "Parser.h"

void Parser::parse(vector<vector<string>> line) {
    vector<vector<string>> conditionLines; // Lines that are inside parentheses {...}
    ConditionCommand* conditionCommand;
    string condition;
    for (vector<vector<string>>::iterator iter=line.begin(); iter!=line.end(); ++iter) {
        if (find(iter->begin(), iter->end(), CLOSE) != iter->end()) {
            this->addToCondition = false;
            this->inner = new Parser();
            //conditionCommand->execute();
            if (condition == IF) {
                if (conditionCommand->isExpressionTrue()) {
                    this->inner->parse(*(conditionCommand->getCommands()));
                }
            } else {
                if (condition == WHILE) {
                    while (conditionCommand->isExpressionTrue()) {
                        this->inner->parse(*(conditionCommand->getCommands()));
                    }
                }
            }
            conditionLines.clear();
        }
        if (find(iter->begin(), iter->end(), BIND) != iter->end()) {
            BindCommand command = BindCommand(*iter, &(this->maps));
            this->executeIfNeeded(command);
            this->addToConditionIfNeeded(&conditionLines,*iter);
        }
        if (find(iter->begin(), iter->end(), CONNECT) != iter->end()) {
            ConnectCommand command = ConnectCommand();
            this->executeIfNeeded(command);
            this->addToConditionIfNeeded(&conditionLines,*iter);
        }
        if (find(iter->begin(), iter->end(), EQUALS) != iter->end()) {
            EqualsCommand command = EqualsCommand(*iter, &(this->maps));
            this->executeIfNeeded(command);
            this->addToConditionIfNeeded(&conditionLines,*iter);
        }
        if (find(iter->begin(), iter->end(), IF) != iter->end()) {
            this->addToCondition = true;
            condition = IF;
            conditionCommand = new IfCommand(*iter, &(this->maps));
        }
        if (find(iter->begin(), iter->end(), WHILE) != iter->end()) {
            this->addToCondition = true;
            condition = WHILE;
            conditionCommand = new WhileCommand(*iter, &(this->maps));
        }
        if (find(iter->begin(), iter->end(), OPEN_SERVER) != iter->end()) {
            OpenDataServerCommand command = OpenDataServerCommand();
            this->executeIfNeeded(command);
            this->addToConditionIfNeeded(&conditionLines,*iter);
        }
        if (find(iter->begin(), iter->end(), PRINT) != iter->end()) {
            PrintCommand command = PrintCommand(*iter, &(this->maps));
            this->executeIfNeeded(command);
            this->addToConditionIfNeeded(&conditionLines,*iter);
        }
        if (find(iter->begin(), iter->end(), VAR) != iter->end()) {
            VarCommand command = VarCommand(*iter, &(this->maps));
            this->executeIfNeeded(command);
            this->addToConditionIfNeeded(&conditionLines,*iter);
        }
        if (find(iter->begin(), iter->end(), SLEEP) != iter->end()) {
            SleepCommand command = SleepCommand();
            this->executeIfNeeded(command);
            this->addToConditionIfNeeded(&conditionLines,*iter);
        }
        if (find(iter->begin(), iter->end(), EXIT) != iter->end()) {
            ExitCommand command = ExitCommand();
            this->executeIfNeeded(command);
            this->addToConditionIfNeeded(&conditionLines,*iter);
        }
    }
}

Parser::Parser() {
    this->maps = Maps();
    this->addToCondition = false;
}

void Parser::executeIfNeeded(Command command) {
    if (!this->addToCondition) {
        command.execute();
    }
}

void Parser::addToConditionIfNeeded(vector<vector<string>>* condition, vector<string> line) {
    if (this->addToCondition) {
        condition->push_back(line);
    }
}
