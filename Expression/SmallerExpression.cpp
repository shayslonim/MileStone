//
// Created by shira on 12/24/18.
//

#include "SmallerExpression.h"

double SmallerExpression::calculate() {
    double result = this->getLeft()->calculate() < this->getRight()->calculate() ? TRUE : FALSE;
    return result;
}

SmallerExpression::SmallerExpression(Expression* left, Expression* right) : BinaryExpression(left, right) {}