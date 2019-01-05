//
// Created by shira on 12/24/18.
//

#include "SmallerExpression.h"

/**
 * Evaluate <
 * @return double 0 or 1
 */
double SmallerExpression::calculate() {
    double result = this->getLeft()->calculate() < this->getRight()->calculate() ? TRUE : FALSE;
    return result;
}

/**
 * Constructor
 * @param left Expression*
 * @param right Expression*
 */
SmallerExpression::SmallerExpression(Expression* left, Expression* right) : BinaryExpression(left, right) {}