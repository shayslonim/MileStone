//
// Created by shira on 12/24/18.
//

#include "BiggerEqualsExpression.h"

double BiggerEqualsExpression::calculate() {
    double result = this->getLeft()->calculate() >= this->getRight()->calculate() ? TRUE : FALSE;
    return result;
}

BiggerEqualsExpression::BiggerEqualsExpression(Expression* left, Expression* right) : BinaryExpression(left, right) {}