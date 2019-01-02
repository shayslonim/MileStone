//
// Created by shira on 12/20/18.
//

#include "ConnectCommand.h"

ConnectCommand::ConnectCommand(vector<string> line, Maps* maps) {
    this->maps = maps;
    ExpressionFactory factory = ExpressionFactory(maps);
    int index = 0;
    if (find(line.begin(), line.end(), ",") != line.end()) {
        while (line[index] != ",") {
            index++;
        }
        index++;
    }
    else {
        index = 2;
    }
    this->hostName = line[1];
    this->portId = factory.getExpressionFromUnorderedLine(line, index, line.size())->calculate();
}

void ConnectCommand::execute() {
    ServerUpdater* serverUpdater = new ServerUpdater(this->hostName, this->portId);
    this->updater = serverUpdater;
}
