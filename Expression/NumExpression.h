//
// Created by shay on 12/17/18.
//

#ifndef MILESTONE_NUMEXPRESSION_H
#define MILESTONE_NUMEXPRESSION_H


#include "Expression.h"

class NumExpression : public Expression {
private:
    double value;
public:
    NumExpression(double value);
    double calculate() override;
};


#endif //MILESTONE_NUMEXPRESSION_H
