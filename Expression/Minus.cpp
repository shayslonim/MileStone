//
// Created by shay on 12/18/18.
//

#include "Minus.h"
double Minus::calculate() {
    return this->getLeft()->calculate() - this->getRight()->calculate();
}

Minus::Minus(Expression* left, Expression* right) : BinaryExpression(left, right) {}
