//
// Created by shay on 12/17/18.
//

#include "NumExpression.h"

/**
 * Evaluate
 * @return double
 */
double NumExpression::calculate() {
    return this->value;
}

/**
 * Constructor
 * @param value double
 */
NumExpression::NumExpression(double value) {
    this->value = value;
}
