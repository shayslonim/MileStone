//
// Created by shay on 12/17/18.
//

#include "DivideExpression.h"

/**
 * Evaluate /
 * @return double
 */
double DivideExpression::calculate() {
    return this->getLeft()->calculate() / this->getRight()->calculate();
}

/**
 * Constructor
 * @param left Expression*
 * @param right Expression*
 */
DivideExpression::DivideExpression(Expression* left, Expression* right) : BinaryExpression(left, right) {}


