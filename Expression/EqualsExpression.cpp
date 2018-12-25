//
// Created by shira on 12/24/18.
//

#include "EqualsExpression.h"

double EqualsExpression::calculate() {
    double result = this->getLeft()->calculate() == this->getRight()->calculate() ? TRUE : FALSE;
    return result;
}

EqualsExpression::EqualsExpression(Expression* left, Expression* right) : BinaryExpression(left, right) {}