#if defined MAIN_BUILD
#include <exception>
#include <arpa/inet.h>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <sys/socket.h>

#include "general/server.h"

#define SUCCESS 0
#define ERROR -1

/*
 * ./server port 
 * example: ./server 8080 REVISAR ESTOS PARAMETROS
 */
int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Bad program call. Expected "
                << argv[0]
                << " <servname/servport>\n";
        return ERROR;
    }
        
    try {
        Server server(argv[1]);
        server.run();
    } catch (const std::exception& err) {
        std::cerr
            << "Something went wrong and an exception was caught: "
            << err.what()
            << "\n";
        return ERROR;
    } catch (...) {
        std::cerr << "Something went wrong and an unknown exception was caught.\n";
        return ERROR;
    } 
    return SUCCESS;
}
#endif
