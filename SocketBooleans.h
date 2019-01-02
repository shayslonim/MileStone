//
// Created by shay on 12/27/18.
//

#ifndef MILESTONE_SOCKETBOOLEANS_H
#define MILESTONE_SOCKETBOOLEANS_H


class SocketBooleans {
private:
    static bool stopServerReader;
    static bool readingStarted;

public:
    static bool isStopServerReader();
    static void setStopServerReader(bool isStop);

    static bool isReadingStarted();
    static void setReadingStarted(bool isStarted);
};


#endif //MILESTONE_SOCKETBOOLEANS_H
