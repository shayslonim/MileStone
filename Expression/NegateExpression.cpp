//
// Created by shira on 1/5/19.
//

#include "NegateExpression.h"

double NegateExpression::calculate() {
    return this->value->calculate() * -1;
}

NegateExpression::NegateExpression(Expression* value) {
    this->value = value;
}