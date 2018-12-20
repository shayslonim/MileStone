//
// Created by shay on 12/19/18.
//

#ifndef MILESTONE_INFIXHANDLER_H
#define MILESTONE_INFIXHANDLER_H

#include <string>
using namespace std;

class InfixHandler {
public:
    string convertToPostfix(string infix);

private:
    static bool isNumber(string s);

    static bool isDigit(char c);

    bool isOperator(string &basic_string);
};


#endif //MILESTONE_INFIXHANDLER_H
