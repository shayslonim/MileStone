//
// Created by shay on 12/23/18.
//

#include "ServerReaderArguments.h"

int ServerReaderArguments::getPortId() const {
    return portId;
}

int ServerReaderArguments::getTimesPerSecond() const {
    return timesPerSecond;
}

Maps* ServerReaderArguments::getMaps() const {
    return maps;
}
