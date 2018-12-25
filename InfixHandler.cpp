#include <utility>

//
// Created by shay on 12/19/18.
//

#include <vector>
#include "InfixHandler.h"
#include <queue>
#include <stack>
#include <unordered_set>

#define LENGTH_OF_CHAR 1
using namespace std;


/**
 * The function takes an infix numeric expression and converts it to a postfix one.
 * @param infix the infix expression that would be converted
 * @return the postfix version of the same expression
 */
vector<string> InfixHandler::convertToPostfix(vector<string> infix) {
    vector<string> resultArray;
    queue<string> outputQueue;
    stack<string> operatorsStack;

    for (string &s :infix) {
        if (isNumber(s)) {
            outputQueue.push(s);
        } else if (isOperator(s)) {

            //Since the string s is an operator, it is expected to have length 1, so it can be converted into a char.
            string curOperator = s;

            /* While there is an operator with greater precedence in the stack, pop it to the queue */
            if (!operatorsStack.empty()) {
                string top = operatorsStack.top();
                while (!operatorsStack.empty() && isHigherPriority(top, curOperator)) {
                    operatorsStack.pop(); //pop the operator from the stack
                    outputQueue.push(top); //add the operator to the queue
                }
            }
            //push the current operator onto the stack
            operatorsStack.push(curOperator);

        } else if (s == "(") {
            //if it's a left bracket, push it to the stack.
            operatorsStack.push("(");
        } else if (s == ")") {
            /* While there's not a left bracket at the top of the stack
              Pop operators from the stack onto the output queue.*/
            while (!operatorsStack.empty() && (operatorsStack.top() != "(")) {
                string top = operatorsStack.top();
                outputQueue.push(top);
                operatorsStack.pop();

            }
            //pop the left bracket from the stack and discard it
            operatorsStack.pop();
        } else {
            throw exception();
        }
    }

    //while there are operators on the stack, pop them to the queue
    while (!operatorsStack.empty()) {
        string top = operatorsStack.top();
        if (top != "(" && top != ")") {
            outputQueue.push(top);
            operatorsStack.pop();
        }
    }

    //move the queue to the array
    while (!outputQueue.empty()) {
        resultArray.push_back(outputQueue.front());
        outputQueue.pop();
    }
    return resultArray;
}


bool InfixHandler::isOperator(string s) {
    if (s.length() > 2) {
        return false;
    }
    //convert the string to char
    //char symbol = s[0];

    unordered_set<string> operators = {"+", "-", "/", "*", "=", ":", "==", "<", ">", "<=", ">="};
    return operators.find(s) != operators.end();
}

bool InfixHandler::isNumber(string s) {
    bool usedPeriod = false; //a boolean that checks if we used a decimal period.

    //if the first char is not minus sign or a digit return false.
    if (!(s[0] == '-' || isdigit(s[0]))) {
        return false;
    }
    //check that the rest of the string is digits
    for (int i = 0; i < s.length(); i++) {
        if (!isdigit(s[i])) {
            //if it's not a digit, maybe it's a period which is allowed once. else, return false.
            if (s[i] == '.' && !usedPeriod) {
                usedPeriod = true;
            } else {
                return false;
            }
        }
    }
    return true;
}

bool InfixHandler::isDigit(char c) {
    return ('0' <= c && c <= '9');
}

bool InfixHandler::isHigherPriority(string operator1, string operator2) {
    if ((operator1 == "*" || operator1 == "/") && (operator2 == "+" || operator2 == "-")) {
        return true;
    }
    if ((operator1 == ">" || operator1 == "<" || operator1 == "==" || operator1 == "<=" || operator1 == ">=")) {
        if (operator2 == "*" || operator2 == "/" || operator2 == "+" || operator2 == "-") {
            return true;
        }
    }
    return false;
}

string InfixHandler::charToString(char c) {
    int lengthOfChar = 1;
    return string(lengthOfChar, c);
}






