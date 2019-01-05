//
// Created by shay on 12/22/18.
//

#include "ExpressionFactory.h"

#define LEN_STR 1

ExpressionFactory::ExpressionFactory(Maps* maps) {
    this->maps = maps;
}

Expression* ExpressionFactory::getExpression(vector<string> postfix) {
    stack<Expression*> expressionStack;
    for (string &s: postfix) {
        //If the current string is an operator
        if (s == "+" || s == "-" || s == "*" || s == "/" || s == ">" || s == "<" || s == "<=" || s == ">=" || s == "==") {
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
                    exp = new PlusExpression(num1, num2);
                    break;
                case '-':
                    exp = new MinusExpression(num1, num2);
                    break;
                case '*':
                    exp = new MultiplyExpression(num1, num2);
                    break;
                case '/':
                    exp = new DivideExpression(num1, num2);
                    break;
                case '>':
                    if (s.length() > LEN_STR) { // ">="
                        exp = new BiggerEqualsExpression(num1, num2);
                    } else {
                        exp = new BiggerExpression(num1, num2);
                    }
                    break;
                case '<':
                    if (s.length() > LEN_STR) { // "<="
                        exp = new SmallerEqualsExpression(num1, num2);
                    } else {
                        exp = new SmallerExpression(num1, num2);
                    }
                    break;
                case '=': //"=="
                    exp = new EqualsExpression(num1, num2);
                    break;
                default:
                    throw "Operator is unknown";
            }
            //Push the created expression to the stack;
            expressionStack.push(exp);
        } else { //The current string is a number
            //convert the string to double and push it the stack
            try {
                expressionStack.push(new NumExpression(stod(s)));
            }
            catch (exception ex) {
                if (s[0] == '-') {
                    string positive = string();
                    for (int i = 1; i < s.length(); i++) {
                        positive += s[i];
                    }
                    expressionStack.push(new NegateExpression(new VarExpression(positive, maps)));
                }
                else {
                    expressionStack.push(new VarExpression(s, maps));
                }
            }
        }
    }
    //There should be one item in the stack which is the return value.
    if (expressionStack.size() != 1) {
        std::cerr << "Something went wrong with the algorithm. Is it possible that the expression isn't correct?";
    }
    return expressionStack.top();
}

Expression* ExpressionFactory::getExpressionFromUnorderedLine(vector<string> line, int start, int end) {
    InfixHandler infixHnadler = InfixHandler();
    vector<string> expressionVector;
    for (int i = start; i <= end; i++) {
            expressionVector.push_back(line[i]);
    }
    return getExpression(infixHnadler.convertToPostfix(expressionVector));
}
