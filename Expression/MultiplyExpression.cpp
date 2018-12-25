//
// Created by shay on 12/17/18.
//

#include "MultiplyExpression.h"

double MultiplyExpression::calculate() {
    return this->getLeft()->calculate() * this->getRight()->calculate();
}

MultiplyExpression::MultiplyExpression(Expression* left, Expression* right) : BinaryExpression(left, right) {

}

