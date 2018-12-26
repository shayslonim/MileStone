//
// Created by shay on 12/17/18.
//

#ifndef MILESTONE_BINARYEXPRESSION_H
#define MILESTONE_BINARYEXPRESSION_H

#include "Expression.h"

class BinaryExpression : public Expression {
private:
    Expression* left;
    Expression* right;
public:
    BinaryExpression(Expression* left, Expression* right);

protected:
    Expression* getLeft();
    Expression* getRight();

public:
    virtual double calculate() override = 0;
};


#endif //MILESTONE_BINARYEXPRESSION_H
