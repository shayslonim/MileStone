//
// Created by shay on 12/23/18.
//

#include "ServerReader.h"
#include <string>

using namespace std;

void* ServerReader::readFromServer(void*) {
    int sockfd, newsockfd, portno, clilen;
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
    portno = 5001;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

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

    /* Accept actual connection from the client */
    newsockfd = accept(sockfd, (struct sockaddr*) &cli_addr, (socklen_t*) &clilen);

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    /* If connection is established then start communicating */
    bzero(buffer, 256);
    n = read(newsockfd, buffer, 255);

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    while (/*no one told me to close the socket*/) {
        string a;
        while (a.find('\n') != string::npos) {

        }
        bzero(buffer, 256);
        n = read(newsockfd, buffer, 255);
        a += buffer;

        //If the new-line char is in the string
        if (a.find('\n') != string::npos) {
            //double b[23]
            double* arguments = updateArgumentsList();

            a = a.substr(a.find('\n'));


        }

    }
    // close socket
    close(newsockfd);


}

double* ServerReader::updateArgumentsList(double* values) {
    Maps maps;//todo: set the map to be the same map as we use
    maps.setValue("instrumentation/airspeed-indicator/indicated-speed-kt", values[0]);
    maps.setValue("/instrumentation/altimeter/indicated-altitude-ft", values[1]);
    maps.setValue("/instrumentation/altimeter/pressure-alt-ft", values[2]);
    maps.setValue("/instrumentation/attitude-indicator/indicated-pitch-deg", values[3]);
    maps.setValue("/instrumentation/attitude-indicator/indicated-roll-deg", values[4]);
    maps.setValue("/instrumentation/attitude-indicator/internal-pitch-deg", values[5]);
    maps.setValue("/instrumentation/attitude-indicator/internal-roll-deg", values[6]);
    maps.setValue("/instrumentation/encoder/indicated-altitude-ft", values[7]);
    maps.setValue("/instrumentation/encoder/pressure-alt-ft", values[8]);
    maps.setValue("/instrumentation/gps/indicated-altitude-ft", values[9]);
    maps.setValue("/instrumentation/gps/indicated-ground-speed-kt", values[10]);
    maps.setValue("/instrumentation/gps/indicated-vertical-speed", values[11]);
    maps.setValue("/instrumentation/heading-indicator/indicated-heading-deg", values[12]);
    maps.setValue("/instrumentation/magnetic-compass/indicated-heading-deg", values[13]);
    maps.setValue("/instrumentation/slip-skid-ball/indicated-slip-skid", values[14]);
    maps.setValue("/instrumentation/turn-indicator/indicated-turn-rate", values[15]);
    maps.setValue("/instrumentation/vertical-speed-indicator/indicated-speed-fpm", values[16]);
    maps.setValue("/controls/flight/aileron", values[17]);
    maps.setValue("/controls/flight/elevator", values[18]);
    maps.setValue("/controls/flight/rudder", values[19]);
    maps.setValue("/controls/flight/flaps", values[20]);
    maps.setValue("/controls/engines/current-engine/throttle", values[21]);
    maps.setValue("/engines/engine/rpm", values[22]);
}
