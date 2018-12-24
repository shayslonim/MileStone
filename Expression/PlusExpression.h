//
// Created by shay on 12/18/18.
//

#ifndef MILESTONE_PLUS_H
#define MILESTONE_PLUS_H


#include "BinaryExpression.h"

class PlusExpression : public BinaryExpression {
public:
    PlusExpression(Expression* left, Expression* right);

    double calculate() override;
};


#endif //MILESTONE_PLUS_H
