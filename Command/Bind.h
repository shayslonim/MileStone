//
// Created by shira on 12/20/18.
//

#ifndef MILESTONE_BIND_H
#define MILESTONE_BIND_H
#include "Command.h"
#include "../Maps.h"
#define FIRST 1
#define SECOND 4

class Bind : public Command
{
    Maps* maps;
public:
    Bind(Maps* maps) {
        this->maps = maps;
    }
    void execute(vector<string>::iterator);
    //vector<string> cut(vector<string>::iterator iter);
};

#endif //MILESTONE_BIND_H
