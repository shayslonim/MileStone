//
// Created by shay on 12/17/18.
//

#ifndef MILESTONE_EXPRESSION_H
#define MILESTONE_EXPRESSION_H
#define TRUE 1
#define FALSE 0

/**
 * The Expression interface represents an expression - whether its a numeric expression like numbers and arithmetic
 * operations, or a Command Expression.
 */
class Expression {
public:
    /**
     * Evaluate
     * @return double
     */
    virtual double calculate() = 0;
};


#endif //MILESTONE_EXPRESSION_H
