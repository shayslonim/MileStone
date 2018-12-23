//
// Created by shay on 12/22/18.
//

#include "ExpressionFactory.h"
#include <stack>
#include "Expression/PlusExpression.h"
#include "Expression/NumExpression.h"
#include "Expression/MinusExpression.h"
#include "Expression/MultiplyExpression.h"
#include "Expression/DivideExpression.h"

Expression* ExpressionFactory::getExpression(vector<string> postfix) {
    stack<Expression*> expressionStack;
    for (string &s: postfix) {
        //If the current string is an operator
        if (s == "+" || s == "-" || s == "*" || s == "/") {
            char oper = s[0];
            //take two numbers out of the stack
            Expression* num2 = expressionStack.top();
            expressionStack.pop();
            Expression* num1 = expressionStack.top();
            expressionStack.pop();

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
            expressionStack.push(exp);
        } else { //The current string is a number
            //convert the string to double and push it the stack
            expressionStack.push(new NumExpression(stod(s)));
        }
    }
    //There should be one item in the stack which is the return value.
    if (expressionStack.size() != 1) {
        throw "Something went wrong with the algorithm. Is it possible that the expression isn't correct?";
    }
    return expressionStack.top();
}
