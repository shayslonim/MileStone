//
// Created by shira on 12/20/18.
//

#ifndef MILESTONE_VAREXPRESSION_H
#define MILESTONE_VAREXPRESSION_H
#include <string>
#include "Expression.h"
#include "../Maps.h"
using namespace std;

class VarExpression : public Expression {
private:
    string value;
    Maps* maps;
public:
    VarExpression(string value, Maps* maps);
    double calculate() override;
};

#endif //MILESTONE_VAREXPRESSION_H
