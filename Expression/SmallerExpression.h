//
// Created by shira on 12/24/18.
//

#ifndef MILESTONE_SMALLEREXPRESSION_H
#define MILESTONE_SMALLEREXPRESSION_H

#include "BinaryExpression.h"

class SmallerExpression : public BinaryExpression {
public:
    SmallerExpression(Expression* left, Expression* right);

    double calculate() override;
};

#endif //MILESTONE_SMALLEREXPRESSION_H
