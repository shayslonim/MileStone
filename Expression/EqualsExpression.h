//
// Created by shira on 12/24/18.
//

#ifndef MILESTONE_EQUALSEXPRESSION_H
#define MILESTONE_EQUALSEXPRESSION_H

#include "BinaryExpression.h"

class EqualsExpression : public BinaryExpression {
public:
    EqualsExpression(Expression* left, Expression* right);

    double calculate() override;
};

#endif //MILESTONE_EQUALSEXPRESSION_H
