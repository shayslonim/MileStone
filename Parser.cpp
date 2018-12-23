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


void Parser::parse(vector <string>* line) {
    if (find(line->begin(), line->end(), BIND) != line->end()) {
        BindCommand command = BindCommand(*line, &(this->maps));
        this->commands.push_back(command);
    }
    if (find(line->begin(), line->end(), CONNECT) != line->end()) {
        ConnectCommand command = ConnectCommand();
        this->commands.push_back(command);
    }
}

Parser::Parser() {
    this->maps = Maps();
    this->commands = vector<Command>();
}
