//
// Created by shira on 12/24/18.
//

#include "BiggerExpression.h"

double BiggerExpression::calculate() {
    double result = this->getLeft()->calculate() > this->getRight()->calculate() ? TRUE : FALSE;
    return result;
}

BiggerExpression::BiggerExpression(Expression* left, Expression* right) : BinaryExpression(left, right) {}