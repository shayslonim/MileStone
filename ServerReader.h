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
#include "Maps.h"
class ServerReader {
public:
    static void* readFromServer(void*);

private:
    static void updateArgumentsListInMaps(double* values, Maps* maps);

    static double* createArgumentsList(string valuesString);
};


#endif //MILESTONE_SERVERLISTENER_H
