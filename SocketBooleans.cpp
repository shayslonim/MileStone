//
// Created by shay on 12/27/18.
//

#include "SocketBooleans.h"

bool SocketBooleans::isStopServerReader() {
    return stopServerReader;
}

void SocketBooleans::setStopServerReader(bool isStop) {
    SocketBooleans::stopServerReader = isStop;
}
