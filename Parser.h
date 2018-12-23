//
// Created by shay on 12/17/18.
//

#ifndef MILESTONE_PARSER_H
#define MILESTONE_PARSER_H

#include <string>
#include <vector>
#include "Parser.h"
#include "Maps.h"
using namespace std;

class Parser {
    Maps maps;
    vector<Command> commands;
public:
    Parser();
    void parse(vector<string>* commands);
};


#endif //MILESTONE_PARSER_H
