//
// Created by shira on 12/20/18.
//

#ifndef MILESTONE_OPENDATASERVER_H
#define MILESTONE_OPENDATASERVER_H
#include "Command.h"

class OpenDataServerCommand : public Command
{
public:
    void execute(vector<string>::iterator);
};

#endif //MILESTONE_OPENDATASERVER_H
