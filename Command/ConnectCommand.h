//
// Created by shira on 12/20/18.
//

#ifndef MILESTONE_CONNECT_H
#define MILESTONE_CONNECT_H
#include <regex>
#include "Command.h"
#include "../Maps.h"
#include "../InfixHandler.h"
#include "../ExpressionFactory.h"

class ConnectCommand : public Command
{
    string hostName;
    int portId;
    Maps* maps;
public:
    ConnectCommand(vector<string> &line, Maps* maps);
    void execute(/*vector<string>::iterator*/) override;
};

#endif //MILESTONE_CONNECT_H
