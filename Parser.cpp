//
// Created by shay on 12/17/18.
//

#include <regex>
#include "Parser.h"
#include "Command/BindCommand.h"
#include "Command/ConnectCommand.h"
#include "Command/EqualsCommand.h"
#include "Command/IfCommand.h"
#include "Command/OpenDataServerCommand.h"
#include "Command/PrintCommand.h"
#include "Command/VarCommand.h"
#include "Command/WhileCommand.h"
#include "Command/SleepCommand.h"
#include "Command/ExitCommand.h"
#include "Command/Command.h"
#define BIND "bind"
#define CONNECT "connect"
#define EQUALS "="
#define IF "if"
#define OPEN_SERVER "openDataServer"
#define SLEEP "sleep"
#define EXIT "exit"
#define PRINT "print"
#define VAR "var"
#define WHILE "while"
#define CLOSE "}"

void Parser::parse(vector <string>* line) {
    if (find(line->begin(), line->end(), CLOSE) != line->end()) {
//        this->countCondition--;
//        this->conditions.pop();
//        if (this->countCondition == 0) {
//            this->addToCondition = false;
//        }
    }
    if (find(line->begin(), line->end(), BIND) != line->end()) {
        BindCommand command = BindCommand(*line, &(this->maps));
        command.execute();
//        this->add(command);
    }
//    if (find(line->begin(), line->end(), CONNECT) != line->end()) {
//        ConnectCommand command = ConnectCommand();
//        this->add(command);
//    }
    if (find(line->begin(), line->end(), EQUALS) != line->end()) {
        EqualsCommand command = EqualsCommand(*line, &(this->maps));
        command.execute();
//        this->add(command);
    }
    if (find(line->begin(), line->end(), IF) != line->end()) {
//        this->addToCondition = true;
//        this->countCondition++;
        IfCommand command = IfCommand(*line);
        command.execute();
//        this->conditions.push(&command);
//        this->add(command);
    }
    if (find(line->begin(), line->end(), WHILE) != line->end()) {
//        this->addToCondition = true;
//        this->countCondition++;
        WhileCommand command = WhileCommand(*line);
        command.execute();
//        this->conditions.push(&command);
//        this->add(command);
    }
//    if (find(line->begin(), line->end(), OPEN_SERVER) != line->end()) {
//        OpenDataServerCommand command = OpenDataServerCommand();
//        this->add(command);
//    }
    if (find(line->begin(), line->end(), PRINT) != line->end()) {
        PrintCommand command = PrintCommand(*line, &(this->maps));
        command.execute();
//        this->add(command);
    }
    if (find(line->begin(), line->end(), VAR) != line->end()) {
        VarCommand command = VarCommand(*line, &(this->maps));
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

Parser::Parser() {
    this->maps = Maps();
//    this->commands = vector<Command>();
//    this->addToCondition = false;
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
