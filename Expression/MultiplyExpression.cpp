//
// Created by shay on 12/17/18.
//

#include "MultiplyExpression.h"

double Multiply::calculate() {
    return this->getLeft()->calculate() * this->getRight()->calculate();
}

Multiply::Multiply(Expression* left, Expression* right) : BinaryExpression(left, right) {

}

