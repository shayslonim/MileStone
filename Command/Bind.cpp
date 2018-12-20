//
// Created by shira on 12/20/18.
//

#include "Bind.h"
#include "../Maps.h"

// The vector is expected to include strings without spaces, ex: var breaks = bind "/controls/flight/speedbrake"
void Bind::execute(vector<string>::iterator iter) {
    //vector<string> buffer = cut(iter);
    Maps::insertBind(iter[FIRST], iter[SECOND]);
}
//vector<string> Bind::cut(vector<string>::iterator iter) {
//
//}
