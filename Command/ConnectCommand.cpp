//
// Created by shira on 12/20/18.
//

#include "ConnectCommand.h"

ConnectCommand::ConnectCommand(vector<string> &line, Maps* maps) {
    this->maps = maps;
    ExpressionFactory factory = ExpressionFactory(maps);
    this->hostName = line[1];
    this->portId = factory.getExpressionFromUnorderedLine(line, 2, line.size() - 1)->calculate();
}

void ConnectCommand::execute() {
    ServerUpdater* serverUpdater = new ServerUpdater(this->hostName, this->portId);
    this->maps->setServerUpdater(serverUpdater);
}
