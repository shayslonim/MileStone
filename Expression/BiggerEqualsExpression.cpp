//
// Created by shira on 12/24/18.
//

#include "BiggerEqualsExpression.h"

/**
 * Evaluate >=
 * @return double 0 or 1
 */
double BiggerEqualsExpression::calculate() {
    double result = this->getLeft()->calculate() >= this->getRight()->calculate() ? TRUE : FALSE;
    return result;
}

/**
 * Constructor
 * @param left Expression*
 * @param right Expression*
 */
BiggerEqualsExpression::BiggerEqualsExpression(Expression* left, Expression* right) : BinaryExpression(left, right) {}