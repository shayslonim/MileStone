//
// Created by shira on 12/20/18.
//

#include "VarCommand.h"

//var breaks = bind "/controls/flight/speedbrake"
//var h0 = heading
void Var::execute(vector<string>::iterator iter) {
    this->maps->insertVal(iter[INDEX], 0);
}