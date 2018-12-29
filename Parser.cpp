//
// Created by shay on 12/17/18.
//

#include "Parser.h"

void Parser::parse(vector<vector<string>> line) {
    vector<vector<string>> conditionLines; // Lines that are inside parentheses {...}
    ConditionCommand* conditionCommand;
    Command command;
    for (vector<vector<string>>::iterator iter=line.begin(); iter!=line.end(); ++iter) {
        if (find(iter->begin(), iter->end(), CLOSE) != iter->end()) {
            this->addToCondition = false;
            conditionCommand->execute();
            conditionLines.clear();
        }
        if (find(iter->begin(), iter->end(), BIND) != iter->end()) {
            command = BindCommand(*iter, &(this->maps));
            this->executeIfNeeded(command);
            this->addToConditionIfNeeded(&conditionLines,*iter);
        }
        if (find(iter->begin(), iter->end(), CONNECT) != iter->end()) {
            command = ConnectCommand();
            this->executeIfNeeded(command);
            this->addToConditionIfNeeded(&conditionLines,*iter);
        }
        if (find(iter->begin(), iter->end(), EQUALS) != iter->end()) {
            command = EqualsCommand(*iter, &(this->maps));
            this->executeIfNeeded(command);
            this->addToConditionIfNeeded(&conditionLines,*iter);
        }
        if (find(iter->begin(), iter->end(), IF) != iter->end()) {
            this->addToCondition = true;
            conditionCommand = new IfCommand(*iter, &(this->maps));
        }
        if (find(iter->begin(), iter->end(), WHILE) != iter->end()) {
            this->addToCondition = true;
            conditionCommand = new WhileCommand(*iter, &(this->maps));
        }
        if (find(iter->begin(), iter->end(), OPEN_SERVER) != iter->end()) {
            command = OpenDataServerCommand();
            this->executeIfNeeded(command);
            this->addToConditionIfNeeded(&conditionLines,*iter);
        }
        if (find(iter->begin(), iter->end(), PRINT) != iter->end()) {
            command = PrintCommand(*iter, &(this->maps));
            this->executeIfNeeded(command);
            this->addToConditionIfNeeded(&conditionLines,*iter);
        }
        if (find(iter->begin(), iter->end(), VAR) != iter->end()) {
            command = VarCommand(*iter, &(this->maps));
            this->executeIfNeeded(command);
            this->addToConditionIfNeeded(&conditionLines,*iter);
        }
        if (find(iter->begin(), iter->end(), SLEEP) != iter->end()) {
            command = SleepCommand();
            this->executeIfNeeded(command);
            this->addToConditionIfNeeded(&conditionLines,*iter);
        }
        if (find(iter->begin(), iter->end(), EXIT) != iter->end()) {
            command = ExitCommand();
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
