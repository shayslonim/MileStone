//
// Created by shay on 12/29/18.
//

#include "ServerReader.h"
//
// Created by shay on 12/23/18.
//

#include "ServerReader.h"
#include "ServerReaderArguments.h"
#include "SocketBooleans.h"
#include "Maps.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

void* ServerReader::readFromServer(void* arguments) {
    ServerReaderArguments* args = (ServerReaderArguments*) arguments;

    Maps* maps = args->getMaps();
    int portId = args->getPortId();
    int timesPerSecond = args->getTimesPerSecond(); //todo: check if it is ever used - nevermind :)

    int sockfd, newsockfd, clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Initialize socket structure */
    bzero((char*) &serv_addr, sizeof(serv_addr));
    // portId = 5001;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portId);

    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    */

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);
    cout << "Trying to connect to server.." << std::endl;
    /* Accept actual connection from the client */
    newsockfd = accept(sockfd, (struct sockaddr*) &cli_addr, (socklen_t*) &clilen);

    //This is printed if openDataServer connects to the flightgear! :D
    std::cout << "There is a connection!" << std::endl;

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    /* If connection is established then start communicating */
    cout << "reading..." << std::endl;
    while (!SocketBooleans::isStopServerReader()) {
        string varsAndVals;

        bzero(buffer, 256);
        n = read(newsockfd, buffer, 255);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        varsAndVals += buffer;

        if (varsAndVals.find('\n') != string::npos) {
////////////cout << "current value is:" << varsAndVals << std::endl;
            double* values = createArgumentsList(varsAndVals);
            updateArgumentsListInMaps(values, maps);
            //remove the used variables in the string and keep the variables after the \n
            varsAndVals = varsAndVals.substr(varsAndVals.find('\n'));

            //sleep for timesPerSecondTime
            usleep(1.0 / timesPerSecond); //Maybe delete this
        }
        // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    }
    //close socket
    close(newsockfd);

    //The function is void* so it needs to return some value
    return nullptr;
}


void ServerReader::updateArgumentsListInMaps(double* values, Maps* maps) {
    maps->setValue("/instrumentation/airspeed-indicator/indicated-speed-kt", values[0]);
    maps->setValue("/instrumentation/altimeter/indicated-altitude-ft", values[1]);
    maps->setValue("/instrumentation/altimeter/pressure-alt-ft", values[2]);
    maps->setValue("/instrumentation/attitude-indicator/indicated-pitch-deg", values[3]);
    maps->setValue("/instrumentation/attitude-indicator/indicated-roll-deg", values[4]);
    maps->setValue("/instrumentation/attitude-indicator/internal-pitch-deg", values[5]);
    maps->setValue("/instrumentation/attitude-indicator/internal-roll-deg", values[6]);
    maps->setValue("/instrumentation/encoder/indicated-altitude-ft", values[7]);
    maps->setValue("/instrumentation/encoder/pressure-alt-ft", values[8]);
    maps->setValue("/instrumentation/gps/indicated-altitude-ft", values[9]);
    maps->setValue("/instrumentation/gps/indicated-ground-speed-kt", values[10]);
    maps->setValue("/instrumentation/gps/indicated-vertical-speed", values[11]);
    maps->setValue("/instrumentation/heading-indicator/indicated-heading-deg", values[12]);
    maps->setValue("/instrumentation/magnetic-compass/indicated-heading-deg", values[13]);
    maps->setValue("/instrumentation/slip-skid-ball/indicated-slip-skid", values[14]);
    maps->setValue("/instrumentation/turn-indicator/indicated-turn-rate", values[15]);
    maps->setValue("/instrumentation/vertical-speed-indicator/indicated-speed-fpm", values[16]);
    maps->setValue("/controls/flight/aileron", values[17]);
    maps->setValue("/controls/flight/elevator", values[18]);
    maps->setValue("/controls/flight/rudder", values[19]);
    maps->setValue("/controls/flight/flaps", values[20]);
    maps->setValue("/controls/engines/current-engine/throttle", values[21]);
    maps->setValue("/engines/engine/rpm", values[22]);

    if (!SocketBooleans::isReadingStarted()) {
        SocketBooleans::setReadingStarted(true);
    }
}

double* ServerReader::createArgumentsList(string valuesString) {
    array<double, 23>* valuesArr = new array<double, 23>();
    vector<string> result;
    stringstream ss = stringstream(valuesString);
    while (ss.good()) {
        string substr;
        getline(ss, substr, ',');
        result.push_back(substr);
    }
//    cout << flush;
//    for (vector<string>::iterator it = result.begin(); it != result.end(); ++it) {
//        cout << *it << " ";
//    }
//    cout << std::endl;


    if (result.size() != 23) {
        // perror("not enough arguments were passed to createArgumentsList function");
        cerr << "not enough arguments were passed to createArgumentsList function" << std::endl;
    } else {
        int i = 0;
        for (vector<string>::iterator it = result.begin(); it < result.end(); it++) {
            valuesArr->at(i) = stod(*it); //convert it to double
            i++;
        }

    }
    return (double*) valuesArr;

}
