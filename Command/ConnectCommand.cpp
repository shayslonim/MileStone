//
// Created by shira on 12/20/18.
//

#include "ConnectCommand.h"

ConnectCommand::ConnectCommand(vector<string> line, Maps* maps) {
    this->maps = maps;
    //todo: constructor
}

void ConnectCommand::execute() {
    ServerUpdater* serverUpdater = new ServerUpdater(this->hostName, this->portId);

}
