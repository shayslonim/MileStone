//
// Created by shay on 12/17/18.
//

#ifndef MILESTONE_EXPRESSION_H
#define MILESTONE_EXPRESSION_H

/**
 * The Expression interface represents an expression - whether its a numeric expression like numbers and arithmetic
 * operations, or a Command Expression.
 */
class Expression {
public:
    virtual double calculate() = 0;
};


#endif //MILESTONE_EXPRESSION_H
