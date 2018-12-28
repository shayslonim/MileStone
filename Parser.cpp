//
// Created by shay on 12/17/18.
//

#include <regex>
#include "Parser.h"

void Parser::parse(vector<vector<string>>* line) {
    vector<vector<string>> conditionLines; // Lines that are inside parentheses {...}
    ConditionCommand* conditionCommand;
    for (vector<vector<string>>::iterator iter=line->begin(); iter!=line->end(); ++iter) {
        if (find(line->begin(), line->end(), CLOSE) != line->end()) {
            this->addToCondition = false;
            this->inner = new Parser();
            inner->parse(&conditionLines);
            conditionLines.clear();
        }
        if (find(line->begin(), line->end(), BIND) != line->end()) {
            BindCommand command = BindCommand(*iter, &(this->maps));
            command.execute();
//        this->add(command);
        }
        if (find(line->begin(), line->end(), CONNECT) != line->end()) {
            ConnectCommand command = ConnectCommand();
            command.execute();
//        this->add(command);
        }
        if (find(line->begin(), line->end(), EQUALS) != line->end()) {
            EqualsCommand command = EqualsCommand(*iter, &(this->maps));
            command.execute();
//        this->add(command);
        }
        if (find(line->begin(), line->end(), IF) != line->end()) { // @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ add command to conditionLine, change add function for this and use in all ifs
            this->addToCondition = true;
            IfCommand* ifCommand = new IfCommand(*iter);
            conditionCommand = ifCommand;

            // command.execute();
//        this->conditions.push(&command);
//        this->add(command);
        }
        if (find(line->begin(), line->end(), WHILE) != line->end()) {
            this->addToCondition = true;
//        this->countCondition++;
            conditionCommand = WhileCommand(*iter);
            // command.execute();
//        this->conditions.push(&command);
//        this->add(command);
        }
        if (find(line->begin(), line->end(), OPEN_SERVER) != line->end()) {
            OpenDataServerCommand command = OpenDataServerCommand();
            command.execute();
//        this->add(command);
        }
        if (find(line->begin(), line->end(), PRINT) != line->end()) {
            PrintCommand command = PrintCommand(*iter, &(this->maps));
            command.execute();
//        this->add(command);
        }
        if (find(line->begin(), line->end(), VAR) != line->end()) {
            VarCommand command = VarCommand(*iter, &(this->maps));
            command.execute();
//        this->add(command);
        }
        if (find(line->begin(), line->end(), SLEEP) != line->end()) {
            SleepCommand command = SleepCommand();
            command.execute();
        }
        if (find(line->begin(), line->end(), EXIT) != line->end()) {
            ExitCommand command = ExitCommand();
            command.execute();
        }
    }
}

Parser::Parser() {
    this->maps = Maps();
    this->addToCondition = false;
    this->lex = Lexer();
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
