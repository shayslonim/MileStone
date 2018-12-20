//
// Created by shay on 12/16/18.
//
#include <string>
#include <vector>
#include <list>
#include <set>
#include <unordered_set>
#include <iostream>
using namespace std;

#ifndef MILESTONE_LEXER_H
#define MILESTONE_LEXER_H
using namespace std;

class Lexer {
public:
    vector<string>* lexer(string line);

public: //private
    static string separateSpaces(string line);
};


#endif //MILESTONE_LEXER_H
