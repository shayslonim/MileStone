//
// Created by shira on 12/24/18.
//

#ifndef MILESTONE_SMALLEREQUALSEXPRESSION_H
#define MILESTONE_SMALLEREQUALSEXPRESSION_H

#include "BinaryExpression.h"

class SmallerEqualsExpression : public BinaryExpression {
public:
    SmallerEqualsExpression(Expression* left, Expression* right);

    double calculate() override;
};

#endif //MILESTONE_SMALLEREQUALSEXPRESSION_H
