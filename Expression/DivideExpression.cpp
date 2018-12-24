//
// Created by shay on 12/17/18.
//

#include "DivideExpression.h"

double DivideExpression::calculate() {
    return this->getLeft()->calculate() / this->getRight()->calculate();
}

DivideExpression::DivideExpression(Expression* left, Expression* right) : BinaryExpression(left, right) {}


