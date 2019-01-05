//
// Created by shira on 12/26/18.
//

#include "ExitCommand.h"
#include "../SocketBooleans.h"

/**
 * Exit and stop
 */
void ExitCommand::execute() {
    this->shouldExit = true;
    SocketBooleans::setStopServerReader(true);
    this->maps->closeServerUpdate();
}

/**
 * Should the program stop
 * @return bool shouldExit
 */
bool ExitCommand::getShouldExit() {
    return this->shouldExit;
}

/**
 * Constructor
 * @param maps Maps*
 */
ExitCommand::ExitCommand(Maps* maps) {
    this->maps = maps;
    this->shouldExit = false;
}
