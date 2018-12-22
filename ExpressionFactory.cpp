//
// Created by shay on 12/22/18.
//

#include "ExpressionFactory.h"
#include <stack>
#include "Expression/Plus.h"
#include "Expression/NumExpression.h"

Expression ExpressionFactory::getExpression(vector<string> postfix) {
    stack<string> operatorsStack;
    for (string &s: postfix) {
        if (s == "+" || s == "-" || s == "*" || s == "/") {
            char oper = s[0];
            Expression* num2 = new NumExpression(stod(operatorsStack.top()));
            operatorsStack.pop();
            Expression* num1 = new NumExpression(stod(operatorsStack.top()));
            operatorsStack.pop();

            Expression* exp;
            switch (oper) {
                case '+':
                    exp = new Plus(num1,num2);
                default:
                    break;

            }
        }
    }
}
