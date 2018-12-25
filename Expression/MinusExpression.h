//
// Created by shay on 12/18/18.
//

#ifndef MILESTONE_MINUS_H
#define MILESTONE_MINUS_H


#include "BinaryExpression.h"
#include "Expression.h"

class MinusExpression : public BinaryExpression {

public:
    MinusExpression(Expression* left, Expression* right);

    double calculate() override;
};


#endif //MILESTONE_MINUS_H
