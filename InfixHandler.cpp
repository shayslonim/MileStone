//
// Created by shay on 12/19/18.
//

#include <vector>
#include "InfixHandler.h"
#include <queue>
#include <stack>
#include <unordered_set>

using namespace std;

/**
 * The function takes an infix numeric expression and converts it to a postfix one.
 * @param infix the infix expression that would be converted
 * @return the postfix version of the same expression
 */
//string InfixHandler::convertToPostfix(string infix) {
//    int i = 0;
//    while (i < infix.length()) {
//        char c = infix[i];
//        if (isdigit(c)) {
//            int numValue = 0;
//            while (isdigit(c)) {
//
//            }
//        }
//        i++;
//    }
//}

vector<string> InfixHandler::convertToPostfix(vector<string> infix) {
    vector<string> resultArray;
    queue<string> operatorsQueue;
    stack<char> operatorsStack;

    for (string &s :infix) {
        if (isNumber(s)) {
            operatorsQueue.push(s);
        } else if (isOperator(s)) {

            //Since the string s is an operator, it is excpected to have length 1, so it can be converted into a char.
            char curOperator = s[0];

            /* While there is an operator with greater precedence in the stack, pop it to the queue */

            char top = operatorsStack.top();
            while (!operatorsStack.empty() && isHigherPriority(top, curOperator)) {
                operatorsStack.pop(); //pop the operator from the stack
                operatorsQueue.push(to_string(top)); //add the operator to the queue
            }
            //push the current operator onto the stack
            operatorsStack.push(curOperator);

        } else if (s == "(") {
            //if it's a left bracket, push it to the stack.
            operatorsStack.push('(');
        } else if (s == ")") {
            /* While there's not a left bracket at the top of the stack
              Pop operators from the stack onto the output queue.*/
            while (!operatorsStack.empty() && (operatorsStack.top() != '(')) {
                string top = to_string(operatorsStack.top());
                operatorsQueue.push(top);

            }
            //pop the left bracket from the stack and discard it
            operatorsStack.pop();
        }
    }
    /* While there are operators on the stack, pop them to the queue
      (unless they are brackets then ignore them) */
    while (!operatorsStack.empty()) {
        char top = operatorsStack.top();
        if (top != ')' && top != '(') {
            operatorsQueue.push(to_string(top));
        }
    }

    //convert the result to a vector of strings
    while (!operatorsQueue.empty()) {
        resultArray.push_back(operatorsQueue.top());
        operatorsQueue.pop();
    }
    return resultArray;
}

bool isDigit(char c) {
    return ('0' <= c && c <= '9');
}


bool isNumber(string s) {
    bool usedPeriod = false; //a boolean that checks if we used a decimal period.

    //if the first char is not minus sign or a digit return false.
    if (!(s[0] == '-' || isdigit(s[0]))) {
        return false;
    }
    //check that the rest of the string is digits
    for (int i = 0; i < s.length(); i++) {
        if (!isdigit(s[i])) {
            return false;
        }
    }
}

bool InfixHandler::isOperator(string &c) {
    unordered_set<char> operators = {'+', '-', '/', '*', '(', ')', '=', ':'};
    return operators.find(c) != operators.end();
}

bool isHigherPriority(char operator1, char operator2) {
    //+ - * /
    return operator1 == '*' || operator1 == '/' && operator2 == '+' || operator2 == '-';
}
