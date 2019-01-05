//
// Created by shay on 12/17/18.
//

#include "BinaryExpression.h"

/**
 * Getter
 * @return Expression* left
 */
Expression* BinaryExpression::getLeft(){
    return this->left;
}

/**
 * Getter
 * @return Expression* right
 */
Expression* BinaryExpression::getRight() {
    return this->right;
}

/**
 * Constructor
 * @param left Expression*
 * @param right Expression*
 */
BinaryExpression::BinaryExpression(Expression* left, Expression* right) : left(left), right(right) {}


