//
// Created by shay on 12/17/18.
//

#ifndef MILESTONE_PARSER_H
#define MILESTONE_PARSER_H

#include <string>
#include <vector>
#include <stack>
#include "Maps.h"
#include "Command/ConditionCommand.h"

using namespace std;

class Parser {
    Maps maps;
    vector<Command> commands;
    //ConditionCommand* condition;
    stack<ConditionCommand*> conditions;
    bool addToCondition;
    int countCondition;
public:
    Parser();
    void parse(vector<string>* line);
    void add(Command command);
};


#endif //MILESTONE_PARSER_H
