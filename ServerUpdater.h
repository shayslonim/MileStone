//
// Created by shira on 12/30/18.
//

#ifndef MILESTONE_SERVERUPDATER_H
#define MILESTONE_SERVERUPDATER_H
#include <string>
using namespace std;

class ServerUpdater {
private:
    string hostName;
    int portId;

    int socketId;
public:

    ServerUpdater(const string &hostName, int portId);
    void connectToServer();
    void update(string path, double val);
    void disconnect();
};






#endif //MILESTONE_SERVERUPDATER_H
