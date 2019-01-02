//
// Created by shira on 12/20/18.
//

#include "ConnectCommand.h"

ConnectCommand::ConnectCommand(vector<string> line, Maps* maps) {
    this->maps = maps;
    InfixHandler infixHandler = InfixHandler();
    ExpressionFactory factory = ExpressionFactory(maps);
    int index = 0;
    int indexSecond;
    vector<string> first;
    vector<string> second;
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
    this->timesPerSecond = factory.getExpressionFromUnorderedLine(line, indexSecond, line.size())->calculate();
}

void ConnectCommand::execute() {
    ServerUpdater* serverUpdater = new ServerUpdater(this->hostName, this->portId);
    this->updater = serverUpdater;
}
