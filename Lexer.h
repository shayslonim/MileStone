//
// Created by shay on 12/16/18.
//
#include <string>
#include <vector>

#ifndef MILESTONE_LEXER_H
#define MILESTONE_LEXER_H
using namespace std;

class Lexer {
public:
    vector<string>* lexer(string line);

private:
    static string separateSpaces(string line);


};


#endif //MILESTONE_LEXER_H
