//
// Created by shay on 12/18/18.
//

#include "MinusExpression.h"

/**
 * Evaluate
 * @return double 0 or 1
 */
double MinusExpression::calculate() {
    return this->getLeft()->calculate() - this->getRight()->calculate();
}

/**
 * Constructor
 * @param left Expression*
 * @param right Expression*
 */
MinusExpression::MinusExpression(Expression* left, Expression* right) : BinaryExpression(left, right) {}
