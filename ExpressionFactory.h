//
// Created by shay on 12/22/18.
//

#ifndef MILESTONE_EXPRESSIONFACTORY_H
#define MILESTONE_EXPRESSIONFACTORY_H

#include <string>
#include <vector>

using namespace std;
#include <iostream>
#include <stack>
#include "Expression/Expression.h"
#include "Maps.h"
#include "InfixHandler.h"
#include "Expression/PlusExpression.h"
#include "Expression/NumExpression.h"
#include "Expression/MinusExpression.h"
#include "Expression/MultiplyExpression.h"
#include "Expression/DivideExpression.h"
#include "Expression/BiggerExpression.h"
#include "Expression/SmallerExpression.h"
#include "Expression/EqualsExpression.h"
#include "Expression/BiggerEqualsExpression.h"
#include "Expression/SmallerEqualsExpression.h"
#include "Expression/VarExpression.h"

/**
 * The expression factory creates an expression from a vector of string.
 */
class ExpressionFactory {
    Maps* maps;
public:
    ExpressionFactory(Maps* maps);
    /**
     * The getExpression function gets a postfix expression and creates the appropriate Expression* from it.
     * @param postfix the vector<string> of operators and numbers, in postfix notation
     * @return an Expression*
     */
    Expression* getExpression(vector<string> postfix);
    Expression* getExpressionFromUnorderedLine(vector<string> line, int start, int end);
};


#endif //MILESTONE_EXPRESSIONFACTORY_H
