//
// Created by shay on 12/22/18.
//

#include "ExpressionFactory.h"
#include <stack>
#include "Expression/Plus.h"
#include "Expression/NumExpression.h"
#include "Expression/Minus.h"
#include "Expression/Multiply.h"
#include "Expression/Divide.h"

Expression* ExpressionFactory::getExpression(vector<string> postfix) {
    stack<Expression*> ExpressionStack;
    for (string &s: postfix) {
        //If the current string is an operator
        if (s == "+" || s == "-" || s == "*" || s == "/") {
            char oper = s[0];
            //take two numbers out of the stack
            Expression* num2 = ExpressionStack.top();
            ExpressionStack.pop();
            Expression* num1 = ExpressionStack.top();
            ExpressionStack.pop();

            //create the expression with the two numbers
            Expression* exp;
            switch (oper) {
                case '+':
                    exp = new Plus(num1, num2);
                    break;
                case '-':
                    exp = new Minus(num1, num2);
                    break;
                case '*':
                    exp = new Multiply(num1, num2);
                    break;
                case '/':
                    exp = new Divide(num1, num2);
                    break;
                default:
                    throw "Operator is unknown";
            }
            //Push the created expression to the stack;
            ExpressionStack.push(exp);
        } else { //The current string is a number
            //convert the string to double and push it the stack
            ExpressionStack.push(new NumExpression(stod(s)));
        }
    }
    return ExpressionStack.top();
}
