//
// Created by shira on 12/24/18.
//

#ifndef MILESTONE_BIGGEREXPRESSION_H
#define MILESTONE_BIGGEREXPRESSION_H

#include "BinaryExpression.h"

class BiggerExpression : public BinaryExpression {
public:
    BiggerExpression(Expression* left, Expression* right);

    double calculate() override;
};

#endif //MILESTONE_BIGGEREXPRESSION_H
