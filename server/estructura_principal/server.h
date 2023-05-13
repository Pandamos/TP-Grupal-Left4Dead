#ifndef SERVER_H
#define SERVER_H

#include <string>
#include <iostream>
#include <arpa/inet.h>
#include <utility>

#include "common_socket_dipa.h"

class Server {
    private: 
    Socket socket;

    public:
    explicit Server(char *servname);

    void run();
};

#endif