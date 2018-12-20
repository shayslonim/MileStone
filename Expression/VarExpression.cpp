//
// Created by shira on 12/20/18.
//

#include "VarExpression.h"

double VarExpression::calculate() {
    return Maps::getVal(this->value);
}

VarExpression::VarExpression(string value) {
    this->value = value;
}
