//
// Created by shay on 12/17/18.
//

#include "BinaryExpression.h"


Expression* BinaryExpression::getLeft(){
    return this->left;
}

Expression* BinaryExpression::getRight() {
    return this->right;
}

BinaryExpression::BinaryExpression(Expression* left, Expression* right) : left(left), right(right) {}


