//
// Created by shira on 1/5/19.
//

#include "NegateExpression.h"

/**
 * Evaluate * -1
 * @return double
 */
double NegateExpression::calculate() {
    return this->value->calculate() * -1;
}

/**
 * Constructor
 * @param value Expression*
 */
NegateExpression::NegateExpression(Expression* value) {
    this->value = value;
}