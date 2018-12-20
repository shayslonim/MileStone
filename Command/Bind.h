//
// Created by shira on 12/20/18.
//

#ifndef MILESTONE_BIND_H
#define MILESTONE_BIND_H
#include "Command.h"
#define FIRST 1
#define SECOND 4

class Bind : public Command
{
public:
    void execute(vector<string>::iterator);
    //vector<string> cut(vector<string>::iterator iter);
};

#endif //MILESTONE_BIND_H
