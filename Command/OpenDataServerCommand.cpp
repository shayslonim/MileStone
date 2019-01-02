//
// Created by shira on 12/20/18.
//

#include <pthread.h>
#include "OpenDataServerCommand.h"
#include "../ServerReader.h"
#include "../ServerReaderArguments.h"


void OpenDataServerCommand::execute() {
    pthread_t serverThread;

    ServerReaderArguments* args = new ServerReaderArguments(this->portId, this->timesPerSecond, this->maps);

    pthread_create(&serverThread, nullptr, ServerReader::readFromServer, args);
    // pthread_create(&serverThread, nullptr,server)
}
//חןןןןןןןןןןן                                                                                     maps(maps) {}

OpenDataServerCommand::OpenDataServerCommand(vector<string> line, Maps* maps) {
    this->maps = maps;
    InfixHandler infixHandler = InfixHandler();
    ExpressionFactory factory = ExpressionFactory(maps);
    int index = 0;
    int indexSecond;
    if (find(line.begin(), line.end(), ",") != line.end()) {
        while (line[index] != ",") {
            index++;
        }
        index--;
        indexSecond = index + 2;
    }
    else {
        if (!(infixHandler.isANumber(line[index]) && infixHandler.isANumber(line[index + 1]))) {
            index++;
        }
        indexSecond = index + 1;
    }
    this->portId = factory.getExpressionFromUnorderedLine(line, 1, index)->calculate();
    this->timesPerSecond = factory.getExpressionFromUnorderedLine(line, indexSecond, line.size() - 1)->calculate();
}
