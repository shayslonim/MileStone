//
// Created by shira on 1/5/19.
//

#ifndef MILESTONE_NEGATEEXPRESSION_H
#define MILESTONE_NEGATEEXPRESSION_H
#include "Expression.h"

class NegateExpression : public Expression {
private:
    Expression* value;
public:
    NegateExpression(Expression* value);
    double calculate() override;
};
#endif //MILESTONE_NEGATEEXPRESSION_H
