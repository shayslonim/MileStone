//
// Created by shay on 12/17/18.
//

#include "NumExpression.h"

double NumExpression::calculate() {
    return this->value;
}

NumExpression::NumExpression(double value) {
    this->value = value;
}
