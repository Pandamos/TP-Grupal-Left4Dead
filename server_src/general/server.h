#ifndef SERVER_H
#define SERVER_H

#include "../../common_src/socket/common_socket_dipa.h"

class Server {
    private: 
    Socket socket;

    public:
    explicit Server(char *servname);

    void run();
};

#endif