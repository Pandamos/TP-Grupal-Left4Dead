#include <exception>
#include <arpa/inet.h>
#include "server.h"

#include <iostream>
#include <iomanip>
#include <cstring>
#include <sys/socket.h>

#define SUCCESS 0
#define ERROR -1

/*
 * ./server port 
 * example: ./server 8080 REVISAR ESTOS PARAMETROS
 */
int main(int argc, char *argv[]) { try {
    if (argc != 2) {
        std::cerr << "Bad program call. Expected "
                << argv[0]
                << " <servname/servport>\n";
        return ERROR;
    }
    
    Server server(argv[1]);

    server.run(); 
    return SUCCESS;
} catch (const std::exception& err) {
    std::cerr
        << "Something went wrong and an exception was caught: "
        << err.what()
        << "\n";
    return ERROR;
} catch (...) {
    std::cerr << "Something went wrong and an unknown exception was caught.\n";
    return ERROR;
} }