//
// Created by shay on 12/17/18.
//

#ifndef MILESTONE_COMMAND_H
#define MILESTONE_COMMAND_H

#include <string>
#include <vector>

using namespace std;
/**
 * Something that can be executed
 */
class Command {
public:
    /**
     * Do the command
     */
    virtual void execute(/*vector<string>::iterator iter*/)  = 0;
    /**
     * Destructor
     */
    virtual ~Command() = default;
};

#endif //MILESTONE_COMMAND_H
