//
// Created by shira on 12/20/18.
//

#include "EqualsCommand.h"

//var breaks = bind "/controls/flight/speedbrake"
//breaks = 0
//var h0 = heading
//aileron = - roll / 70
void Equals::execute(vector<string>::iterator iter) {
    int first = FIRST;
    int second = SECOND;
    if (iter[0] == "var") {
        first++;
        second++;
    }
    if (iter[second] == "bind") {
        second++;
    }
    Expression* exp; // Use ShuntingYard algorithm of Expression on iter[second] until line end @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    this->maps->insertVal(iter[first], exp->calculate());
}