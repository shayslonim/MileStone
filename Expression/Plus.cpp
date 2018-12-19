//
// Created by shay on 12/18/18.
//

#include "Plus.h"

double Plus::calculate() {
    return this->getLeft()->calculate() + this->getRight()->calculate();
}

Plus::Plus(Expression* left, Expression* right) : BinaryExpression(left, right) {}
