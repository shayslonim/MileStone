//
// Created by shay on 12/17/18.
//

#include "Parser.h"

void Parser::parse(vector<vector<string>> line) {
    vector<vector<string>> conditionLines; // Lines that are inside parentheses {...}
    ConditionCommand* conditionCommand;
    Command command;
    for (vector<vector<string>>::iterator iter=line.begin(); iter!=line.end(); ++iter) {
        if (find(line.begin(), line.end(), CLOSE) != line.end()) {
            this->addToCondition = false;
            conditionCommand->execute();
            conditionLines.clear();
        }
        if (find(line.begin(), line.end(), BIND) != line.end()) {
            command = BindCommand(*iter, &(this->maps));
            this->executeIfNeeded(command);
            this->addToConditionIfNeeded(&conditionLines,*iter);
        }
        if (find(line.begin(), line.end(), CONNECT) != line.end()) {
            command = ConnectCommand();
            this->executeIfNeeded(command);
            this->addToConditionIfNeeded(&conditionLines,*iter);
        }
        if (find(line.begin(), line.end(), EQUALS) != line.end()) {
            command = EqualsCommand(*iter, &(this->maps));
            this->executeIfNeeded(command);
            this->addToConditionIfNeeded(&conditionLines,*iter);
        }
        if (find(line.begin(), line.end(), IF) != line.end()) {
            this->addToCondition = true;
            conditionCommand = new IfCommand(*iter);
        }
        if (find(line.begin(), line.end(), WHILE) != line.end()) {
            this->addToCondition = true;
            conditionCommand = new WhileCommand(*iter);
        }
        if (find(line.begin(), line.end(), OPEN_SERVER) != line.end()) {
            command = OpenDataServerCommand();
            this->executeIfNeeded(command);
            this->addToConditionIfNeeded(&conditionLines,*iter);
        }
        if (find(line.begin(), line.end(), PRINT) != line.end()) {
            command = PrintCommand(*iter, &(this->maps));
            this->executeIfNeeded(command);
            this->addToConditionIfNeeded(&conditionLines,*iter);
        }
        if (find(line.begin(), line.end(), VAR) != line.end()) {
            command = VarCommand(*iter, &(this->maps));
            this->executeIfNeeded(command);
            this->addToConditionIfNeeded(&conditionLines,*iter);
        }
        if (find(line.begin(), line.end(), SLEEP) != line.end()) {
            command = SleepCommand();
            this->executeIfNeeded(command);
            this->addToConditionIfNeeded(&conditionLines,*iter);
        }
        if (find(line.begin(), line.end(), EXIT) != line.end()) {
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
