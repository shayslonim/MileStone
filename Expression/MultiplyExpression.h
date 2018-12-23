//
// Created by shay on 12/17/18.
//

#ifndef MILESTONE_MULTIPLY_H
#define MILESTONE_MULTIPLY_H


#include "Expression.h"
#include "BinaryExpression.h"

class Multiply : public BinaryExpression {

public:
    Multiply(Expression* left, Expression* right);

    double calculate() override;

};


#endif //MILESTONE_MULTIPLY_H
