//
// Created by shira on 12/20/18.
//

#include "VarExpression.h"

/**
 * Evaluate by Maps
 * @return double
 */
double VarExpression::calculate() {
    return this->maps->getValbyVar(this->value);
}

/**
 * Constructor
 * @param left Expression*
 * @param right Expression*
 */
VarExpression::VarExpression(string value, Maps* maps) {
    this->value = value;
    this->maps = maps;
}
