//
// Created by shira on 12/24/18.
//

#include "SmallerEqualsExpression.h"

double SmallerEqualsExpression::calculate() {
    double result = this->getLeft()->calculate() <= this->getRight()->calculate() ? TRUE : FALSE;
    return result;
}

SmallerEqualsExpression::SmallerEqualsExpression(Expression* left, Expression* right) : BinaryExpression(left, right) {}