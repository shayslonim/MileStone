//
// Created by shay on 12/17/18.
//

#include "Parser.h"

void Parser::parse(vector<vector<string>> line) {
    vector<vector<string>> conditionLines; // Lines that are inside parentheses {...}
    ConditionCommand* conditionCommand;
    Command* command;
    string condition;

    for (vector<vector<string>>::iterator iter = line.begin(); iter != line.end(); ++iter) {

        if (find(iter->begin(), iter->end(), CLOSE) != iter->end()) {
            this->addToCondition = false;
            this->inner = new Parser(this->maps);
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
            command = new BindCommand(*iter, this->maps);
            this->executeIfNeeded(command);
            this->addToConditionIfNeeded(&conditionLines, *iter);
        }
        if (find(iter->begin(), iter->end(), CONNECT) != iter->end()) {
            command = new ConnectCommand(*iter, this->maps);
            this->executeIfNeeded(command);
            this->addToConditionIfNeeded(&conditionLines, *iter);
        }
        if (find(iter->begin(), iter->end(), EQUALS) != iter->end()) {
            command = new EqualsCommand(*iter, this->maps);
            this->executeIfNeeded(command);
            this->addToConditionIfNeeded(&conditionLines, *iter);
        }
        if (find(iter->begin(), iter->end(), IF) != iter->end()) {
            this->addToCondition = true;
            condition = IF;
            conditionCommand = new ConditionCommand(*iter, this->maps);
        }
        if (find(iter->begin(), iter->end(), WHILE) != iter->end()) {
            this->addToCondition = true;
            condition = WHILE;
            conditionCommand = new ConditionCommand(*iter, this->maps);
        }
        if (find(iter->begin(), iter->end(), OPEN_SERVER) != iter->end()) {
            command = new OpenDataServerCommand(*iter, this->maps);
            this->executeIfNeeded(command);
            this->addToConditionIfNeeded(&conditionLines, *iter);
        }
        if (find(iter->begin(), iter->end(), PRINT) != iter->end()) {
            command = new PrintCommand(*iter, this->maps);
            this->executeIfNeeded(command);
            this->addToConditionIfNeeded(&conditionLines, *iter);
        }
        if (find(iter->begin(), iter->end(), VAR) != iter->end()) {
            command = new VarCommand(*iter, this->maps);
            this->executeIfNeeded(command);
            this->addToConditionIfNeeded(&conditionLines, *iter);
        }
        if (find(iter->begin(), iter->end(), SLEEP) != iter->end()) {
            command = new SleepCommand(*iter, this->maps);
            this->executeIfNeeded(command);
            this->addToConditionIfNeeded(&conditionLines, *iter);
        }
        if (find(iter->begin(), iter->end(), EXIT) != iter->end()) {
            command = new ExitCommand(this->maps);
            this->executeIfNeeded(command);
            this->addToConditionIfNeeded(&conditionLines, *iter);
            //stop = command.getShouldExit();
        }
    }
}

Parser::Parser(Maps* maps) {
    this->maps = maps;
    this->addToCondition = false;
}

void Parser::executeIfNeeded(Command* command) {
    if (!this->addToCondition) {
        command->execute();
    }
}

void Parser::addToConditionIfNeeded(vector<vector<string>>* condition, vector<string> line) {
    if (this->addToCondition) {
        condition->push_back(line);
    }
}
