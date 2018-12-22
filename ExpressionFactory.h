//
// Created by shay on 12/22/18.
//

#ifndef MILESTONE_EXPRESSIONFACTORY_H
#define MILESTONE_EXPRESSIONFACTORY_H

#include <string>
#include <vector>

using namespace std;

#include "Expression/Expression.h"
/**
 * The expression factory creates an expression from a vector of string.
 */
class ExpressionFactory {
    /**
     * The getExpression function gets a postfix expression and creates the appropriate Expression* from it.
     * @param postfix the vector<string> of operators and numbers, in postfix notation
     * @return an Expression*
     */
Expression getExpression(vector<string> postfix);
};


#endif //MILESTONE_EXPRESSIONFACTORY_H
