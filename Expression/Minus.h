//
// Created by shay on 12/18/18.
//

#ifndef MILESTONE_MINUS_H
#define MILESTONE_MINUS_H


#include "BinaryExpression.h"
#include "Expression.h"

class Minus : public BinaryExpression {

public:
    Minus(Expression* left, Expression* right);

    double calculate() override;
};


#endif //MILESTONE_MINUS_H
