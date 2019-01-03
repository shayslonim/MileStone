//
// Created by shira on 12/30/18.
//

#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string.h>

#include <iostream>

#include "ServerUpdater.h"

ServerUpdater::ServerUpdater(const string &hostName, int portId) : hostName(hostName), portId(portId) {}

void ServerUpdater::connectToServer() {
    std::cout << "hostName: " << hostName << " ,portId: " << portId << std::endl;
    //int socketId, portno;
    struct sockaddr_in serv_addr;
    struct hostent* server;

//    if (argc < 3) {
//        fprintf(stderr,"usage %s hostname port\n", argv[0]);
//        exit(0);
//    }0



    /* Create a socket point */
    this->socketId = socket(AF_INET, SOCK_STREAM, 0);

    if (this->socketId < 0) {
        std::cerr << "ERROR opening socket";
        exit(1);
    }

    server = gethostbyname(this->hostName.c_str());

    if (server == NULL) {
        std::cerr << "ERROR, no such host\n";
        exit(0);
    }

    bzero((char*) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char*) server->h_addr, (char*) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(this->portId);

    /* Now connect to the server */
    if (connect(this->socketId, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        std::cerr << "ERROR connecting";
        exit(1);
    }
//-------------------------------------------------------------------------------------

    std::cout << "SERVER UPDATER SAYS: WE'RE DONE IN THE ConnectToServer CONSTRUCTOR" << std::endl;
}

void ServerUpdater::update(string path, double val) {
    std::cout << "SERVER UPDATER SAYS: WE'RE TRYING TO UPDATE IN THE ConnectToServer UPDATE" << std::endl;
    /* Now ask for a message from the user, this message
      * will be read by server
     */
    char buffer[256];
    int n;
    bzero(buffer, 256);
    string commandString = string("set") + " " + path +" " + to_string(val) + "\r\n"; //set
    std::cout << "setting: " << commandString << std::endl;
    std::copy(commandString.begin(), commandString.end(), buffer); //instead of fgets in Michael's code.
    /* Send message to the server */
    std::cout <<"buffer is " << buffer << endl;
    n = write(this->socketId, buffer, strlen(buffer));
    if (n < 0) {
        std::cerr << "ERROR writing to socket";
        exit(1);
    }

    /* Now read server response */
    bzero(buffer, 256);
    n = read(this->socketId, buffer, 255);

    if (n < 0) {
        std::cerr << "ERROR reading from socket";
        exit(1);
    }
//---------------------------------------------------------------
    std::cout << "SERVER UPDATER SAYS: WE'RE DONE IN THE ConnectToServer UPDATE" << std::endl;
}

void ServerUpdater::disconnect() {
    close(this->socketId);
}
