//
// Created by shay on 12/18/18.
//

#include "PlusExpression.h"

/**
 * Evaluate
 * @return double
 */
double PlusExpression::calculate() {
    return this->getLeft()->calculate() + this->getRight()->calculate();
}

/**
 * Constructor
 * @param left Expression*
 * @param right Expression*
 */
PlusExpression::PlusExpression(Expression* left, Expression* right) : BinaryExpression(left, right) {}
