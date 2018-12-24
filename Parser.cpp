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
#include "Command/Command.h"
#define BIND "bind"
#define CONNECT "connect"
#define EQUALS "="
#define IF "if"
#define OPEN_SERVER "openDataServer"
#define PRINT "print"
#define VAR "var"
#define WHILE "while"

void Parser::parse(vector <string>* line) {
    if (find(line->begin(), line->end(), BIND) != line->end()) {
        BindCommand command = BindCommand(*line, &(this->maps));
        this->commands.push_back(command);
    }
//    if (find(line->begin(), line->end(), CONNECT) != line->end()) {
//        ConnectCommand command = ConnectCommand();
//        this->commands.push_back(command);
//    }
    if (find(line->begin(), line->end(), EQUALS) != line->end()) {
        EqualsCommand command = EqualsCommand(*line, &(this->maps));
        this->commands.push_back(command);
    }
//    if (find(line->begin(), line->end(), IF) != line->end()) {
//        IfCommand command = IfCommand();
//        this->commands.push_back(command);
//    }
//    if (find(line->begin(), line->end(), OPEN_SERVER) != line->end()) {
//        OpenDataServerCommand command = OpenDataServerCommand();
//        this->commands.push_back(command);
//    }
//    if (find(line->begin(), line->end(), PRINT) != line->end()) {
//        PrintCommand command = PrintCommand();
//        this->commands.push_back(command);
//    }
    if (find(line->begin(), line->end(), VAR) != line->end()) {
        VarCommand command = VarCommand(*line, &(this->maps));
        this->commands.push_back(command);
    }
//    if (find(line->begin(), line->end(), WHILE) != line->end()) {
//        WhileCommand command = WhileCommand();
//        this->commands.push_back(command);
//    }
}

Parser::Parser() {
    this->maps = Maps();
    this->commands = vector<Command>();
}
