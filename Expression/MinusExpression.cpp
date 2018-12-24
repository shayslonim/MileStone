//
// Created by shay on 12/18/18.
//

#include "MinusExpression.h"
double MinusExpression::calculate() {
    return this->getLeft()->calculate() - this->getRight()->calculate();
}

MinusExpression::MinusExpression(Expression* left, Expression* right) : BinaryExpression(left, right) {}
