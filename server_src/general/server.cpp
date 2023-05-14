#include <string>
#include <utility>
#include <iostream>
#include <arpa/inet.h>
#include "server.h"

#define EXIT "q"

Server::Server(char *servname) :
    socket(servname) {
    //nothign to do
}

void Server::run() { 
    try {
        //Aceptador aceptador(std::move(socket));
        //aceptador.start();
        std::string command;
        std::cin >> command;
        while (command != EXIT)
            std::cin >> command;
        //que hacemos cuando el command es EXIT?
    } catch (std::system_error& ex) {
        std::cerr << "Error en " << __FILE__ << ":" << __LINE__ << ": " << ex.what() << std::endl;
    }
}
