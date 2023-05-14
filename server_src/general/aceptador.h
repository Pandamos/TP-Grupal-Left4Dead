#ifndef ACEPTADOR_H
#define ACEPTADOR_H

#include "../../common_src/socket/common_socket_dipa.h"

class aceptador /*: public Thread */{
    private:
    Socket socket;

    public:
    explicit aceptador(Socket&& socket);

    // hace el socket.accept y crea un nuevo hilo para el client
    // este client solamente se encarga de verificar la primera parte del protocolo?
    // o lo reutilizamos para el sender o receiver?
    // si la reutilizamos, conviene para el receiver (para eliminar RC)

    //virtual void run() override;
    
    //agrega un nuevo cliente cuando socket.accept devuelve
    void add_client(Socket&& peer);

    //verifica si algun cliente esta muerto y si es asi, lo mata
    void clean_old_clients();

    //elimina un cliente especifico
    void delete_client(/*client *client*/);
};

#endif