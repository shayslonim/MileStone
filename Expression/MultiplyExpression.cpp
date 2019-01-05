//
// Created by shay on 12/17/18.
//

#include "MultiplyExpression.h"

/**
 * Evaluate *
 * @return double
 */
double MultiplyExpression::calculate() {
    return this->getLeft()->calculate() * this->getRight()->calculate();
}

/**
 * Constructor
 * @param left Expression*
 * @param right Expression*
 */
MultiplyExpression::MultiplyExpression(Expression* left, Expression* right) : BinaryExpression(left, right) {

}

