//
// Created by shay on 12/27/18.
//

#include "SocketBooleans.h"

bool SocketBooleans::stopServerReader = false; //initialize the stopServerReader boolean with default value of false
bool SocketBooleans::readingStarted = false; //initialize the readingStarted boolean with default value of false

bool SocketBooleans::isStopServerReader() {
    return stopServerReader;
}

void SocketBooleans::setStopServerReader(bool isStop) {
    SocketBooleans::stopServerReader = isStop;
}

bool SocketBooleans::isReadingStarted() {
    return readingStarted;
}

void SocketBooleans::setReadingStarted(bool isStarted) {
    SocketBooleans::readingStarted = isStarted;
}


