//
// Created by shira on 12/20/18.
//

#include <pthread.h>
#include "OpenDataServerCommand.h"
#include "ServerReader.h"
#include "../ServerReaderArguments.h"

OpenDataServerCommand::OpenDataServerCommand() {

}

void OpenDataServerCommand::execute() {
    pthread_t serverThread;

    ServerReaderArguments* args = new ServerReaderArguments(this->portId, this->timesPerSecond, this->maps);

    pthread_create(&serverThread, nullptr, ServerReader::readFromServer, args);
    // pthread_create(&serverThread, nullptr,server)
}

