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
public:

    ServerUpdater(const string &hostName, int portId);
    void connect();
    void update(string path, double val);
    void disconnect();
};

ServerUpdater::ServerUpdater(const string &hostName, int portId) : hostName(hostName), portId(portId) {}

void ServerUpdater::connect() {

}

#endif //MILESTONE_SERVERUPDATER_H
