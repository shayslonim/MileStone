//
// Created by shira on 12/20/18.
//

#include "Bind.h"

// The vector is expected to include strings without spaces, ex: var breaks = bind "/controls/flight/speedbrake"
void Bind::execute(vector<string>::iterator iter) {
    if (iter[0] == "var") {
        Maps::insertBind(iter[FIRST + 1], iter[SECOND + 1]);
    } else {
        Maps::insertBind(iter[FIRST], iter[SECOND]);
    }
}
