//
// Created by shay on 12/17/18.
//

#include "Parser.h"

void Parser::parse(vector<vector<string>>* line) {
    vector<vector<string>> conditionLines; // Lines that are inside parentheses {...}
    ConditionCommand* conditionCommand;
    Command command;
    for (vector<vector<string>>::iterator iter=line->begin(); iter!=line->end(); ++iter) {
        if (find(line->begin(), line->end(), CLOSE) != line->end()) {
            this->addToCondition = false;
            conditionCommand->execute();
            conditionLines.clear();
        }
        if (find(line->begin(), line->end(), BIND) != line->end()) {
            command = BindCommand(*iter, &(this->maps));
            command.execute();
//        this->add(command);
        }
        if (find(line->begin(), line->end(), CONNECT) != line->end()) {
            command = ConnectCommand();
            command.execute();
//        this->add(command);
        }
        if (find(line->begin(), line->end(), EQUALS) != line->end()) {
            command = EqualsCommand(*iter, &(this->maps));
            command.execute();
//        this->add(command);
        }
        if (find(line->begin(), line->end(), IF) != line->end()) { // @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ add command to conditionLine, change add function for this and use in all ifs
            this->addToCondition = true;
            conditionCommand = new IfCommand(*iter);


        }
        if (find(line->begin(), line->end(), WHILE) != line->end()) {
            this->addToCondition = true;
            conditionCommand = new WhileCommand(*iter);


        }
        if (find(line->begin(), line->end(), OPEN_SERVER) != line->end()) {
            command = OpenDataServerCommand();
            command.execute();
//        this->add(command);
        }
        if (find(line->begin(), line->end(), PRINT) != line->end()) {
            command = PrintCommand(*iter, &(this->maps));
            command.execute();
//        this->add(command);
        }
        if (find(line->begin(), line->end(), VAR) != line->end()) {
            command = VarCommand(*iter, &(this->maps));
            command.execute();
//        this->add(command);
        }
        if (find(line->begin(), line->end(), SLEEP) != line->end()) {
            command = SleepCommand();
            command.execute();
        }
        if (find(line->begin(), line->end(), EXIT) != line->end()) {
            command = ExitCommand();
            command.execute();
        }
    }
}

Parser::Parser() {
    this->maps = Maps();
    this->addToCondition = false;
//    this->commands = vector<Command>();
//    this->countCondition = 0;
}

//void Parser::add(Command command) {
//if (this->addToCondition) {
//    this->conditions.top()->addCommand(command);
//}
//else {
//    this->commands.push_back(command);
//    }
//}
