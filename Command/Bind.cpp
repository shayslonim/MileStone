//
// Created by shira on 12/20/18.
//

#include "Bind.h"
#include "../Maps.h"

// The vector is expected to include two strings only.
void Bind::execute(vector<string>::iterator iter) {
    Maps::insertBind(iter[0], iter[1]);
}
