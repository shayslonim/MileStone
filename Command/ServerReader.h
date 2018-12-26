//
// Created by shay on 12/23/18.
//

#ifndef MILESTONE_SERVERLISTENER_H
#define MILESTONE_SERVERLISTENER_H


#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>

#include <string>
#include <map>

class ServerReader {
public:
    static void* readFromServer(void*);

private:
    static std::map<std::string, double> createArgumentsList();
};


#endif //MILESTONE_SERVERLISTENER_H