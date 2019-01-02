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
#include "ServerUpdater.h"

ServerUpdater::ServerUpdater(const string &hostName, int portId) : hostName(hostName), portId(portId) {}

void ServerUpdater::connectToServer() {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent* server;

//    if (argc < 3) {
//        fprintf(stderr,"usage %s hostname port\n", argv[0]);
//        exit(0);
//    }0

    portno = this->portId;

    /* Create a socket point */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(this->hostName.c_str());

    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    bzero((char*) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char*) server->h_addr, (char*) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    /* Now connectToServer to the server */
    if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }
//-------------------------------------------------------------------------------------


}

void ServerUpdater::update(string path, double val) {
    /* Now ask for a message from the user, this message
      * will be read by server
     */
    char buffer[256];
    int n;

    printf("Please enter the message: ");
    bzero(buffer, 256);

    std::copy(path.begin(), path.end(), buffer); //instead of fgets in Michael's code.

    /* Send message to the server */
    n = write(this->socketId, buffer, strlen(buffer));

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    /* Now read server response */
    bzero(buffer, 256);
    n = read(this->socketId, buffer, 255);

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
//---------------------------------------------------------------

}

void ServerUpdater::disconnect() {
    close(this->socketId);
}
