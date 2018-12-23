//
// Created by shira on 12/20/18.
//

#include "VarExpression.h"

double VarExpression::calculate() {
    return this->maps->getVal(this->value);
}

VarExpression::VarExpression(string value, Maps* maps) {
    this->value = value;
    this->maps = maps;
}
