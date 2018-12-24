//
// Created by shay on 12/17/18.
//

#ifndef MILESTONE_DIVIDE_H
#define MILESTONE_DIVIDE_H


#include "Expression.h"
#include "BinaryExpression.h"

class DivideExpression : public BinaryExpression {
public:
    DivideExpression(Expression* left, Expression* right);

    double calculate() override;

};


#endif //MILESTONE_DIVIDE_H
