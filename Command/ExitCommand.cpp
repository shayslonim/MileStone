//
// Created by shira on 12/26/18.
//

#include "ExitCommand.h"
#include "../SocketBooleans.h"

void ExitCommand::execute() {
    this->shouldExit = true;
    SocketBooleans::setStopServerReader(true);
    this->maps->closeServerUpdater();
}

bool ExitCommand::getShouldExit() {
    return this->shouldExit;
}

ExitCommand::ExitCommand(Maps* maps) {
    this->maps = maps;
    this->shouldExit = false;
}
