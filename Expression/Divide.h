//
// Created by shay on 12/17/18.
//

#ifndef MILESTONE_DIVIDE_H
#define MILESTONE_DIVIDE_H


#include "Expression.h"
#include "BinaryExpression.h"

class Divide : public BinaryExpression {
public:
    Divide(Expression* left, Expression* right);

    double calculate() override;

};


#endif //MILESTONE_DIVIDE_H
