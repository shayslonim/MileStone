//
// Created by shay on 12/19/18.
//

#ifndef MILESTONE_INFIXHANDLER_H
#define MILESTONE_INFIXHANDLER_H

#include <vector>
#include <string>

using namespace std;

class InfixHandler {
public:
    InfixHandler();
    vector<string> convertToPostfix(vector<string> infix);
    bool isANumber(string s);
private:
    static bool isNumber(string s);

    static bool isDigit(char c);

    static bool isOperator(string s);

    static bool isHigherPriority(string operator1, string operator2);

    static string charToString(char c);
};


#endif //MILESTONE_INFIXHANDLER_H
