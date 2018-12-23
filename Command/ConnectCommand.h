//
// Created by shira on 12/20/18.
//

#ifndef MILESTONE_CONNECT_H
#define MILESTONE_CONNECT_H
#include "Command.h"

class ConnectCommand : public Command
{
public:
    void execute(vector<string>::iterator);
};

#endif //MILESTONE_CONNECT_H
