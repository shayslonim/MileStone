//
// Created by shay on 12/17/18.
//

#include "DivideExpression.h"

double Divide::calculate() {
    return this->getLeft()->calculate() / this->getRight()->calculate();
}

Divide::Divide(Expression* left, Expression* right) : BinaryExpression(left, right) {}


