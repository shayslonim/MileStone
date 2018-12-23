//
// Created by shay on 12/23/18.
//

#ifndef MILESTONE_SERVERREADERINFORMATION_H
#define MILESTONE_SERVERREADERINFORMATION_H


#include "Maps.h"

struct ServerReaderArguments {
    int portId;
    int timesPerSecond;
    Maps* maps;

public:
    ServerReaderArguments(int portId, int timesPerSecond, Maps* maps);

    int getPortId() const;

    int getTimesPerSecond() const;

    Maps* getMaps() const;

};


#endif //MILESTONE_SERVERREADERINFORMATION_H
