//
// Created by shay on 12/17/18.
//

#ifndef MILESTONE_PARSER_H
#define MILESTONE_PARSER_H

#include <string>
#include <vector>
#include <stack>
#include <regex>
#include "Maps.h"
// #include "Command/ConditionCommand.h"
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
#include "Lexer.h"

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

using namespace std;

class ConditionCommand;

class Parser {
    Maps maps;
    bool addToCondition;
    // Lexer lex;
//    vector<Command> commands;
    //ConditionCommand* condition;
//    stack<ConditionCommand*> conditions;
//    int countCondition;
public:
    Parser();
    void parse(vector<vector<string>>* line);
//    void add(Command command);
};


#endif //MILESTONE_PARSER_H
