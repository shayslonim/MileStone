//
// Created by shay on 12/18/18.
//

#include "PlusExpression.h"

double PlusExpression::calculate() {
    return this->getLeft()->calculate() + this->getRight()->calculate();
}

PlusExpression::PlusExpression(Expression* left, Expression* right) : BinaryExpression(left, right) {}
