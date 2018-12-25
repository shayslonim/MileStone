//
// Created by shira on 12/24/18.
//

#ifndef MILESTONE_BIGGEREQUALSEXPRESSION_H
#define MILESTONE_BIGGEREQUALSEXPRESSION_H

#include "BinaryExpression.h"

class BiggerEqualsExpression : public BinaryExpression {
public:
    BiggerEqualsExpression(Expression* left, Expression* right);

    double calculate() override;
};

#endif //MILESTONE_BIGGEREQUALSEXPRESSION_H
