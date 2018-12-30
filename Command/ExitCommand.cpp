//
// Created by shira on 12/26/18.
//

#include "ExitCommand.h"
#include "../SocketBooleans.h"

void ExitCommand::execute() {
    this->shouldExit = true;
    SocketBooleans::setStopServerReader(true);
}

bool ExitCommand::getShouldExit() {
    return this->shouldExit;
}

ExitCommand::ExitCommand() {
    this->shouldExit = false;
}
