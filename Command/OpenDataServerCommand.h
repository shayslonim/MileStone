//
// Created by shira on 12/20/18.
//

#ifndef MILESTONE_OPENDATASERVER_H
#define MILESTONE_OPENDATASERVER_H
#include "Command.h"
#include "../Maps.h"

class OpenDataServerCommand : public Command
{
public:
    //OpenDataServerCommand();
    void execute(/*vector<string>::iterator*/) override;

private:
    int portId;
    int timesPerSecond;
    Maps* maps;
public:
    OpenDataServerCommand(int portId, int timesPerSecond, Maps* maps);

};

#endif //MILESTONE_OPENDATASERVER_H
