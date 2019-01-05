//
// Created by shira on 12/20/18.
//

#include "ConnectCommand.h"

/**
 * constructor
 * @param line vector<string> pointer
 * @param maps Maps*
 */
ConnectCommand::ConnectCommand(vector<string> &line, Maps* maps) {
    this->maps = maps;
    ExpressionFactory factory = ExpressionFactory(maps);
    this->hostName = line[1];
    this->portId = factory.getExpressionFromUnorderedLine(line, 2, line.size() - 1)->calculate();
}

/**
 * Connect to the server
 */
void ConnectCommand::execute() {
    ServerUpdater* serverUpdater = new ServerUpdater(this->hostName, this->portId);
    serverUpdater->connectToServer();
    this->maps->setServerUpdater(serverUpdater);
}
