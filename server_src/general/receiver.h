#ifndef RECEIVER_H_
#define RECEIVER_H_

class receiver /*: public Thread*/ {
    private:
    //protocolo& request;
    //Queue<action>* queue_partida;

    public:
    receiver();

    /*
        Esta funcion 
            1. lee del socket
            2. crea la accion correspondiente
            3. la mete en la queue con un push
    */
    //virtual void run() override;
};
#endif //RECEIVER_H_
